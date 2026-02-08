#include <iostream>

using namespace std;

/* Time Complexity is O(N/2), if we ignore the constants then it is 
O(N) */
void reverseArray(int input[], int size) {
    int left = 0;
    int right = size - 1;
    int temp = 0;
    while(left < right) {
        // we can also use inbuilt swap() function instead of the below 3 lines
        temp = input[left];
        input[left] = input[right];
        input[right] = temp;
        left++;
        right--;
    }
}

int main(int argc, char*argv[]) {
    int arr[] = {1,2,10,11,19,29,30};
    int size = sizeof(arr)/sizeof(int);
    reverseArray(arr,size);

    // print the output
    for(int i = 0; i < size; ++i) {
        cout<<arr[i]<<" ,";
    }
    cout<<endl;
    return 0;
}