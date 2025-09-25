// count_unique_words.cpp
// Count distinct unique words in a file (words are sequences of 'a'..'z').
// Usage: ./count_unique_words <filename>
//
// Approach:
// 1) Single-pass streaming reader: parse words and hash each word to a bucket index.
//    Each bucket is buffered in-memory (small) and periodically flushed to a temporary file
//    (append). This partitions the large input into many smaller files so no single
//    structure must hold all words at once.
// 2) Parallel bucket processing: each bucket file is read, words inserted into an
//    unordered_set<string> to deduplicate within bucket. The bucket unique counts are summed.
//
// Only C++ standard library + POSIX syscalls are used.

#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <atomic>
#include <thread>

using u64 = uint64_t;
using u8 = uint8_t;

static inline u64 fnv1a_hash_word(const char *s, size_t n) {
    // 64-bit FNV-1a
    u64 h = 14695981039346656037ULL;
    for (size_t i = 0; i < n; ++i) {
        h ^= (unsigned char)s[i];
        h *= 1099511628211ULL;
    }
    return h;
}

static void safe_write_all(int fd, const char* data, size_t len) {
    size_t off = 0;
    while (off < len) {
        ssize_t w = write(fd, data + off, len - off);
        if (w < 0) {
            if (errno == EINTR) continue;
            perror("write");
            _exit(1);
        }
        off += (size_t)w;
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 2;
    }
    const char* input_path = argv[1];

    // Stat input file to get size (if available)
    struct stat st;
    off_t input_size = 0;
    if (stat(input_path, &st) == 0) {
        if (S_ISREG(st.st_mode)) input_size = st.st_size;
    }

    // Choose number of buckets based on file size to keep per-bucket files small.
    // Constraints: not too many files; choose between 256 and 65536.
    size_t buckets = 4096; // default
    if (input_size > 0) {
        // aim for ~1MB per bucket file on average (approx), but clamp
        off_t target_per_bucket = (1ULL << 20); // 1 MiB
        size_t derived = (size_t)((input_size + target_per_bucket - 1) / target_per_bucket);
        if (derived < 256) derived = 256;
        if (derived > 65536) derived = 65536;
        buckets = derived;
    }
    // round buckets to nearest power-of-two might help, but not required.
    if (buckets < 256) buckets = 256;
    if (buckets > 65536) buckets = 65536;

    const size_t FLUSH_THRESHOLD = 64 * 1024; // 64 KiB buffer per bucket before flush

    // Create temporary directory for bucket files
    pid_t pid = getpid();
    std::ostringstream ss;
    auto now = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    ss << "/tmp/unique_words_" << pid << "_" << (now & 0xffffffff);
    std::string tmpdir = ss.str();

    if (mkdir(tmpdir.c_str(), 0700) != 0) {
        perror("mkdir");
        return 1;
    }

    // Per-bucket memory buffers
    std::vector<std::string> bucket_bufs(buckets);
    bucket_bufs.shrink_to_fit();

    // Function to flush a bucket buffer to its file (append)
    auto flush_bucket = [&](size_t idx) {
        if (bucket_bufs[idx].empty()) return;
        std::string fname = tmpdir + "/bucket_" + std::to_string(idx) + ".dat";
        int fd = open(fname.c_str(), O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd < 0) {
            perror(("open: " + fname).c_str());
            _exit(1);
        }
        safe_write_all(fd, bucket_bufs[idx].data(), bucket_bufs[idx].size());
        close(fd);
        bucket_bufs[idx].clear();
    };

    // Phase 1: streaming parse and partitioning
    int infd = open(input_path, O_RDONLY);
    if (infd < 0) {
        perror("open input");
        return 1;
    }

    const size_t READ_BUF = 1 << 20; // 1 MiB read buffer
    std::vector<char> rbuf(READ_BUF);
    std::string current_word;
    current_word.reserve(64);
    u64 current_hash = 14695981039346656037ULL; // if using FNV-1a incremental
    bool have_partial = false;

    ssize_t r;
    while ((r = read(infd, rbuf.data(), READ_BUF)) > 0) {
        size_t i = 0;
        while (i < (size_t)r) {
            char c = rbuf[i++];
            if (c == ' ') {
                if (!current_word.empty()) {
                    // compute hash if we haven't been doing it incrementally (we will use fnv for safety)
                    u64 h = fnv1a_hash_word(current_word.data(), current_word.size());
                    size_t bucket_idx = (size_t)(h % buckets);
                    // append word + '\n' to bucket buffer
                    bucket_bufs[bucket_idx].append(current_word);
                    bucket_bufs[bucket_idx].push_back('\n');
                    if (bucket_bufs[bucket_idx].size() >= FLUSH_THRESHOLD) {
                        flush_bucket(bucket_idx);
                    }
                    current_word.clear();
                }
                have_partial = false;
            } else {
                // guaranteed 'a'..'z' per problem statement
                current_word.push_back(c);
                have_partial = true;
            }
        }
        // continue; words spanning buffer boundary are kept in current_word
    }
    if (r < 0) {
        perror("read");
        close(infd);
        return 1;
    }
    // End of file: flush any final word
    if (!current_word.empty()) {
        u64 h = fnv1a_hash_word(current_word.data(), current_word.size());
        size_t bucket_idx = (size_t)(h % buckets);
        bucket_bufs[bucket_idx].append(current_word);
        bucket_bufs[bucket_idx].push_back('\n');
        current_word.clear();
    }
    // Flush all bucket buffers to disk
    for (size_t i = 0; i < buckets; ++i) {
        flush_bucket(i);
    }

    close(infd);

    // Phase 2: parallel processing of buckets to count unique words per bucket
    unsigned int hw = std::thread::hardware_concurrency();
    if (hw == 0) hw = 4;
    size_t num_threads = hw;

    std::atomic<uint64_t> total_unique{0};

    // We'll build a list of existing bucket files to process (some buckets might be empty/no file)
    std::vector<std::string> bucket_files;
    bucket_files.reserve(buckets);
    for (size_t i = 0; i < buckets; ++i) {
        std::string fname = tmpdir + "/bucket_" + std::to_string(i) + ".dat";
        struct stat stf;
        if (stat(fname.c_str(), &stf) == 0 && stf.st_size > 0) {
            bucket_files.push_back(std::move(fname));
        }
    }

    // Worker function for each bucket file
    auto process_bucket_file = [&](const std::string& fname) {
        // Stat to get size and possibly reserve set capacity
        struct stat stf;
        size_t fsize = 0;
        if (stat(fname.c_str(), &stf) == 0) fsize = (size_t)stf.st_size;
        // Read file and insert words into unordered_set
        int fd = open(fname.c_str(), O_RDONLY);
        if (fd < 0) {
            perror(("open bucket for read: " + fname).c_str());
            _exit(1);
        }
        const size_t BUFSZ = 1 << 20; // 1 MiB
        std::vector<char> buf(BUFSZ);
        std::string cur;
        cur.reserve(64);

        // Estimate number of unique words for reserve
        size_t est_words = 1024;
        if (fsize > 0) {
            est_words = fsize / 6;
            if (est_words < 1024) est_words = 1024;
        }

        std::unordered_set<std::string> set;
        set.reserve(est_words);

        ssize_t rr;
        while ((rr = read(fd, buf.data(), BUFSZ)) > 0) {
            size_t i = 0;
            while (i < (size_t)rr) {
                char c = buf[i++];
                if (c == '\n') {
                    if (!cur.empty()) {
                        set.emplace(cur);
                        cur.clear();
                    }
                } else {
                    cur.push_back(c);
                }
            }
        }
        if (rr < 0) {
            perror(("read bucket: " + fname).c_str());
            close(fd);
            _exit(1);
        }
        if (!cur.empty()) {
            set.emplace(cur);
            cur.clear();
        }
        close(fd);
        total_unique.fetch_add(set.size(), std::memory_order_relaxed);
    };

    // Simple thread pool: distribute bucket_files among threads
    std::atomic<size_t> next_idx{0};
    std::vector<std::thread> workers;
    for (size_t t = 0; t < num_threads; ++t) {
        workers.emplace_back([&](){
            while (true) {
                size_t idx = next_idx.fetch_add(1);
                if (idx >= bucket_files.size()) break;
                process_bucket_file(bucket_files[idx]);
            }
        });
    }
    for (auto &th : workers) th.join();

    // Output the result
    std::cout << total_unique.load() << "\n";

    // Cleanup temporary files and directory
    for (const auto &f : bucket_files) {
        unlink(f.c_str());
    }
    // also remove any leftover bucket files (if any existed but were empty they might not be in list)
    // iterate bucket indices and unlink
    for (size_t i = 0; i < buckets; ++i) {
        std::string fname = tmpdir + "/bucket_" + std::to_string(i) + ".dat";
        unlink(fname.c_str()); // ignore errors
    }
    rmdir(tmpdir.c_str()); // ignore error

    return 0;
}
