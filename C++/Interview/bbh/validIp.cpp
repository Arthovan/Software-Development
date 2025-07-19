/* Write a C++ program to determine if a string is an IP format (only IPv4 cases).
Example: 255.255.10.5 is IPv4, 304.2.3.10 is NOT IPv4. Three dots are required in the string, only numbers, and the range of number is between 0 and 255.
*/

#include<iostream>
#include<string>

using namespace std;

bool check(string str){
    int tval = 0, val = 0,cnt = 0;
	int j = str.size();
   
    for(int i=0;i<j;i++){
        if(str[i] >= '0' && str[i] <= '9'){
            tval = str[i] - '0';
            val = val*10 + tval;
        }
        else if((str[i] == '.') && val <= 255){
            cnt++;
			val = 0;
            if(cnt == 4){	//	Return false if string has more then 3 dots
                return false;
            }
        }
        else{				//	Return false if string char value is other then 0 - 9 and dot or >255
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "255.255.255.255";
    cout<<check(s)<<endl;
    return 0;
}
