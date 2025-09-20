/*  2434. Using a Robot to Print the Lexicographically Smallest String

You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:

Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
Return the lexicographically smallest string that can be written on the paper. 

Example 1:  Input: s = "zza"    Output: "azz"
Explanation: Let p denote the written string.
Initially p="", s="zza", t="".
Perform first operation three times p="", s="", t="zza".
Perform second operation three times p="azz", s="", t="".

Example 2:  Input: s = "bac"    Output: "abc"
Explanation: Let p denote the written string.
Perform first operation twice p="", s="c", t="ba". 
Perform second operation twice p="ab", s="c", t="". 
Perform first operation p="ab", s="", t="c". 
Perform second operation p="abc", s="", t="".

Example 3:  Input: s = "bdda"   Output: "addb"
Explanation: Let p denote the written string.
Initially p="", s="bdda", t="".
Perform first operation four times p="", s="", t="bdda".
Perform second operation four times p="addb", s="", t="".       */

#include<iostream>
#include<unordered_map>
#include<stack>

using namespace std;

string robotWithString(string s) {
    unordered_map<char,int> freq;
    // This for each loop tracks the frequency of characters in the string and map into a unordered map
    for(char c : s) {
        freq[c]++;
    }

    stack<char> robot;      //  empty stack
    string res;             //  empty string
    char minCharacter = 'a';    //  assign minCharacter as 'a' as it is the first one in alphabet
    for(char c : s) {
        robot.push(c);      //  push the first element from string 's' into robot
        freq[c]--;          //  reduce the frequency as it removed from the string
        while(minCharacter != 'z' and freq[minCharacter] == 0) {    //  while current character is not 'z' and its frequency is zero then we can increment the minCharacter 
            minCharacter++;
        }
        while(!robot.empty() and robot.top() <= minCharacter) {     //  while robot is not empty and robot.top() element is less than minCharacter then we can push that element from robot to paper whcih is 'res' in our case
            res.push_back(robot.top());             //  push the robot top into the "res"
            robot.pop();                            //  remove that character from robot
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    string s{"bdda"};
    cout<<"Output of robots lexicographically smallest string is : "<<robotWithString(s)<<endl;
    return 0;
}
////////////////////////////////////////