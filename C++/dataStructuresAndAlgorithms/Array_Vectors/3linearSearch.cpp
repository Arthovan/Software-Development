/* Linear search algorithm is used for finding the index of an element in the array */

#include <iostream>

using namespace std;

/* Time complexity : O(N) */
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; ++i) {
        // check if current element matches the key
        if(arr[i] == key) {
            return i;
        }
    }
    // out of the loop
    return -1;
}
int main(int argc, char *arg[]) {
    int arr[] = {1,2,0,9,6,4,5,8,10};
    int size = sizeof(arr)/sizeof(int);
    int key;
    cin>>key;

    int index = linearSearch(arr, size, key);

    if(index != -1) {
        cout<<"Element is at index "<<index<<endl;
    } else {
        cout<<"Index not found"<<endl;
    }
    return 0;
}