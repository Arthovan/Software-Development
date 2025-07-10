/*  Example 2: 2270. Number of Ways to Split Array
Given an integer array nums, find the number of ways 
to split the array into two parts so that the first section 
has a sum greater than or equal to the sum of the second section. 
The second section should have at least one number.
*/
#include<iostream>
#include<vector>

using namespace std;

int subarraySum(vector<int> arr){
    vector<int> preSum = {arr[0]};
    int ans = 0, len = arr.size();
    for(int i = 1;i < len; i++){
        preSum.push_back(preSum.back()+arr[i]);
    }
    for(int i = 0; i < len-1; i++){
        long left = preSum[i];
        long right = preSum.back() - preSum[i];
        if(left >= right)
            ans++;
    }
    return ans;
}
int main(){
    vector<int> arr{10,4,-8,7};
    cout<<"Number of ways are : "<<subarraySum(arr)<<endl;
    return 0;
}
