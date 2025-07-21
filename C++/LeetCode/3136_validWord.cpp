#include<iostream>
#include<string>

using namespace std;

bool isValid(string word) {
    bool flag = false;
    char temp;
    if(word.length() < 3) {
        return false;
    }
    else {
        for(char ch : word){
            ch = tolower(ch);
            if(isalnum(ch)){
                if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u'){
                    flag = true;
                }
            }
            else{
                flag = false;
                return flag;
            }
        }
    }
    return flag;        
}

int main(){
    string str = "234Adas";
    cout<<"Word Validity is : "<<isValid(str)<<endl;
    return 0;
}
