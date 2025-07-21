/*  Example 1: You are given a string s and an integer k. Find the length of the longest substring that contains at most k distinct characters.
For example, given s = "eceba" and k = 2, return 3. The longest substring with at most 2 distinct characters is "ece".
*/
#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;
int count(string str, int target){
    unordered_map<char,int> temp;
    int left = 0, maxVal = 0;
    int len = str.size();
    for(int right = 0; right < len; right++){
        temp[str[right]]++;
        while(temp.size() > target){
            temp[str[left]]--;
            if(temp[str[left]] == 0){
                temp.erase(str[left]);
            }
            left++;
        }
        maxVal = max(maxVal, right-left+1);
    }
    return maxVal;
}

int main(){
    string s ="eceba";
    int k = 2;
    cout<<"Count : "<<count(s,2)<<endl;
    return 0;
}
