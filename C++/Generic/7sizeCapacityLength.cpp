#include <iostream>
#include <cstring>
#include <array>

using namespace std;

int main(int argc, char*argv[]){
    // int arr[10] = {0};  // we cant use the size() here as its a noraml array with a fixed memory, we need to use sizeof(arr)/sizeof(arr[0]) to find the size

    string str = "Hello";
    cout<<"Size: "<<str.size()<<endl;
    cout<<"Length: "<<str.length()<<endl;
    cout<<"Capacity: "<<str.capacity()<<endl;

    array<int,10> arr = {0};
    cout<<"Size: "<<arr.size()<<endl;
    // cout<<"Length: "<<arr.length()<<endl;    // Because length is only for strings
    // cout<<"Capacity: "<<arr.capacity()<<endl; // Because capacity is only for string and containers
    return 0;
}