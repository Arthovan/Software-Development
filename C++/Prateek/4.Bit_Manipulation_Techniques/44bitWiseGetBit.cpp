#include<iostream>

using namespace std;

void getBit(int value, int bitValue){
    int mask = 1<<bitValue;
    if((value & mask))
        cout<<"Bit Values is : 1"<<endl;
    else
        cout<<"Bit Values is : 0"<<endl;
}

int main(){
    int val,bitPosition;
    cout<<"Enter the input value: ";
    cin>>val;
    cout<<"Enter the bit position to get value: ";
    cin>>bitPosition;
    getBit(val,bitPosition);
    return 0;
}