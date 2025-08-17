/* Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.
Example 1:
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11 
*/
#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int>& nums) {
    int len = nums.size(), leftTotal = 0, rightTotal = 0, total = 0;
    for(int i = 0; i < len; i++){
        total += nums[i]; // we dont need to have pressum in the every index, just total is fine
    }
    for(int i = 0; i < len; i++){
        rightTotal = total - leftTotal - nums[i]; // we need to remove the pivot too so only nums[i]
        if(rightTotal == leftTotal){
            return i;
        }
        leftTotal += nums[i];
    }
    return -1;
}

int main(int argc, char*argv[]){
    vector<int> val = {1,7,3,6,5,6};
    cout<<"Pivot Index is : "<<pivotIndex(val)<<endl;
    return 0;
}