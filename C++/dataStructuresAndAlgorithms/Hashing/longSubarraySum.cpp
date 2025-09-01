/* Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.
Examples:   Input: nums = [10, 5, 2, 7, 1, 9],  k=15
            Output: 4
    Explanation: The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.
            Input: nums = [-3, 2, 1], k=6
            Output: 0
    Explanation: There is no sub-array in the array that sums to 6. Therefore, the output is 0.
            Input: nums = [-1, 1, 1], k=1
            Output: 3
*/
#include <iostream>
#include <map> 
#include <vector>

using namespace std;

int longestSubarray(vector<int> &nums, int k){
    map<long long,int> temp;
    int maxLen = 0, len = 0;
    long long sum = 0, rem = 0;

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        rem = sum - k;

        if(sum == k){
            maxLen = max(maxLen,i+1);
        }
        if(temp.find(rem) != temp.end()) {
            len = i - temp[rem]; // here we are not doing +1 at the end because tem[rem] will produce 0 as k found by subtracting the sum with k
            maxLen = max(maxLen,len);
            cout<<"i : "<<i<<" temp[rem]: "<<temp[rem]<<endl;
        }
        if(temp.find(sum) == temp.end()) {
            temp[sum] = i;
        }
    }
    return maxLen;        
}

int main(int argc, char*argv[]) {
    vector<int> nums = {10,5,2,7,1,9};
    cout<<"count of subarray sum : "<<longestSubarray(nums,15)<<endl;
    return 0;
}