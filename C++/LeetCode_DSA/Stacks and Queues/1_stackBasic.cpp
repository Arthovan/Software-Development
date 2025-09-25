/*  Stack : A stack is a linear data structure that follows the Last In, First Out (LIFO) principle. This means that the last element added to the stack will be the first one to be removed. Stacks are analogous to a stack of plates where you can only add or remove plates from the top. Common operations in a stack include:
    * Push: Adding an element to the top of the stack.
    * Pop: Removing the top element from the stack.
    * Peek/Top: Retrieving the top element without removing it.
    * Size: To get the size of the stack(shows how many elements in the stack)
    * Stacks are used in various applications such as reversing a word, backtracking algorithms (like finding a path in a maze), and in the implementation of function calls in recursion.
*/
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(int argc, char*argv[]){
    // Declaration: C++ supports multiple implementations, but we will be using
    // std::stack. Specify the data type
    stack<int> stack;

    // Pushing elements:
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // Popping elements:
    // Note, unlike other languages, popping here does not return the popped value
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;

    // Check if empty
    stack.empty()==0?cout<<"Stack is Not Empty"<<endl:cout<<"Stack is Empty"<<endl; // false

    // Check element at top
    cout<<"Stack top value is : "<<stack.top()<<endl; // 1

    // Get size
    cout<<"Stack size is : "<<stack.size()<<endl; // 1
    stack.pop();
    cout<<"Stack size is : "<<stack.size()<<endl; // 0

    return 0;
}
//////////////////////////////////





