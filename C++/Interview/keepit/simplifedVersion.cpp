// simple_pthread_count_unique_words.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>
#include <pthread.h>

// Shared global set and mutex
unordered_set<string> global_set;
pthread_mutex_t global_mutex = PTHREAD_MUTEX_INITIALIZER;

struct ThreadArgs {
    string filename;
    streampos start;
    streampos end;
};

void* process_chunk(void* arg) {
    ThreadArgs* args = static_cast<ThreadArgs*>(arg);
    ifstream file(args->filename);
    file.seekg(args->start);

    unordered_set<string> local_set;
    string word;

    // Skip partial word if not at beginning
    if (args->start != 0) {
        char c;
        while (file.get(c)) {
            if (c == ' ') break;
            if (file.tellg() >= args->end) return nullptr;
        }
    }

    while (file >> word) {
        streampos pos = file.tellg();
        local_set.insert(word);
        if (pos >= args->end && pos != -1) break;
    }

    // Merge local results into global set
    pthread_mutex_lock(&global_mutex);
    global_set.insert(local_set.begin(), local_set.end());
    pthread_mutex_unlock(&global_mutex);

    return nullptr;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    ifstream infile(argv[1], ios::ate);
    if (!infile) {
        cerr << "Error: cannot open file " << argv[1] << "\n";
        return 1;
    }

    streampos file_size = infile.tellg();
    unsigned int num_threads = thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 4; // fallback
    streampos chunk_size = file_size / num_threads;

    vector<pthread_t> threads(num_threads);
    vector<ThreadArgs> args(num_threads);

    for (unsigned int i = 0; i < num_threads; ++i) {
        args[i].filename = argv[1];
        args[i].start = i * chunk_size;
        args[i].end = (i == num_threads - 1) ? file_size : (i + 1) * chunk_size;
        pthread_create(&threads[i], nullptr, process_chunk, &args[i]);
    }

    for (unsigned int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], nullptr);
    }

    cout << global_set.size() << "\n";
    return 0;
}
