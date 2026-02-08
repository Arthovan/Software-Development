/* Binary search search the elements in a sorted array */

#include <iostream>

using namespace std;

/* Time Complexity is O(log N), BS only for sorted elements only */
int binarySearch(int input[], int target, int size) {
    int start = 0; 
    int end = size - 1;
    while(start <= end) {
        int mid = (start + end)/2;
        if(target == input[mid]){
            return mid;
        } else if( target < input[mid]) {
            end = mid - 1;
        } else if( target > input[mid]) {
            start = mid + 1;
        }
    }
    return -1;
}

int main(int argc, char*argv[]) {
    int arr[] = {1,2,10,11,19,29,30};
    int element;
    cin>>element;
    int size = sizeof(arr)/sizeof(int);

    int index = binarySearch(arr,element,size);
    if(index != -1) {
        cout<<"Element is at index : "<<index<<endl;
    } else {
        cout<<"Element not found"<<endl;
    }
    return 0;
}