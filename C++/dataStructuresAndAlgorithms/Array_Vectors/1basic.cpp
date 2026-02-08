/* C/C++/Java : An array is a collection of a similar data type placed in contiguous memory locations. But in python we have type called of list where it is of heterogenous data type which can have elements of different data type. */

// Creating an array
// Synatax: data_type array_name[size];

#include <iostream>

using namespace std;

int main() {

    int a[100]; //  allocate a memory for 100 integer at compile time

    int b[100] = {0};   //  we are using the initializer list to make sure the first element is of '0', thereby the uninitialized elements will be initialized with '0'.

    int c[100] = {1,2,3}; // first 3 elements set, remaining are 0

    int d[] = {1,2,3};  // we havent defined the size, where size is optional if we keep the elements in init list method. compiler deduces size = 3

    string fruits[3] = {"apple","mango","guava"};

    // simple Program 

    int marks[100] = {0};
    int n;
    cout<<"Enter the no of students ";
    cin>>n;

    // Input
    for(int i = 0; i < n; ++i) {
        cin>>marks[i];
    }

    // Update
    for(int i = 0; i < n; ++i) {
        marks[i] = marks[i]*2;
    }

    // Output
    for(int i = 0; i < n; ++i) {
        cout<<marks[i]<<" ,";
    }

    cout<<endl;
    return 0;
}
