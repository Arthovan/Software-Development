/* Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array. 

Example 1:
Input           :   nums = [3,0,1]
Output          :   2
Explanation     :   n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 
                    2 is the missing number in the range since it does not appear in nums.
Example 2:
Input           :   nums = [0,1]
Output          :   2
Explanation     :   n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:
Input           :   nums = [9,6,4,2,3,5,7,0,1]
Output          :   8
Explanation     :   n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
*/

#include<iostream>
#include<vector>

using namespace std;

 int missingNumber(vector<int>& nums) {
        int len = nums.size();
        // Lets say size is 3, and numbers from 0 to 3. so n(n+1)/2  = 3*4/2 => 6
        int expectedSum = len*(len+1)/2; 
        int actualSum = 0;
        for(int i = 0;i<len;i++){
            actualSum += nums[i];   // as 2 is missing in our case so the current sum is 4
        }
        return expectedSum - actualSum; // by substracting the current sum to expected sum we get the answer    
    }

int main(){
    vector<int> num = {3,0,1};
    cout<<"The missing number is : "<<missingNumber(num)<<endl;    
    return 0;
}

