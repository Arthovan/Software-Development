/* A pangram is a sentence where every letter of the English alphabet appears at least once.
Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

Example 1:
Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.

Example 2:
Input: sentence = "leetcode"
Output: false

Constraints:
1 <= sentence.length <= 1000
sentence consists of lowercase English letters.
*/

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

bool pangram(string s) {
    vector<int> temp(26,0);
    for(auto ch:s){
        temp[ch - 'a']++;
    }
    for(auto ch:temp)
        cout<<ch<<" ";
    cout<<endl;
    for(auto ch: temp){     
        if(ch == 0)
            return false;    
    }
    return true;      
}

int main(){
    string num = "thequickbrownfoxjumpsoverthelazydog";     
    bool flag = pangram(num);
    if(flag)
        cout<<"It is a pangram"<<endl;
    else
        cout<<"Its not a pangram"<<endl;
    
    return 0;
}
