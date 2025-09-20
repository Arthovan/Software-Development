//format 
#include<iostream>
//#include<format>
//#include<print> //  C++23

int main(int argc, char*argv[]) {
    const char* str{"Hello, World!"};
    std::cout<< "Hello World\n";
    std::cout<< "The std is "<<str<<std::endl;          // cout is safer then printf
    printf("The str is %s\n",str);                      // smaller and faster than cout
    //std::cout<<format("The str is {}\n",str);         // from C++20 we have a new formatter called format which is inspired by python string formatter, this is in the format header
    //std::print("The str is {}\n",str);                // from C++23 there is a print function that uses the same formatter as format. This will mittigate the need for "cout" and "format" in many cases
    return 0;
}
///////////////////////////////