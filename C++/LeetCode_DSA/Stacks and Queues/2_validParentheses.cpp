/*  20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
    1. Open brackets must be closed by the same type of brackets.
    2. Open brackets must be closed in the correct order.
    3. Every close bracket has a corresponding open bracket of the same type.

Example 1:  Input: s = "()"         Output: true
Example 2:  Input: s = "()[]{}"     Output: true
Example 3:  Input: s = "(]"         Output: false
Example 4:  Input: s = "([])"       Output: true
Example 5:  Input: s = "([)]"       Output: false */

#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool isValid(string s) {
    stack<char> stack;
    char top;
    for(char val:s) {
        if(val == '(' || val == '{' || val == '[') {
            stack.push(val);
        } 
        else {
            // we are checking empty here because if no element other then parentheses in string s or not a open parentheses at start then we need to return false
            if(stack.empty()){
                return false;
            }
            top = stack.top();
            stack.pop();                
            if( (val == ')') and (top != '(')) return false;
            if( (val == '}') and (top != '{')) return false;
            if( (val == ']') and (top != '[')) return false;
        }
    }
    // if stack is empty then valid parentheses or not valid. empty() returns 1 if stack is empty otherwise 0
    return stack.empty();
}

int main(int argc, char*argv[]){
    string str = "(){}[]";
    isValid(str)==1?cout<<"Parentheses are valid"<<endl:cout<<"Parentheses are not valid"<<endl;
    return 0;
}
 
