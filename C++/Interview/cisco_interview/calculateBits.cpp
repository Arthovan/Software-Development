#include<iostream>
#include<string>

using namespace std;

int calbits(string data){
    int cnt = 0;
    //for int
    /*
    while(data>0){
        cnt++;
        data = data&(data-1);
    }*/

    //for string
    int len = data.length();
    for(int i = 0; i<len;i++){
        if(data[i] == '1')
            cnt++;
    }
    return cnt;
}

int main(){
    int val = 5; // 101
    string s = "10101010011";
    //int temp = calbits(val);
    int temp =calbits(s);
    cout<<"Number of Bits : "<<temp<<endl;
    return 0;
}