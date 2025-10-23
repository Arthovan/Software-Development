/* You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average value and 
return this value. Any answer with a calculation error less than 10-5 will be accepted.
Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:
Input: nums = [5], k = 1
Output: 5.00000

Constraints:
n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104
Time Complexity     :   O(n) 
Space Complexity    :   O(1)
*/

#include<iostream>
#include<vector>

using namespace std;

double maxAvgSubarray(vector<int> nums, int k) {
    int i = 0;
    int cSum = 0;
    int maxSum = 0;
    int len = nums.size(); 
    for(i = 0; i < k; i++)
        cSum += nums[i];

    maxSum = cSum;

    for(i = k; i < len; i++){
        cSum += nums[i];
        cSum -= nums[i-k];
        maxSum = max(maxSum,cSum);
    }
    return maxSum/double(k); // because we need to return the average of K
}  

int main(){
    vector<int> arr{1,12,-5,-6,50,3};
    int k = 4;
    cout<<"Max subArray is : "<<maxAvgSubarray(arr,k)<<endl;
    return 0;    
}
