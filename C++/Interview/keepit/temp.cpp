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

const size_t CHUNK_SIZE = 1024 * 1024;
const int MAX_THREADS = 4;

struct ThreadData {
    int threadId;
    int fileId;
    off_t startOffset;
    off_t endOffset;
    unordered_set<string> *localWords;
};

void extractWords(const char *buffer, size_t size, unordered_set<string> &words) {
    string currentWord;

    for(size_t i = 0; i < size; i++) {
        char c = buffer[i];
        if(c >= 'a' && c <= 'z') {
            currentWord += c;
        } else {
            if(!currentWord.empty()) {
                words.insert(currentWord);
                currentWord.clear();
            }
        }
    }

    // need to add the last word if buffer doesnt end with space
    if(!currentWord.empty()) {
        words.insert(currentWord);
    }
}

// thread fucntion to process the file
void* processFileChunk(void *arg) {
    ThreadData *data = static_cast<ThreadData*>(arg);

    // calculate the size of this thread's portion
    off_t chunkSize = data->endOffset - data->startOffset;
    if(chunkSize <= 0) {
        return nullptr;
    }

    // allocate buffer for reading 
    vector<char> buffer(CHUNK_SIZE);
    string overFlow;    //  to handle words split across chunks
    off_t currentOffset = data->startOffset;

    while(currentOffset < data->endOffset) {
        // calculate how much to read
        size_t toRead = (size_t)min<off_t>((off_t)(CHUNK_SIZE), data->endOffset - currentOffset);

        // read chunk
        ssize_t bytesRead = pread(data->fileId, buffer.data(), toRead, currentOffset);
        if(bytesRead <= 0) {
            break;
        }

        // find the last space to avoid splitting words
        size_t actualSize = (size_t)bytesRead;
        if(currentOffset + bytesRead < data->endOffset) {
            // Not the last chunk for this thread: try to avoid splitting a word by trimming
            // back to the last space inside the buffer if possible.
            size_t pos = actualSize;
            while (pos > 0 && buffer[pos - 1] != ' ') --pos;
            if(pos > 0) {
                actualSize = pos;
            }
        }

        // combine with overflow from previous chunk
        string chunkData;
        chunkData.reserve(overFlow.size() + actualSize);
        chunkData += overFlow;
        chunkData.append(buffer.data(), actualSize);

        // extract words from this chunk
        extractWords(chunkData.c_str(), chunkData.size(), *data->localWords);

        // handle overflow for next iteration
        if(actualSize < (size_t)bytesRead) {
            overFlow.assign(buffer.data() + actualSize, (size_t)bytesRead - actualSize);
        } else {
            overFlow.clear();
        }

        currentOffset += actualSize;
    }

    // process any remaining overflow
    if(!overFlow.empty()) {
        extractWords(overFlow.c_str(), overFlow.size(), *data->localWords);
    }

    return nullptr;
}

int main(int argc, char *argv[]) {
    // error handling for the input in commandline arguments
    if(argc != 2) {
        cerr << "Error : Use in this format : "<<argv[0]<<" <fileName>"<<endl;
        return 1;
    }

    // open file
    const char *fileName = argv[1];
    int fileFd = open(fileName, O_RDONLY);
    // error handling for file open 
    if(fileFd == -1) {
        cerr<<"Error: Cannot open file "<<fileName<<endl;
        return 1;
    }

    // get the size of the file
    struct stat fileStat;
    if(fstat(fileFd, &fileStat) == -1) {
        cerr <<"Error : Cannot get file size"<<endl;
        close(fileFd);
        return 1;
    }

    off_t fileSize = fileStat.st_size;
    if(fileSize == 0) {
        cerr <<"Error : File is empty"<<endl;
        close(fileFd);
        return 0;
    }

    // create a thread and add their data
    int hw = (int)sysconf(_SC_NPROCESSORS_ONLN);
    int numThreads = (hw > 0) ? min(hw, MAX_THREADS) : MAX_THREADS;
    if ((off_t)numThreads > fileSize) numThreads = 1; // tiny file -> single thread

    vector<pthread_t> threads(numThreads);
    vector<ThreadData> threadData(numThreads);
    vector<unordered_set<string>> localWordSets(numThreads);

    // calculate chunk size per thread
    off_t chunkPerThread = fileSize / numThreads;

    // create the threads and start it
    for(int i = 0; i < numThreads; i++) {
        threadData[i].threadId = i;
        threadData[i].fileId = fileFd;
        threadData[i].startOffset = i * chunkPerThread;
        threadData[i].endOffset = (i == numThreads - 1) ? fileSize : (i + 1) * chunkPerThread;
        threadData[i].localWords = &localWordSets[i];

        if(pthread_create(&threads[i], nullptr, processFileChunk, &threadData[i]) != 0) {
            cerr<<"Error : cannot create a thread "<<i<<endl;
            close(fileFd);
            return 1;
        }
    }

    // wait for thread completion
    for(int i = 0; i < numThreads; i++) {
        pthread_join(threads[i],nullptr);
    }

    // Merge local sets into a global set
    unordered_set<string> globalWords;
    for (int i = 0; i < numThreads; ++i) {
        for (const auto &w : localWordSets[i]) globalWords.insert(w);
    }

    cout << globalWords.size() << "\n";

    close(fileFd);
    return 0;
}