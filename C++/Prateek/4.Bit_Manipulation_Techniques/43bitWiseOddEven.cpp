#include<iostream>

using namespace std;

int main(){
    int val;
    cout<<"Enter the input value: ";
    cin>>val;
    if(val&1)
        cout<<"Odd"<<endl;
    else
        cout<<"Even"<<endl;
}