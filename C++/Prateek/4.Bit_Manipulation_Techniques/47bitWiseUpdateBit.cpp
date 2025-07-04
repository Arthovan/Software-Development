#include<iostream>

using namespace std;

int clearBit(int value, int bitPos){
    int mask = ~(1<<bitPos);
    value &= mask;
    return value;
}

void updateBit(int value, int bitPos,bool bitValue){
    value = clearBit(value,bitPos);
    int mask = (bitValue<<bitPos);
    value |= mask;
    
    cout<<"After update, value now is: "<<value<<endl;
}

int main(){
    int val,bitPosition;
    bool bitValue;
    cout<<"Enter the input value: ";
    cin>>val;
    cout<<"Enter the bit position to update: ";
    cin>>bitPosition;
    cout<<"Enter the bit value either 0 or 1: ";
    cin>>bitValue;
    updateBit(val,bitPosition,bitValue);
    return 0;
}