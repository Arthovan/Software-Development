/* Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
You can use each character in text at most once. Return the maximum number of instances that can be formed.
Example 1: nlaebolko
Input: text = "nlaebolko"
output : 1

Example Walkthrough
Input: "nlaebolko"
s frequencies: {n:1, l:2, a:1, e:1, b:1, o:2, k:1}
"balloon" frequencies: {b:1, a:1, l:2, o:2, n:1}
Compute min:
b: 1 / 1 = 1
a: 1 / 1 = 1
l: 2 / 2 = 1
o: 2 / 2 = 1
n: 1 / 1 = 1
So, minVal = 1 */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<limits>

using namespace std;

int rearrangeCharacters(string s) {
    unordered_map<char,int> inFreq;     //  to check the input string s character count
    unordered_map<char,int> tarFreq;    //  to check the "balloon" string character count
    string target = "balloon";
    int minVal = numeric_limits<int>::max();
    for(auto ele: s){
        inFreq[ele]++;      //  store the string s frequency count
    }
    for(auto ele: target){
        tarFreq[ele]++;     //  store the "balloon" string frequency count
    }
    for(auto [key,value]:tarFreq){  //Iterate through the "ballon" string and its character count
        minVal = min(minVal,inFreq[key]/value); // because "l" and "o" repeats 2 times in string "balloon"so we are dividing in freq value / value so we can get proper output
    }   
    return minVal;   
}

int main(){
    string text = "nlaebolko";
    cout<<"Maximum formation of ballons are "<<rearrangeCharacters(text)<<endl;
    return 0;
}
