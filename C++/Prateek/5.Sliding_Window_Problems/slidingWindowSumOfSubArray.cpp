#include<iostream>
#include<vector>

int maxSumSubarray(std::vector<int> num, int elementLength){
    int len =num.size();
    int maxSum = 0, windowSum = 0;
    // baseCase
    if(len < elementLength){
        std::cout<<"Array length is too small"<<std::endl;
        return 0;
    }

    // calculating the sum of first 3 elements as per this example
    for(int i=0;i<elementLength;i++){
        windowSum += num[i];
    }
    maxSum = windowSum; //  Max sum holds the first window value, where window sum holds the same but keep on changed in the below loop
    // Starting the i from 3 as we already calculated the first 3s sum
    for(int i=elementLength;i<len;i++){
        // already maxSum is from num[0] to num[2], now are adding num[4] and removing num[0]
        // Thereby we can calculate the next element into sum and remove first element from sum
        windowSum += num[i] - num[i-elementLength]; 
        maxSum = std::max(maxSum,windowSum);    //checcking whether which is max
    }

    return maxSum;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 10, 7, 8, 9};
    int k = 3;
    std::cout << "Maximum sum of subarray of size " << k << " is: " << maxSumSubarray(nums, k) << std::endl;
    return 0;
}