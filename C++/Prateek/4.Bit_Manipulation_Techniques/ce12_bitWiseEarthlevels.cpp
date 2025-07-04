/*  Earth Levels
The Planet Earth is under a threat from the aliens of the outer space and your task is to defeat an enemy who is N steps above you (assume yourself to be at ground level i.e. at the 0th level). You can take jumps in power of 2. In order to defeat the enemy as quickly as possible you have to reach the Nth step in minimum moves possible.

Input Format : In the function an integer is passed.
Output Format : Return an integer representing minimum jumps.
Sample Input : 7
Sample Output : 3
Explanation : 0 -> 4 -> 6 -> 7
*/
#include<iostream>
using namespace std;

// This code is same as n * n -1 method ==>  count the number of set bits
int returnSteps(int k){
    int jump = 0;
    while(k > 0){
        jump++;
        k = k & (k-1);
    }
    return jump;
}

int main(int argc, char const *argv[])// Even without argc and argv this program works fine
{
    int n;
    cout<<"Enter the level: ";
    cin>>n;
    cout<<returnSteps(n)<<endl;
    return 0;
}