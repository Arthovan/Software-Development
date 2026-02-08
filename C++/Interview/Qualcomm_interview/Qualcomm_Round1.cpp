#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/* Questions asked :    1. General Compilation stages and each stages explantion 
                        2. What are the errors tha each stage can identify
                        3. Different section in a memory like data,heap,stack and text
                        4. Explain .bss, .data, .rodata
                        5. SPI protocol operation or CAN protocol operation and its details
                        5. palindrome program
                        6. Reverse the string */


/* check whether the given integer is palindrome or not*/
void palindrome(int temp) {
    int val = 0;
    int main_val = temp;
    while(temp) {
        val = val * 10 + (temp % 10);
        temp = temp / 10;
    }

    if(main_val == val) std::cout<<"Its a palindrome"<<std::endl;
    else std::cout<<"Its a not palindrome"<<std::endl;
}

/*Reverse the given string in wordwise*/
void reverse(std::string &val) {
    int size = val.length();
    int count = 0;
    std::vector<std::string> tempString;
    int left = 0, right = 0;
    std::string local;
    for(char temp : val) {
        count++;
        if(temp == ' ') {
            tempString.push_back(local);
            local.clear();
        } else {
            local += temp;
        }
    }
    tempString.push_back(local);
    for(int i = tempString.size()-1; i >= 0; --i) {
        std::cout<<tempString[i]<<" ";
    }
    std::cout<<std::endl;
}
int main() {
     int val_int = 210;
     palindrome(val_int);   // Program Question 1

     std::string val = "Qualcomm India Private Limited";
     reverse(val);          // Program Question 2
     return 0;
}