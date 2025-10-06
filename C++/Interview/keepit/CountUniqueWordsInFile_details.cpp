#include <iostream>
#include <fstream>          // file stream
#include <string>           //  string
#include <sstream>          //  string stream
#include <unordered_set>
#include <algorithm>        //  tranform() function is in this library
#include <pthread.h>
#include <vector>

std::unordered_set<std::string> uniqueWords;        //  store distinct words from each thread into the global set
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  //  create a mutex variable for thread synchronisation

// thread function to handle the count of words by line 
void* routine(void *arg){
    std::string line = *(std::string*)arg;          //  store the received line from main function in local string "line"
    delete (std::string*)arg;                       //  free allocated memeory in heap (its created in the main function)

    std::stringstream ss(line);                     //  create a string stream and assign it with "line" which we receive from main as "arg"
    std::string word;
    std::unordered_set<std::string> localSet;       //  local set for each thread to store the words from each line
    while (ss >> word) {                            //  loop the stream by word
        // convert word to lowercase to make comparison case-insensitive
        std::transform(word.begin(), word.end(), word.begin(), ::tolower); // syntax : transform(start, end, start_position, operation)

        if (!word.empty())                          //  check if word is not empty
            localSet.insert(word);                  //  insert only if word is not empty  
    }

    // merge into the global set
    pthread_mutex_lock(&mutex);                     //  apply mutex lock for synchronisation between threads
    for(auto &globalWord : localSet) {
        uniqueWords.insert(globalWord);             //  as set wont take duplicates we can avoid the repetition
    }
    pthread_mutex_unlock(&mutex);                   //  remove mutex lock

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

    std::vector<pthread_t> threads;                                 //  create a vector of threads
    std::string line;                                               //  create a string
    while(std::getline(inputFile, line)) {                          //  loop through each line of a file
        std::string *lineCopy = new std::string(line);              //  store the line in a heap
        pthread_t tid;                                              //  Pointer to a pthread_t variable where the system can store the ID of the new thread.
        //  To create a new thread, we use the pthread_create() function provided by the thread library in C. It initializes and starts the thread to run the given function.
        if(pthread_create(&tid, NULL, routine, lineCopy) != 0) {    
            perror("Error: Failed to create a thread");
            delete lineCopy;
        } else {
            threads.push_back(tid); //  store the each thread ID in the vector
        }
    }

    for(auto &t : threads) {
        pthread_join(t, NULL);      //  join the thread as per the thread ID from the vector
    }

    inputFile.close();              //  close the file descriptor
    std::cout << "Number of unique words in the file: " << uniqueWords.size() << std::endl; //  output the unique words count from the file

    // (Optional) Print the unique words:
    for (const auto& tempWords : uniqueWords) {
        std::cout << tempWords << " ";
    }
    std::cout << std::endl;

    pthread_mutex_destroy(&mutex);  //  destroy the mutex variable

    return 0;
}
