
/*  2390. Removing Stars From a String

You are given a string s, which contains stars *.

In one operation, you can:
    *   Choose a star in s.
    *   Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:
    *   The input will be generated such that the operation is always possible.
    *   It can be shown that the resulting string will always be unique.
 
Example 1:
Input: s = "leet**cod*e"    Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".

Example 2:
Input: s = "erase*****"     Output: ""
Explanation: The entire string is removed, so we return an empty string.    */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

string removeStars(string s) {
    stack <char> stack;
    string temp = "";
    for(auto val : s) {
        if(!stack.empty() and val == '*') {
            stack.pop();
        } else {
            stack.push(val);
        }
    }
    while(!stack.empty()) {
        temp += stack.top();
        stack.pop();
    }
    reverse(temp.begin(),temp.end());
    return temp;
}

int main(int argc, char* argv[]) {
    string str{"leet**cod*e"};
    cout<<"After 1 * for 1 character is removed from string, the output is : "<<removeStars(str)<<endl;
    return 0;
}
