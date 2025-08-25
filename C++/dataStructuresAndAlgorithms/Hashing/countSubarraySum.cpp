/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
Examples:   Input: nums = [1, 1, 1], k = 2
            Output: 2
    Explanation: In the given array [1, 1, 1], there are two subarrays that sum up to 2: [1, 1] and [1, 1]. Hence, the output is 2.
            Input: nums = [1, 2, 3], k = 3
            Output: 2
    Explanation: In the given array [1, 2, 3], there are two subarrays that sum up to 3: [1, 2] and [3]. Hence, the output is 2.
            Input: nums = [3, 1, 2, 4], k = 6
            Output: 2
*/
#include <iostream>
#include <unordered_map> 
#include <vector>

using namespace std;

int subarraySum(vector<int> &nums, int k){
    unordered_map<int,int> temp;
    int sum = 0, rem = 0, count = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i]; // preSum
        rem = sum - k;  // calculate the reminder
        if(sum == k) {  // if the current number is the k then we need to increment the count
            count++;
        }
        if(temp.find(rem) != temp.end()) { // if we find the reminder in the map then also we need to increment as k is found
            count += temp[rem]; // there may be of multiple remainder of same value and we need its count here to have a proper finding of count. so only temp[rem]
        } 
        // we need to insert the rem in map only if it is not already in the map
        temp[sum]++;
    }
    return count;
}

int main(int argc, char*argv[]) {
    vector<int> nums = {1,1,1};
    int temp = subarraySum(nums,2);
    cout<<"count of subarray sum : "<<temp<<endl;
    return 0;
}