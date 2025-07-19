#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

char findChar(string val){
      // Create an unordered map to store character counts
    unordered_map<char,int> temp;

    // Count occurrences of each character in the string
    for(char ch : val){
        temp[ch]++;
    }

    // Iterate through the string to find the first non-repeating character
    for(char ch : val){
        if(temp[ch]==1)
            return ch;
    }

    // Return a special value if no non-repeating character is found
    return '\0';    // Null character indicates no non-repeating character
}

int main(){

    string str ="abnectyeessdfs";
    cout<<findChar(str)<<endl;
    return 0;
}
