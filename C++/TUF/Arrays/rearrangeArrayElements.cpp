#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> rearrangeArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> output(n, 0);
        int posIndex = 0;
        int negIndex = 1;
        for(int i = 0; i < n; ++i) {
            if(nums[i] < 0) {
                output[negIndex] = nums[i];
                negIndex += 2;
            } else {
                output[posIndex] = nums[i];
                posIndex += 2;
            }
        }
        return output;
    }
};

int main(int argc, char**argv) {
    std::vector<int> val = {2, 4, 5, -1, -3, -4};
    Solution sol;
    std::vector<int> output = sol.rearrangeArray(val);
    std::cout<<"Rearranged array elements are : ";
    for(int val : output) {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
