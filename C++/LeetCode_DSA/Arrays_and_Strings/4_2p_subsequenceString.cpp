/*  Example 4: 392. Is Subsequence.
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a sequence of characters that can be obtained by deleting some (or none) 
of the characters from the original string, while maintaining the relative order of the remaining characters. 
For example, "ace" is a subsequence of "abcde" while "aec" is not.
    Time Complexity : O(n)
    Space Complexity : O(1)
*/

#include<iostream>
#include<vector>

using namespace std;

bool subsequenceString(string a, string b){
    int i=0,j=0;
    while(i < a.size() and  j < b.size()){
        if(a[i] == b[j]){
            i++;
        }
        j++;
    }
    return i == a.size();
}

int main(){
    string str1 = "abc";
    string str2 = "adbedc";
    subsequenceString(str1, str2) == 1 ? cout<<"Str1 is a subsequence of str2"<<endl : cout<<"Str1 is a not a subsequence of str2"<<endl;
    return 0;
}
