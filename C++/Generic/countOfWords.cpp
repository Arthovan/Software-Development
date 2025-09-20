#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int countWords(string str) {
    stringstream temp(str);
    string word;
    unordered_map<string,int> freq;

    while(temp >> word) {
        freq[word]++;
    }
    return freq.size();
}

int main(int argc, char* arg[]) {
    string str;
    cout<<"Enter the string for reference : ";
    getline(cin,str);
    cout<<"Count of the unique words are : "<<countWords(str)<<endl;
    return 0;
}