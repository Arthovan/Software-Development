/*  Given an integer array nums sorted in non-decreasing order, return an 
array of the squares of each number sorted in non-decreasing order.

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<int> sortedSquares(vector<int> &num){
    int j = num.size()-1;
    int i = 0,left = 0, right = j;    
    vector<int>temp(num.size(),0);// We need a temp array of same size as nums
    for(int i = j; i > 0; i--){
        if(abs(num[left]) > abs(num[right])){
            temp[i] = num[left] * num[left];
            left++;
        }else{
            temp[i] = num[right] * num[right];
            right--;
        }
    }
    return temp;
}
int main(int argc, char *argv[]){
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> temp;
    temp = sortedSquares(nums);
    cout<<"Soreted squares of arrays are : ";
    for(auto ch: temp)
        cout<<ch<<" ";
    cout<<endl;
    return 0;
}


/* brute force
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int len = nums.size();
        while(i<len){
            nums[i] *= nums[i];
            i++;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
*/
