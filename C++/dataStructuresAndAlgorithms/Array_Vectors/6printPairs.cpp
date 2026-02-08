#include <iostream>

using namespace std;

/* Time Complexity is O(N^2) */
void printAllPairs(int input[], int size) {
    for(int i = 0; i < size; ++i) {
        int x = input[i];
        for(int j = i + 1; j < size; ++j) {
            int y = input[j];
            cout<<x<<","<<y<<endl;
        }
        cout<<endl;
    }
}

int main(int argc, char*argv[]) {
    int arr[] = {1,2,10,11,19,29,30};
    int size = sizeof(arr)/sizeof(int);
    printAllPairs(arr,size);
    return 0;
}