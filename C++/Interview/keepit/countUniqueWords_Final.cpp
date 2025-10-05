#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <string>
#include <pthread.h>
#include <cstring>

using namespace std;

const size_t BUFFER_SIZE = 1024 * 1024;
const int NUM_THREADS = 4;

struct ThreadData {
    vector<string> *chunks;
    int startIndex;
    int endIndex;
    unordered_set<string> *result;
};

int main(int argc, char* argv[]) {
    // error handling for the input in commandline arguments
    if(argc != 2) {
        cerr << "Error : Use in this format : "<<argv[0]<<" <fileName>"<<endl;
    }

    ifstream file(argv[1]);
    // error handling for file open 
    if(!file.is_open()) {
        cerr<<"Error: Cannot open file "<<argv[1]<<endl;
    }

    // read the file in chunks
    vector<string> chunks;
    char buffer[BUFFER_SIZE];
    string leftOver;

}