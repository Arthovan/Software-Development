/* We can use the same strategy as power of 2 here,  N * (N - 1), 
    Ex: Number of set bits in 7
    Step 1: increment the counter 
    Step 2: do this operation
        n       =>7     =   0000 0111
        n-1     =>6     =   0000 0110
                            ----------
        n & (n-1)       =   0000 0110 
                            -----------
    Step 3: repeat step 1 until n becomes zero, in every n * n-1 we can get 1 set bit out of the n there we can spend less number of iterations compared to brute force
*/
#include<iostream>

using namespace std;

// Brute force method, where complexity is always O(n), as it has to traverse all the bits on n even if it has zero values
// Lets say 0x01 and its binary is 0000 0001, its for 8 bit values and to check the number of set bits, it has to iterate 8 times
void bfCountSetBits(int n){
    int count = 0;
    while(n>0){
        if(n&1)
            count++;
        n = n >>1;
    }
    cout<<"Count bits via Brute Force is : "<<count<<endl;

}
// Efficient method of n*(n-1), where minimum complexity is always O(1) and maximum complexity is O(n) , as it has to traverse only if it has valid ones
// Lets say 0x01 and its binary is 0000 0001, its for 8 bit values and to check the number of set bits, it has to iterate 1 times
// Worst case scenario is 1111 1111, where it has to iterate 8 times to get the number of set bits
void countSetBits(int n){
    int count = 0;
    while(n>0){
        count++;
        //  Removes the last set bit from the current number
        n = n & (n-1);
    }
    cout<<"Count bits via N*(N-1) is : "<<count<<endl;
}

int main(){
    int n;
    cout<<"Enter the number to count its set bits: ";
    cin>>n;
    cout<<"Brute Force Method"<<endl;
    bfCountSetBits(n);
    cout<<"N&N-1 method"<<endl;
    countSetBits(n);
    return 0;
}