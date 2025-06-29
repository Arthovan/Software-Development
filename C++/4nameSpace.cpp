#include<iostream>
#define NORMAL	//	use which method you want as per the #define MACROS		
namespace first{
    int x = 1;
}
namespace second{
    int x = 2;
}
int main(){
    /* Namespace    =   Provides a solution for preventing name conflicts in large projects. 
                    Each entity needs a unique name. A namespace allows for identically
                    named entities as long as the namespaces are different. */

    # if defined METHOD_1
    //---------------- Method 1 -------------------------
    int x = 0;
    std::cout << "Method-1 ==> Local x: " << x << std::endl; // prints the x in the current main function local variable
    std::cout << "Method-1 ==> First namespace x: " << first::x <<std::endl;   //  prints the first namespace variable value as we specified with the scope resolution (::) operator that we need from "first" namespace
    std::cout << "Method-1 ==> Second namespace x: " << second::x <<std::endl; //  prints the second namespace variable value as we specified with the scope resolution (::) operator that we need from "second" namespace
    std::cout << '\n';

    //---------------- Method 2 ------------------------- (we cant use both namespace together, if we try than error will be triggered)
    # elif defined METHOD_2_FIRST
    using namespace first;
    // if we have local x and namespace first x than local x will have precedence over namespace x, so comment out the local x
    std::cout << "Method-2 ==> First namespace x: " << x <<std::endl;  // if we specify which namespace we are gonna use than x will be automatically taken from that namespace even we have many 'x' in same name

    # elif defined METHOD_2_SECOND
    using namespace second; 
    // if we have local x and namespace second x than local x will have precedence over namespace x, so comment out the local x
    std::cout << "Method-2 ==> Second namespace x: " << x <<std::endl; // if we specify which namespace we are gonna use than x will be automatically taken from that namespace even we have many 'x' in same name

    # elif defined NORMAL
    //------------------ namespace std-----------------------
    using namespace std;
    cout<<"using namespace std here"<<'\n'; // if we use namespace std than we dont have to use the "std::" but std has many other entities, so it is recommended to use "using std::cout"

    # else
    // ------------- Recommended method of std and strin -----------
    // These are used to reduce some typing
    using std::cout;
    using std::string;
    string var = "Using string in a recommeneded way";

    cout << "Using std in a recommended way" <<'\n';
    cout << var <<'\n';
    # endif
}