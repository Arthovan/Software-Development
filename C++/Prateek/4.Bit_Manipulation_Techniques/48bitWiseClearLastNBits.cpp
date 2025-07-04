#include<iostream>

using namespace std;

void clearLastNBits(int value, int bitPos){
    int mask = (-1<<bitPos);
    value &= mask;
    cout<<"After clear N bits, value now is: "<<value<<endl;
}

int main(){
    int val,bitPosition;
    bool bitValue;
    cout<<"Enter the input value: ";
    cin>>val;
    cout<<"Enter the bit position to clear from last: ";
    cin>>bitPosition;
    clearLastNBits(val,bitPosition);
    return 0;
}