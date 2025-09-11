/*  1047. Remove All Adjacent Duplicates In String
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

Example 1:  Input: s = "abbaca" Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Example 2:  Input: s = "azxxzy" Output: "ay"    */

#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

string removeDuplicates(string s) {
    stack<char> st;
    string ret="";
    for(char val:s) {
        // This is needed when we need to insert at first or when stack is empty after removing adjacents and still characters are pending to verify in s string
        if(st.empty()) {
            st.push(val);
        } 
        else {
            // Ex: if top is 'a' and current val is 'a' then we can remove from stack 
            if(st.top() == val) {
                st.pop();
            } 
            else { // if char not found then insert
                st.push(val);
            }
        }
    }
    // we need to return the string so we need to copy the stack to string
    while(st.empty() != 1){
        ret += st.top();
        st.pop();
    }
    // as only top is inserted first so we need to reverse the string ret
    reverse(ret.begin(),ret.end());
    return ret;        
}

string removeDuplicatesUsingStrings(string s) {
    string ret="";
    for(char val : s) {
        // if ret string is not empty and last value is == val then we can remove that character from string if not then push that char into the string
        if(!ret.empty() and ret.back() == val) {
            ret.pop_back();
        } else {
            ret.push_back(val);
        }
    }
    return ret;        
}

int main(int argc, char*argv[]){
    string str = "azxxzy";
    cout<<"After removal of adjacent characters : "<<removeDuplicates(str)<<endl;
    // This below method is simple and we consider string as a stack and used it, its not necessary to use stack from stack STL. We can use string as stack.
    cout<<"After removal of adjacent characters : "<<removeDuplicatesUsingStrings(str)<<endl;
    return 0;
}