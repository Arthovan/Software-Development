/* Example 1: Given an array of positive integers nums and an integer k, find the length of the longest subarray whose sum is less than or equal to k. 
This is the problem we have been talking about above. We will now formally solve it.
Time Complexity     :   O(n) 
Space Complexity    :   O(1)
*/
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int longestSubarray(vector<int> arr, int K) {
    int right = 0, left = 0, sum = 0,ans = 0;
    int len = arr.size();
    for(right=0;right<len;right++){
        sum += arr[right];
        
        while(sum > K){
            sum -= arr[left];
            left++;            
        }
        // as we need only the maximum length of the index we do right - left + 1
        // as we are starting index from 0 we need to add +1 to maintain proper value     
        ans = max(ans, right-left+1);  
    }
    return ans;
}

int main(){
    vector<int> arr{3,1,2,7,4,2,1,1,5};
    int  K = 8;
    cout<<"Longest Subarray whose sum is <= K is : "<<longestSubarray(arr, K)<<endl;
    return 0;    
}
