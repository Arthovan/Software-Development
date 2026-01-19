#include<iostream>
#include<algorithm>
using namespace std;

int binaryToDecimal(string str) {
    int val = 1;
    int len = str.length();
    int out = 0;
    for(int i = len - 1; i >= 0; --i) {
        if(str[i] == '1') {
            out = out + val;
        }
        val = val * 2;
    }
    return out;
}
int main(int argc, char* argv[]) {
    cout<<"Binary Value is : "<<binaryToDecimal("1111")<<endl;
    return 0;
}