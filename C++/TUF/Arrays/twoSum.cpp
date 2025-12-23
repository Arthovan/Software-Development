#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int size = nums.size();
        std::unordered_map<int, int> map;
        for(int i = 0; i < size; ++i){
            int remaining = target - nums[i];
            if(map.find(remaining) != map.end()) {
                return{map[remaining], i};
            }
            map[nums[i]] = i;
        }
        return {-1,-1};
    }
};

int main(int argc, char**argv) {
    std::vector<int> val = {2, 4, 5, -1, -3, -4};
    Solution sol;
    std::vector<int> output = sol.twoSum(val,-7);
    std::cout<<"Two Sum indexes are : ";
    for(int val : output) {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;
    return 0;
}