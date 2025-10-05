#include <iostream>
//#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <algorithm>
#include<cctype>
//#include <cstring>


using namespace std;

const size_t CHUNK_SIZE = 1024 * 1024; // 1 MiB
const int MAX_THREADS = 4;             // fallback thread count

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct ThreadData {
    int threadId;
    int fileFd;
    off_t startOffset;
    off_t endOffset;
    unordered_set<string> *localWords;
    pthread_mutex_t *mutex;
};

void extractWords(const char *buffer, size_t size, unordered_set<string> &words) {
    string currentWord;
    currentWord.reserve(64);
    for (size_t i = 0; i < size; ++i) {
        unsigned char c = buffer[i];
        if (isalpha(c)) {
            currentWord += static_cast<char>(tolower(c));
        } else {
            if (!currentWord.empty()) {
                words.insert(currentWord);
                cout<<"CurrentWord : "<<currentWord<<endl;
                currentWord.clear();
                
            }
        } 
    }
    if (!currentWord.empty()) {
        words.insert(currentWord);
        cout<<"CurrentWord : "<<endl;
    }
}

void* processFileChunk(void *arg) {
    ThreadData *data = static_cast<ThreadData*>(arg);
    off_t chunkSize = data->endOffset - data->startOffset;
    if (chunkSize <= 0) return nullptr;

    vector<char> buffer(CHUNK_SIZE);
    string overflow;
    off_t currentOffset = data->startOffset;

    while (currentOffset < data->endOffset) {
        size_t toRead = (size_t)min<off_t>((off_t)CHUNK_SIZE, data->endOffset - currentOffset);
        ssize_t bytesRead = pread(data->fileFd, buffer.data(), toRead, currentOffset);
        if (bytesRead <= 0) break;

        size_t actualSize = (size_t)bytesRead;
        if (currentOffset + bytesRead < data->endOffset) {
            while (actualSize > 0 && buffer[actualSize - 1] != ' ') --actualSize;
            if (actualSize == 0) actualSize = bytesRead;
        }

        string chunkData = overflow + string(buffer.data(), actualSize);
        extractWords(chunkData.c_str(), chunkData.size(), *data->localWords);

        if (actualSize < (size_t)bytesRead)
            overflow.assign(buffer.data() + actualSize, (size_t)bytesRead - actualSize);
        else
            overflow.clear();

        currentOffset += actualSize;
    }

    if (!overflow.empty()) {
        extractWords(overflow.c_str(), overflow.size(), *data->localWords);
    }

    return nullptr;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    const char *fileName = argv[1];
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
        threadData[i].threadId = i;
        threadData[i].fileFd = fileFd;
        threadData[i].startOffset = i * chunkPerThread;
        threadData[i].endOffset = (i == numThreads - 1) ? fileSize : (i + 1) * chunkPerThread;
        threadData[i].localWords = &localSets[i];
        threadData[i].mutex = &mutex;

        if (pthread_create(&threads[i], nullptr, processFileChunk, &threadData[i]) != 0) {
            cerr << "Error: cannot create thread " << i << "\n";
            close(fileFd);
            return 1;
        }
    }

    for (int i = 0; i < numThreads; ++i) {
        pthread_join(threads[i], nullptr);
    }

    // Merge local sets into a global set
    unordered_set<string> globalWords;
    for (int i = 0; i < numThreads; ++i) {
        for (const auto &w : localSets[i]){
            globalWords.insert(w);
        }
    }
    for(auto val: globalWords) {
        cout<<val<<" ";
    }
    cout<<endl;

    cout << globalWords.size() << "\n";

    close(fileFd);
    pthread_mutex_destroy(&mutex);
    return 0;
}
