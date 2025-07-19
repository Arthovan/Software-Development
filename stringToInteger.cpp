/*You are given an input string as digits, write a function that converts this to an integer.
input = "1234"
output = 1234
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){

    string s = "1234";

    int len = s.size();
    int val = 0;
    int tval = 0;
    for(int i = 0;i<len;i++){
        tval = s[i]- '0';
        val = val*10+tval;
    }
    cout<<"val: "<<val<<endl;      
}