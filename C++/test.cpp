#include <iostream>
#include <string>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
        int i = 0;
        int len = nums.size();
        while(i < len-1){
            if(nums[i] == 0 and nums[i+1] != 0){
                swap(nums[i],nums[i+1]);
                i++;
            }
            else if(nums[i] != 0 and nums[i+1] == 0){
                i++;
            }
        }        
    }

int main(int argc, char*argv[]){
    vector<int> nums = {0,1,0,3,12};
    for(int val : nums)
        cout<<val<<" ";
    cout<<endl;
    return 0;
}