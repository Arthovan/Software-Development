#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>
#include <algorithm>

using namespace std;

const size_t CHUNK_SIZE = 1024 * 1024; // 1 MiB
const int MAX_THREADS = 4;             // fallback max thread count

struct ThreadData {
    int fileFd;
    off_t startOffset;
    off_t endOffset;
    unordered_set<string>* localWords;
};

// --- Extract words from a buffer (thread-safe version)
void extractWords(const char *buffer, size_t size, unordered_set<string> &words, bool lastChunk = false) {
    static thread_local string currentWord; // keeps partial word across chunk reads
    for (size_t i = 0; i < size; ++i) {
        unsigned char c = buffer[i];
        if (isalpha(c)) {
            currentWord += static_cast<char>(tolower(c));
        } else {
            if (!currentWord.empty()) {
                words.insert(currentWord);
                currentWord.clear();
            }
        }
    }

    // If this is the last chunk for this thread, flush any remaining partial word
    if (lastChunk && !currentWord.empty()) {
        words.insert(currentWord);
        currentWord.clear();
    }
}

// --- Thread worker function
void* processFileChunk(void* arg) {
    ThreadData* data = static_cast<ThreadData*>(arg);
    off_t currentOffset = data->startOffset;
    vector<char> buffer(CHUNK_SIZE);

    while (currentOffset < data->endOffset) {
        size_t toRead = min((off_t)CHUNK_SIZE, data->endOffset - currentOffset);
        ssize_t bytesRead = pread(data->fileFd, buffer.data(), toRead, currentOffset);
        if (bytesRead <= 0) break;

        bool isLastChunk = (currentOffset + bytesRead >= data->endOffset);
        extractWords(buffer.data(), bytesRead, *data->localWords, isLastChunk);
        currentOffset += bytesRead;
    }

    return nullptr;
}

// --- Main function
int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    const char* fileName = argv[1];
    int fileFd = open(fileName, O_RDONLY);
    if (fileFd == -1) {
        perror("open");
        return 1;
    }

    struct stat st;
    if (fstat(fileFd, &st) == -1) {
        perror("fstat");
        close(fileFd);
        return 1;
    }

    off_t fileSize = st.st_size;
    if (fileSize == 0) {
        cout << 0 << "\n";
        close(fileFd);
        return 0;
    }

    int hw = (int)sysconf(_SC_NPROCESSORS_ONLN);
    int numThreads = (hw > 0) ? min(hw, MAX_THREADS) : MAX_THREADS;
    if ((off_t)numThreads > fileSize) numThreads = 1;

    vector<pthread_t> threads(numThreads);
    vector<ThreadData> threadData(numThreads);
    vector<unordered_set<string>> localSets(numThreads);
    off_t chunkPerThread = fileSize / numThreads;

    for (int i = 0; i < numThreads; ++i) {
        threadData[i].fileFd = fileFd;
        threadData[i].startOffset = i * chunkPerThread;
        threadData[i].endOffset = (i == numThreads - 1) ? fileSize : (i + 1) * chunkPerThread;
        threadData[i].localWords = &localSets[i];

        pthread_create(&threads[i], nullptr, processFileChunk, &threadData[i]);
    }

    for (int i = 0; i < numThreads; ++i) {
        pthread_join(threads[i], nullptr);
    }

    // Merge all local sets
    unordered_set<string> globalWords;
    for (int i = 0; i < numThreads; ++i) {
        globalWords.insert(localSets[i].begin(), localSets[i].end());
    }

    // Print results
    for (const auto& w : globalWords) {
        cout << w << " ";
    }
    cout << "\nTotal unique words: " << globalWords.size() << "\n";

    close(fileFd);
    return 0;
}
