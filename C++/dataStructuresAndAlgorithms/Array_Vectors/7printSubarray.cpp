#include <iostream>

using namespace std;

/* Time Complexity is O(N^3) */
void printSubarrays(int input[], int size) {
    for(int i = 0; i < size; ++i) {
        for(int j = i; j < size; ++j) {
            for(int k = i; k <= j; ++k) {
                cout<<input[k]<<",";
            }
            cout<<endl;
        }
    }
}

int main(int argc, char*argv[]) {
    int arr[] = {1,2,10,11,19,29,30};
    int size = sizeof(arr)/sizeof(int);
    printSubarrays(arr,size);
    return 0;
}