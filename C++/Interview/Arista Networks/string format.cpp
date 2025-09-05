/* 1 : Get the input string from STDIN and removes spaces and '-'. output in STDOUT where output should be on following format (blocks of 3 char with spaces and end of the string should have semicolon in it, also if the last block has only 1 character, make sure it has 2 character by formatting the last 2 blocks with 2 character.

Constraints : Output should be in upper character with alphanumerics alone

Example 1 : input   :   4a5-   dsfdfs8634sfd.;;;/.
            output  :   4a5 dsf dfs 863 4s fd
Example 2 : input   :   2-4aor7-4k
            output  :   24a or7 4k
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;
string formatString(string &in) {
    string temp;
    vector<string> out;
    string result;
    
    for(char ch : in){
        // allow only alpha numeric characters
        if(isalnum(ch)){
            temp += toupper(ch); // convert it to upper and store it in the temperary string
        }
    }
    // we need to store the char in blocks of 3 in a vector so that we can format it for the special case, where last 2 block should have 2 characters if only 1 characters is left in the last block
    for(int i = 0; i < temp.size(); i = i+3) {
        out.push_back(temp.substr(i,3));
    }

    // Handle the last block of size 1
    if(!out.empty() and out.back().size() == 1){
        string last = out.back();                   // store the last block which has 1 character 
        out.pop_back();                             // remove the last block from vector 'out'
        if(!out.empty()) {                          // check if block is not empty
            string prev = out.back();               // store the last before block as previous
            out.pop_back();                         // remove the last before block
            if(prev.size() == 3) {                  // check if prev block size is 3
                string a = prev.substr(0,2);        // format the prev block of 2 characters and store it in new string 'a'
                string b = prev.substr(2) + last;   // format the last block which should have 2 characters (prev block last char + last block 1 char) and store it in 'b'
                out.push_back(a);                   // store the formatted previous block back to the vector 'out'
                out.push_back(b);                   // store the formatted last block back to the vector 'out'
            } else { // this else case is not needed in my view but few test cases in hacker rank is failed because of this so added it here
                // Previous has 2 chars, just merge
                out.push_back(prev + last);
            }
        } else { // incase if we have only 1 block which has 1 or 2 or 3 characters, then we should not do anything and push it back to the vector
            out.push_back(last);
        }
    }

    // join spaces after every 3 characters
    for(int i = 0; i < out.size(); i++){
        result += out[i];
        if(i != out.size()-1) {
            result += " ";
        }
    }

    // join the semicolon at the end
    result += ";";
    return result;
}
int main(int argc, char*argv[]) {
    string input;
    string out;
    cout<<"Enter the string: ";
    getline(cin,input);
    out = formatString(input);
    cout<<"Formatted String is : "<<out<<endl;
    return 0;
}