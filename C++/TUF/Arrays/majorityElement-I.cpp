#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int size = nums.size();
        std::unordered_map<int,int> count;
        for(int num : nums) {
          count[num]++;
        }

        for(auto pair : count) {
            if(pair.second > size/2) {
                return pair.first;
            }
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    std::vector<int> nums = {-2,-2,1,1,1,-2,-2};
    Solution sol;
    int output = sol.majorityElement(nums);
    std::cout<<"Majority element is : "<<output<<std::endl;
    return 0;
}
