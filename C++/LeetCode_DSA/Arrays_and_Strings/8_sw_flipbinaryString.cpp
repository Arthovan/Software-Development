/* Example 2: You are given a binary string s (a string containing only "0" and "1"). 
You may choose up to one "0" and flip it to a "1". What is the length of the longest 
substring achievable that contains only "1"?
For example, given s = "1101100111", the answer is 5. If you perform the flip at index 2, 
the string becomes 1111100111.
Time Complexity     :   O(n) 
Space Complexity    :   O(1)
*/
#include<iostream>
#include<cstring>

using namespace std;

int flipBit(string str) {
    int right = 0, left = 0, sum = 0,ans = 0;
    int len = str.size()-1;
    for(right = 0; right < len; right++){
        if(str[right] == '0'){
            sum++;
        }

        while(sum > 1){
            if(str[left] == '0'){
                sum--;
            }
            left++;
        }
        // as we ned only the maximum length of the index we do right - left +
        // as we are starting index from 0 we need to add +1 to maintain proper value     
        ans = max(ans, right-left+1);  
    }
    return ans;
}

int main(){
    string arr = "1101100111";
    cout<<"After 1 flip of zero, the longest value we can get is "<<flipBit(arr)<<endl;
    return 0;    
}
