/* Example 1: 49. Group Anagrams
Given an array of strings strs, group the anagrams together.
For example, given strs = ["eat","tea","tan","ate","nat","bat"], return [["bat"],["nat","tan"],["ate","eat","tea"]] */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& str) {
    vector<vector<string>> temp;
    unordered_map<string,vector<string>> group;
    for(string& s:str) {
        string t = s;   // get the string
        sort(t.begin(),t.end()); // sort it 
        group[t].push_back(s); // store the sting as per the sorted order which matches 
    }
    for(auto [key, value]:group) {
        temp.push_back(value);
    }
    return temp;
}
int main(int argc, char*argv[]) {
    vector<string> str = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> temp = groupAnagrams(str);
    for(vector<string> s : temp) {
        for(string ch : s) {
            cout<<ch<<" ";
        }
    }
    cout<<endl;
    return 0;
}