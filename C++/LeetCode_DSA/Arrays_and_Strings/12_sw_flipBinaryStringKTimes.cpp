/* Given a binary array nums and an integer k, return the maximum number of consecutive 1's 
in the array if you can flip at most k 0's.
Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Constraints:
1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length

Time Complexity     :   O(n) 
Space Complexity    :   O(1)
*/

#include<iostream>
#include<vector>

using namespace std;

int maxConsecutive(vector<int> arr, int K) {
    int right = 0, left = 0;
    int cnt = 0;
    int ma = 0;
    int len = arr.size(); 
    for(right = 0; right < len; right++){
        if(arr[right] == 0)
            cnt++;
        while(cnt > K){
            if(arr[left] == 0)
                cnt--;
            left++;
        }
        ma = max(ma,right-left+1); 
    }  
return ma;
}

int main(){
    vector<int> arr{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    cout<<"Max consecutive ones : "<<maxConsecutive(arr,k)<<endl;
    return 0;    
}
