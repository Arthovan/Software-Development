/*  Contiguous Array : Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Step-by-step:
Initialize: temp = {0:-1}, sum=0, maxLen=0

i	nums[i]	sum (0→-1,1→+1)	temp (map)	Action	maxLen
0	0	-1	{0:-1, -1:0}	new sum stored	0
1	1	0	{0:-1, -1:0}	seen sum=0, length=1-(-1)=2	2
2	1	1	{0:-1, -1:0, 1:2}	new sum stored	2
3	1	2	{0:-1,-1:0,1:2,2:3}	new sum stored	2
4	1	3	{...,3:4}	new sum stored	2
5	1	4	{...,4:5}	new sum stored	2
6	0	3	already seen (index=4)	subarray len=6-4=2	2
7	0	2	already seen (index=3)	subarray len=7-3=4	4
8	0	1	already seen (index=2)	subarray len=8-2=6
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findMaxLength(vector<int>& nums) {
    unordered_map<int,int> temp; 
    int sum = 0;                    // balance between 1s and 0s
    int maxLen = 0;                 // longest subarray found
    for(int i = 0;i < nums.size();i++) {
        sum += (nums[i]==1?1:-1);   // Count 1 as +1, and 0 as -1
       
        if(sum == 0){//Bcs sum come to 0 when equal number of 1s & 0s are there
            maxLen = i+1;           // this will capture the above scenario
        }
        if(temp.find(sum) != temp.end()) { // if sum is already in vector 
            maxLen = max(maxLen, i-temp[sum]); // maxLen will be calculated
        } else {
            temp[sum] = i; // insert the sum if it is occured for first time
        }
    }
    return maxLen;
}
int main(int argc, char*argv[]) {
    vector<int> nums = {0,1};
    cout<<"Contiguos Array count is : "<<findMaxLength(nums)<<endl;
    return 0;
}