/* Only for power of 2 alone , if we multiply the given number n with (n-1) the answer is zero then we can say its a power of 2. Note it wont work for other powers remember that
    Ex: 2^3 = 8. Lets check check 8 is power of 2
    n       =>8     =   0000 1000
    n-1     =>7     =   0000 0111
                        ----------
    n & (n-1)       =   0000 0000 
                        -----------                    
*/

#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    if((n&(n-1) )== 0)
        cout<<"Power of 2"<<endl;
    else
        cout<<"Not a power of 2"<<endl;
    return 0;
}