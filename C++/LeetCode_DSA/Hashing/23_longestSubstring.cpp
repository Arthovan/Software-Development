#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> sub;
        int maximum = 0;
        for(char val : s) {
            if(sub.find(val) != sub.end()) {
                maximum = std::max(maximum, sub.size());
                sub.clear();
                sub[val]++;
            }
        }
        return maximum;
    }
};

int main(int argc, char**argv) {
    std::string s = "abcabcbb";
    
    // Create an instance of Solution class
    Solution sol;
 
    int ans = sol.lengthOfLongestSubstring(s);
    
    // Print the status
    std::cout << "Lenght of unique substring is  " << ans<< std::endl;
    
    return 0;
}