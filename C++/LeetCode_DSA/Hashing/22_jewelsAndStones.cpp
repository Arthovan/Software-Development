#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    int numJewelsInStones(std::string jewels, std::string stones) {
        std::unordered_map<char, int> stone_freq;
        int count = 0;
        
        for(char c : stones) {
            stone_freq[c]++;
        }
        
        for(int i = 0; i < jewels.size(); ++i){
            if(stone_freq.find(jewels[i]) != stone_freq.end()) {
                count++;
            }
        }
        return count;
    }
};

int main(int argc, char**argv) {
    std::string jewels = "aA";
    std::string stones = "aAAbbbb";
    
    // Create an instance of Solution class
    Solution sol;
 
    int ans = sol.numJewelsInStones(jewels, stones);
    
    // Print the status
    std::cout << "Number of Jewels can be made with a stone are " << ans<< std::endl;
    
    return 0;
}