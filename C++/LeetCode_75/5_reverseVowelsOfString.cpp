/* 345. Reverse Vowels of a String

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:  Input: s = "IceCreAm"   Output: "AceCreIm"

Explanation:    
The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:  Input: s = "leetcode"   Output: "leotcede" */

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

// Moderate solution : Hashing based solution
string reverseVowelsHashingM(string s) {
    unordered_set<char> temp{'a','e','i','o','u'};
    int right = 0;
    int left = s.size()-1;
    while(left > right){
        if(!(temp.find(tolower(s[right])) != temp.end())) {
            right++;
        }
        if(!(temp.find(tolower(s[left])) != temp.end())) {
            left--;
        }
        if((temp.find(tolower(s[left])) != temp.end()) and temp.find(tolower(s[right])) != temp.end()) {
            swap(s[left],s[right]);
            left--;
            right++;
        }
    }
    return s;
}

// Good Solution : Hashing based solution
string reverseVowelsHashing(string s) {
    unordered_set<char> temp{'a','e','i','o','u'};
    int right = 0;
    int left = s.size()-1;
    while(left > right){
        while(left > right and !(temp.find(tolower(s[right])) != temp.end())) {
            right++;
        }
        while(left > right and !(temp.find(tolower(s[left])) != temp.end())) {
            left--;
        }
        swap(s[left],s[right]);
        left--;
        right++;
    }
    return s;
}

// Array and string based solution
string reverseVowels(string s) {
    int right = 0;
    int left = s.size()-1;
    string vowels = "aeiouAEIOU";
    while(left > right){
        while(left > right and vowels.find(s[right]) == string::npos) {
            right++;
        }
        while(left > right and vowels.find(s[left]) == string::npos) {
            left--;
        }
        swap(s[left],s[right]);
        left--;
        right++;
    }
    return s;
}

int main(int argc, char*argv[]) {
    string val = "IceCreAm";
    cout<<"Reverse of Vowel String array/string based solution : "<<reverseVowels(val)<<endl;
    cout<<"Reverse of Vowel String Hashing(Moderate) solution : "<<reverseVowelsHashingM(val)<<endl;
    cout<<"Reverse of Vowel String Hashing solution : "<<reverseVowelsHashing(val)<<endl;
    return 0;
}
