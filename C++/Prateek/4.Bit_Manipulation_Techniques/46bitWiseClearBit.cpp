#include<iostream>

using namespace std;

void clearBit(int value, int bitValue){
    int mask = ~(1<<bitValue);
    value &= mask;
    
    cout<<"After clear, value now is: "<<value<<endl;
}

int main(){
    int val,bitPosition;
    cout<<"Enter the input value: ";
    cin>>val;
    cout<<"Enter the bit position to clear: ";
    cin>>bitPosition;
    clearBit(val,bitPosition);
    return 0;
}