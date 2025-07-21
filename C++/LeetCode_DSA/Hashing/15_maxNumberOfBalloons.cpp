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
        minVal = min(minVal,inFreq[key]/value);
    }   
    return minVal;   
}

int main(){
    string text = "nlaebolko";
    cout<<"Maximum formation of ballons are "<<rearrangeCharacters(text)<<endl;
    return 0;
}
