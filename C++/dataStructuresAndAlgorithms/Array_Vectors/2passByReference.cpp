#include <iostream>

using namespace std;

// This proves that array passed as an arugments in function means its a pass by reference. where both main and pointArray fucntion shares the same array 
void printArray(int *arr, int n) { // int *arr or int arr[] both are same
    cout<<"In function "<<sizeof(arr)<<endl; // we only received a pointer so it prints pointer type as size. It can be '4' on 32 bit machine and '8' on 64 bit machine

    arr[0] = 100;
    for(int i = 0; i < n; ++i) {
        cout<< arr[i] << endl;
    }
}

int main(int argc, char *argv[]) {
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);

    printArray(arr,n); // changed the value of arr[0] in function also changes the value in main function this also proves that array passing is also an pass by reference.

    cout<<"In main "<<sizeof(arr)<<endl; // this prints the entire array size of 6 * 4 = 24 bytes

    for(int i = 0; i < n; ++i) {
        cout<< arr[i] << endl;
    }

    
    return 0;
}