// This concept is quite difficult to understand need to redo this again */
#include<iostream>
#include<cstring>
#include<unordered_map>

using namespace std;

string uniqueSubstring(string s){
    int i = 0;
    int j = 0;
    int windowLen = 0;
    int maxWindowLen = 0;
    int startWindow = -1;  // end of the string

    unordered_map<char,int> m;

    while(j < s.length()){
        char ch = s[j];

        // If it is inside hashmap & its index idx >= start of the current window
        if(m.count(ch) and m[ch]>=i){
            i = m[ch] +1;
            windowLen = j - i; // updated remaining window len excluding current char
        }

        // update the last occurences
        m[ch] = j;
        windowLen++;
        j++;

        //update maxWindowLen at every step
        if(windowLen > maxWindowLen){
            maxWindowLen = windowLen;
            startWindow = i;
        }
    }
    return s.substr(startWindow, maxWindowLen);
}

int main(){
    string input;
    cout<<"Enter the string:";
    cin>>input;
    cout<<uniqueSubstring(input)<<endl;
    return 0;
}
