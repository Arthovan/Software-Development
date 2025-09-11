/*  844. Backspace String Compare

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:  Input: s = "ab#c", t = "ad#c"   Output: true
Explanation: Both s and t become "ac".

Example 2:  Input: s = "ab##", t = "c#d#"   Output: true
Explanation: Both s and t become "".

Example 3:  Input: s = "a#c", t = "b"       Output: false
Explanation: s becomes "c" while t becomes "b". */

#include<iostream>
#include<string>

using namespace std;

string build(string str) {
    string ret="";
    for(char val : str) {
        // if val is not # then we need to insert
        if(val != '#') {
            ret.push_back(val);
        } else { // if val is # and ret is empty then only we need to pop the character from string to avoid poping empty ret string which cause some undefined behaviour
            if(!ret.empty())
                ret.pop_back();
        }
    }
    return ret;        
}

bool backspaceCompare(string s, string t) {
    return build(s) == build(t);
}

int main(int argc, char*argv[]){
    string str1 = "ab#c";
    string str2 = "ad#c";
    cout<<"Equality of string is : "<<backspaceCompare(str1,str2)<<endl;
    return 0;
}