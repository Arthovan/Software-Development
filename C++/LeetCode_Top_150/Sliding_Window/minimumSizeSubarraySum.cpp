/*  209. Minimum Size Subarray Sum  Medium
    Given an array of positive integers nums and a positive integer target, return the minimal length of a 
    subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
Example 1:  Input: target = 7, nums = [2,3,1,2,4,3]
            Output: 2
            Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:  Input: target = 4, nums = [1,4,4]
            Output: 1

Example 3:  Input: target = 11, nums = [1,1,1,1,1,1,1,1]
            Output: 0

Constraints:    1 <= target <= 109
                1 <= nums.length <= 105
                1 <= nums[i] <= 104
Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n))
*/
#include<iostream>
#include<vector>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int i=0, j=0;
    int len = nums.size();
    int currentSum=0;
    //  minLen should be of greater than length of nums initially bcs if we assign len, there can be chances that
    //  all the subarray addition will be of target so to avoid those we assign greater than target
    int minLen=len+1; // or int minLen = numeric_limits<int>::max();

    while(i<len){
        currentSum += nums[i];
        i++;
        while(currentSum >= target){
            if(minLen > (i-j))
                minLen = i-j;
            currentSum -= nums[j];
            j++;
        }
    }
    return minLen != len+1 ? minLen:0;        // or return minLen != numeric_limits<int>::max() ? minLen:0;
}

int main() {
    vector<int> arr{2,3,1,2,4,3};
    int target = 7;
    cout<<"Minimum Length of a Subarray Sum : "<<minSubArrayLen(target, arr)<<endl;
    return 0;
}
