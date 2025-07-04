#include<iostream>

using namespace std;

/*  Replace bits in N by M
    You are given two 32-bit numbers, N and M, two bit positions i and j.
    write a method to set all bits between i and j in N equal to M.
    M (becomes a substring of N locationed at and starting at j)
    Example:
    N = 10000000000;
    M = 10101;
    i =2, j = 6
    Output : 1001010100
*/
void clearBitsInRange(int &M, int i, int j){    // j is 3 for our case, j+1 is 4 times shifting
    int a = (-1)<<(j+1);    //  1111 1111 << (j+1)  ===> 1111 0000
    int b = (1<<i)-1;       // i is 2,  and I should have value 1 in all bits before i so shifting 1 inot i times and minus 1 will give us the result. Ex: 1 << 3 times is 8 and it is 1000, 8-1 is 7 so it is 0111. Thereby I can have 1 before i elements
    int mask = a | b;
    M = M & mask;
}
void replaceBitsInRange(int &m, int n, int i, int j){
    clearBitsInRange(m, i, j);
    int mask = n << i;
    m = m | mask;
}
int main(){
    int M = 15;
    int N = 2;
    int i = 1, j = 3;
    replaceBitsInRange(M, N, i, j);
    cout<<"After replacing the value of M: "<<M<<endl;
    return 0;
}