/* Questions asked :    1.  Mostly questions came from project working experience like 
							a.Vtune
                            b.Lauterbauch usage
                        2.  Kernel related questions, boot process of embedded hardware, 
						3. 	Program questions 1
                        4.  Program questions 2
                        5.  Program questions 3
                        6.  Semaphore, mutex and spinlock  */

#include <iostream>
#include <vector>
#include <unordered_map>

/* Program 1 : Given an array of elements and target, return the target indexes*/
std::vector<int> findTarget(std::vector<int> nums, int target) {
    std::unordered_map<int, int> map;
    int size = nums.size();
    
    for(int i = 0; i < size; ++i) {
        int difference = target - nums[i];
        if(map.find(difference) != map.end()) {
            return {map[difference],i};
        }
        map[nums[i]] = i;
    }
    return {-1,-1};
}

/* Program 2   :   Toggle the nibble of any part, it can be nibble 1 or 2 or 3 or 4*/
void toggleRange(int &value, int n) {
    value ^= (0xF << (n * 4));
}

/* Program 3  :    Toggel only the specific bit in a value*/
void toggleBit(int &value, int bitPos) {
    value = value ^ (1<<bitPos);
}

int main() {
    /* Program 1 : Given an array of elements and target, return the target indexes*/
    std::vector<int> val = {2, 3, 6, 7, 9};
    int target = 5;
    std::vector<int> out = findTarget(val, target);
    std::cout<<"The indexes are : ";
    for(auto ne: out) {
        std::cout<<ne<<" ";
    }
    std::cout<<std::endl;
 
    /* Program 2   :   Toggle the nibble of any part, it can be nibble 1 or 2 or 3 or 4*/
    /* Nibble means only 4 bits of 1 byte data*/
    int value = 0xAF;
    std::cout<<"The Toggle Nibble values are : ";
    for(int i = 0; i < 5; ++i) {
        toggleRange(value, i); // where value is the input and i is the nibble to be toggled
        std::cout<<value<<" ";
        printf("%x\n", value);
    }
    
    /* Program 3  :    Toggle only the specific bit in a value*/
    value = 0xFF;
    std::cout<<"The Toggle bit values are : ";
    for(int i = 0; i < 5; ++i) {
        toggleBit(value, i); // where value is the input and i is the bit to be toggled
        std::cout<<value<<" ";
        printf("%x\n", value);
    }
    std::cout<<std::endl;
    return 0;
}


