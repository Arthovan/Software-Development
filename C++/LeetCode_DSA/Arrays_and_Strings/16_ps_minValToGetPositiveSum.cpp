/* Given an array of integers nums, you start with an initial positive value startValue.
In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).
Return the minimum positive value of startValue such that the step by step sum is never less than 1.

Example 1:
Input: nums = [-3,2,-3,4,2]
Output: 5
Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.*/
#include <iostream>
#include <vector>

using namespace std;

int minStartValue(vector<int>& nums) {
    int sum = 0;
    int minSum = 0;
    for(int i = 0; i<nums.size();i++){
        sum += nums[i]; // holds the preSum value
        minSum = min(minSum, sum);  // as we are tracking the min value in every iteration thereby we can get the exact minvalue in preSum
    }
    if(minSum < 0) 
        return 1-minSum;
    return 1;
}

int main(int argc, char*argv[]){
    vector<int> nums = {-3,2-3,4,2};
    cout<<"Minimum positive value is : "<<minStartValue(nums);
    return 0;
}

