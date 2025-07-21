/* Example 3: 1941. Check if All Characters Have Equal Number of Occurrences
Given a string s, determine if all characters have the same frequency.
For example, given s = "abacbc", return true, because all characters appear twice. 
Given s = "aaabb", return false. "a" appears 3 times, "b" appears 2 times. 3 != 2.
*/
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<string>

using namespace std;

bool areOccurrencesEqual(string s) {
    unordered_map<char,int> temp;
    unordered_set<int> val;
    int len = s.length();
    for(char elements : s){
        temp[elements]++;
    }
    
    for(auto [key,value] : temp){
        val.insert(value);           
    }
    return val.size()==1;
}

int main(){
    string str = "abacbc";
    cout<<"Character Occurences in : "<<areOccurrencesEqual(str)<<endl;
    return 0;

}
