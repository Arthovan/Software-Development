/*  Convert a number from decimal format into binary format.
    Example :
        Input   : N = 10
        Output  : 1010
*/    
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int num, rem, len;
    vector<int> out;

    cout<<"Enter the number to convert into binary: ";
    cin>>num;
    while(num > 0){
        rem = num & 1;
        out.push_back(rem);
        num = num >> 1;        
    }
    len = out.size();
    for(int i=len-1;i>=0;i--)
        cout<<out[i]<<" ";
    cout<<endl;
    return 0;
}