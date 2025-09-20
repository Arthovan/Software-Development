/* 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

Example 1:  Input: nums = [8,2,4,7], limit = 4          Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.

Example 2:  Input: nums = [10,1,2,4,7,2], limit = 5     Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

Example 3:  Input: nums = [4,2,2,2,4,4,2,2], limit = 0  Output: 3  */

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int longestSubarray(vector<int>& nums, int limit) {
    deque<int> increasing;
    deque<int> decreasing;
    int left = 0, ans = 0;
    for(int right = 0; right < nums.size(); right++) {
        while(!increasing.empty() and increasing.back() > nums[right]) {
            increasing.pop_back();
        }

        while(!decreasing.empty() and decreasing.back() < nums[right]) {
            decreasing.pop_back();
        }

        increasing.push_back(nums[right]);
        decreasing.push_back(nums[right]);

        while(decreasing.front() - increasing.front() > limit) {
            if(nums[left] == decreasing.front()) { 
                decreasing.pop_front();
            }
            if(nums[left] == increasing.front()) {
                increasing.pop_front();
            }
            left++;
        }
        ans = max(ans, right-left+1);
    }
    
    return ans;
}

int main(int argc, char*argv[]) {
    vector<int> val{4,2,2,2,4,4,2,2};
    int limit = 0;
    cout<<"Longest Continuous Subarray with Absolute Difference Less than or Equal to Limit is : "<<longestSubarray(val, limit)<<endl;
    return 0;
}
/////////////////////////////////////////