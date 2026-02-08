/*  Example 1: Given a string s, return true if it is a palindrome, false otherwise.
    A string is a palindrome if it reads the same forward as backward. That means, 
    after reversing it, it is still the same string. For example: "abcdcba", or "racecar".
    Time Complexity : O(n)
    Space Complexity : O(1)
*/
#include <iostream>
#include <cstring>

using namespace std;
bool isPalindrome(string str){
    string temp;
    int i=0,j=str.length()-1;
    for(char ch : str) {
        if(isalnum(ch)){
            temp += tolower(ch);
        }
    }
    while(i<j){
        if(temp[i] != temp[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main(){
    string str;
    cout<<"Enter the string to check for palindrome: ";
    cin>>str;
    if(isPalindrome(str))
        cout<<"Entered string is Palindrome"<<endl;
    else
        cout<<"Entered string is not a palindrome"<<endl;
    return 0;
}
