/* Fast Exponentiation :     Lets say a = 3 and power is 5 => 3^5 is the input and convert it as 3^(101), where 101 is the binary representation of 5
                        Where we need to start a "count" variable with an initial value as 1
                        during 1st iteration, if first bit value valid, multiply "count" variable with 3, else do nothing. Then multiply a =a*a, shift n one time 
                        during 2nd iteration, if second bit value valid, multiply "count" variable with 3, else do nothing. Then multiply a =a*a, shift n one time 
                        during 3rd iteration, if third bit value valid, multiply "count" variable with 3, else do nothing. Then multiply a =a*a, shift n one time 

                        Complexity is O(logn)
*/
#include<iostream>

using namespace std;

int fastExponentiation(int num, int power){
    int count = 1;
    while(power > 0){
        int lastBit = power & 1;
        if(lastBit){
            count *= num;
        }
        num = num * num;
        power = power >> 1;
    }
    return count;
}

int main(){
    int number,power,temp;
    cout<<"Enter the number to do the exponent: ";
    cin>>number;
    cout<<"Enter the power: ";
    cin>>power;
    temp = fastExponentiation(number, power);
    cout<<number<<"^"<<power<<" is "<<temp<<endl;
    return 0;
}