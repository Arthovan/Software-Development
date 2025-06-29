#include<iostream>
int main(){
    /*  std     =   Standard
        cout    =   Character output
        <<      =   Insertion operator
        ::      =   Scope resolution operator
        >>      =   Extraction operator */

    std::cout << "Hai" << '\n';         // "\n" will create a new line after the output, this is better in performance compared to endl
    std::cout << "Arun" << std::endl;   // Benefit of using std::endl is that endl will flush the output buffer

    std::string name;
    std::string fullname;
    std::cin >> name;                   //  this will not read spaces, once we type "Arun Parkugan". Only Arun will be taken as input
    std::cout << "Hello " << name << '\n';
    //  To avoid the space conflict we need to use "getline" function
    std::getline(std::cin,fullname);    //  As we use '\n' at the end of the cin previously and that is affecting here in getline, to avoid this we need to use std::ws (whitespace)
    std::cout << "Hello " << fullname << '\n';
    std::getline(std::cin >> std::ws,fullname);
    std::cout << "Hello " << fullname << '\n';
	return 0;
}