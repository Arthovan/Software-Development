#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <algorithm>
#include <pthread.h>
#include <vector>

std::unordered_set<std::string> uniqueWords; // store distinct words
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* routine(void *arg){
    std::string line = *(std::string*)arg;
    delete (std::string*)arg;   // free allocated memeory in heap

    std::stringstream ss(line);
    std::string word;
    std::unordered_set<std::string> localSet;
    while (ss >> word) {
        // convert word to lowercase to make comparison case-insensitive
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        if (!word.empty())
            localSet.insert(word);
    }

    // merge into the global set
    pthread_mutex_lock(&mutex);
    for(auto &globalWord : localSet) {
        uniqueWords.insert(globalWord);
    }
    pthread_mutex_unlock(&mutex);

    return nullptr;
}

int main(int argc, char *argv[]) {
    // error handling for the input in commandline arguments
    if(argc != 2) {
        std::cerr << "Error : Use in this format : "<<argv[0]<<" <fileName>"<<std::endl;
        return 1;
    }

    // open file
    std::ifstream inputFile(argv[1]); 

    // error handling for the file open operation
    if (!inputFile.is_open()) {
        std::cerr<<"Error: Cannot open file "<<argv[1]<<std::endl;
        return 1;
    }
    // thread creation and passing the input to it
    std::vector<pthread_t> threads;
    std::string line;
    while(std::getline(inputFile, line)) {
        std::string *lineCopy = new std::string(line);
        pthread_t tid;
        if(pthread_create(&tid, NULL, routine, lineCopy) != 0) {
            perror("Error: Failed to create a thread");
            delete lineCopy;
        } else {
            threads.push_back(tid);
        }
    }
    // wait for the thread to complete
    for(auto &t : threads) {
        pthread_join(t, NULL);
    }

    inputFile.close();
    std::cout << "Number of unique words in the file: " << uniqueWords.size() << std::endl;

    pthread_mutex_destroy(&mutex);

    return 0;
}
