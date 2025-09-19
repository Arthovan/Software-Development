#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> freq;
    unordered_set<int> set;
    for(auto i : arr) {
        freq[i]++;
    }
    for(auto i : freq) {
        set.insert(i.second);
    }
    return freq.size() == set.size();
}

int main(int argc, char*argv[]) {
    vector<int> val1{-3,0,1,-3,1,1,1,-3,10,0};
    cout<<"Unique Occurences of numbers valid/or not : "<<uniqueOccurrences(val1)<<endl;      
    return 0;
}