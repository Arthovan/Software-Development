#include<iostream>
#include<algorithm>
using namespace std;

string decimalToBinary(int n) {
    string val = "";
    while(n  > 0) {
        if(n % 2 == 1) val += "1";
        else val += "0";
        n = n / 2;
    }
    reverse(val.begin(),val.end());
    return val;
}
int main(int argc, char* argv[]) {
    cout<<"Binary Value is : "<<decimalToBinary(15)<<endl;
    return 0;
}