#include <iostream>
#include <unordered_map>
#include <string>


class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char,int> ran;
        for(char c : magazine) {
            ran[c]++;
        }
        
        for(char c : ransomNote) {
            if(ran[c] <= 0){
                return false;
            }
            ran[c]--;
        }
        return true;
    }
};

int main(int argc, char**argv) {
    std::string ransom = "aa";
    std::string maga = "aab";
    
    // Create an instance of Solution class
    Solution sol;
 
    bool ans = sol.canConstruct(ransom, maga);
    
    // Print the status
    if(ans) {
        std::cout << "ransom can be created using maga" << std::endl;
    } else {
        std::cout << "ransom cannot be created using maga" << std::endl;
    }
    
    return 0;
}