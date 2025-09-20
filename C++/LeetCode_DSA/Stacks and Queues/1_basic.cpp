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
    return 0;
}
//////////////////////////////////





