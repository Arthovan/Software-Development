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

/* Brute Force Way to to the sub array sum*/
/* Time Complexity is O(N^3) */
int subArraySum(int input[], int size) {
    int maxSum = 0;
    for(int i = 0; i < size; ++i) {
        for(int j = i; j < size; ++j) {
            int sum = 0;
            for(int k = i; k <= j; ++k) {
                sum += input[k];
            }
            maxSum = max(sum, maxSum);
        }
    }
    return maxSum;
}

/* Prefix sum to find the subarray sum */
/* Time Complexity is O(N^2) */
int prefixsubArraySum(int input[], int size) {
    int maxSum = 0;
    int prefix[size] = {0};
    prefix[0] = input[0];

    for(int i = 1; i < size; ++i) {
        prefix[i] = prefix[i-1] + input[i];
    }

    for(int i = 0; i < size; ++i) {
        for(int j = i; j < size; ++j) {
            int sum = i > 0 ? prefix[j] - prefix[i-1]:prefix[j];
            maxSum = max(sum, maxSum);
        }
    }
    return maxSum;
}
/* Time Complexity is : O(N) */
int kadanesubArraySum(int input[], int size) {
    int maxSum = 0;
    int currentSum = 0;
 /* Kadanes algorithm is to keep the current sum =0, when the sum is < 0 and add if it is positive */
    for(int i = 0; i < size; ++i) {
        currentSum += input[i];
        if(currentSum < 0 ) {
            currentSum = 0;
        }
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main(int argc, char*argv[]) {
    int arr[] = {1,2,10,11,19,29,30};
    int size = sizeof(arr)/sizeof(int);
    printSubarrays(arr,size);
    cout<<"Sub Array Sum : "<<subArraySum(arr,size)<<endl;
    cout<<"Sub Array Sum (prefixSum) : "<<prefixsubArraySum(arr,size)<<endl;
    cout<<"Sub Array Sum (Kadanes) : "<<kadanesubArraySum(arr,size)<<endl;
    return 0;
}