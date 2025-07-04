#include<iostream>

using namespace std;

void setBit(int value, int bitValue){
    int mask = 1<<bitValue;
    value |= mask;
    
    cout<<"After set, value now is: "<<value<<endl;
}

int main(){
    int val,bitPosition;
    cout<<"Enter the input value: ";
    cin>>val;
    cout<<"Enter the set bit position to set value: ";
    cin>>bitPosition;
    setBit(val,bitPosition);
    return 0;
}