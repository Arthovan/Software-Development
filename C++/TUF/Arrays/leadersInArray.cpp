#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> leaders(std::vector<int>& nums) {
      std::vector<int> val;
      int max = nums[nums.size()-1];
      val.push_back(max);
      for(int i = nums.size()-2; i >= 0; --i) {
        if(nums[i] > max) {
            val.push_back(nums[i]);
            max = nums[i];
        }
      }
      reverse(val.begin(), val.end());
      return val;
    }
};

int main(int argc, char*argv[]) {
    std::vector<int> num = {1,2,5,3,1,2};
    Solution sol;
    std::vector<int> output = sol.leaders(num);
    std::cout<<"Leaders in an array are ";
    for(int val : output) {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
