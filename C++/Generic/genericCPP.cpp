/*  A stringstream is a part of the C++ Standard Library, defined in the <sstream> header file. 
    It allows us to read from and write to strings like they are streams.
    It lets us take a string and extract data from it (like from cin), It also lets us build strings by inserting data into it (like into cout).

Types of String Streams : There are three types of string stream classes in C++:
    Class       Purpose
stringstream    Both input and output
istringstream   Input only (like cin)
ostringstream   Output only (like cout)
*/

#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main(int argc, char*argv[]) {
    /*---------- Convert String to Integer ----------------*/
    string str = "123";
    int num;
    // Create a stringstream object initialized with 'str'
    stringstream ss(str);
    // Extract an integer from the stringstream and store it in 'num'
    ss >> num;
    cout<<"Integer  : "<<num<<endl;
    /*-------------------------------------------------------*/

    /*---------- Convert Integer to string ----------------*/
    string str1;
    int num1 = 345;
    //Create an empty stringstream object
    stringstream ss1;
    // Insert the integer 'num' into the stringstream
    // This converts the number into characters inside the stream
    ss1 << num1;
    // Extract the contents of the stream as a string and store it in 'str'
    ss1 >> str;

    cout<<"String   : "<<str<<endl;
    /*-------------------------------------------------------*/

    /*---------- Split a Sentence into Words ------------------*/
    string sentence = "C++ is powerful";
    string word;
    // Create a stringstream object initialized with the sentence
    // This lets us read word by word like a stream
    stringstream ss2(sentence);
   
    // Extract words from the stringstream one by one until no more words left
    cout<<"Word     : ";
    while (ss2 >> word) {
        cout << word<< " ";       
    }
    cout<<endl;
    /*-------------------------------------------------------*/

    /*------------- Combine multiple values into a String ------------*/
    int age = 25;          
    string name = "John";  
    // Create an empty stringstream object
    stringstream ss3;       
    // Insert multiple pieces of data (text, variables) into the stringstream
    ss3 << "Name     : " << name << ", Age   : " << age;
    // Get the combined string from the stringstream
    string result = ss3.str();  
    cout << result << endl;
    /*-------------------------------------------------------*/

    /*------------- Resetting or Clearing a stringstream ------------*/
    stringstream ss4;

    // Put some data into the stringstream
    ss4 << "Hello, world!";
    cout << "Before clearing          : " << ss4.str() << endl;

    // Clear the contents of the stringstream
    ss4.str("");     

    // Reset the stringstream's state flags (like eof, fail)
    ss4.clear();      

    // Now we can reuse the stringstream for new data
    ss4 << "New data here!";
    cout << "After clearing and reuse : " << ss4.str() << endl;
    /*-------------------------------------------------------*/

    /*--------------- Tokenize a String ----------------------*/
    string S, T;
    cout<<"Provide a string : ";
    getline(cin, S);

    // Store the string S 
    // into stringstream X
    stringstream X(S);

    while (getline(X, T, ' ')) // get from S and store it in T with the delimiter as "space"
        cout << T << endl;
    /*-------------------------------------------------------*/

    return 0;
}

/*  -----------------------------------   HEADERS ---------------------------------   */
#include <iostream>     //  Contains basic i/p and o/p operations
#include <cmath>        //  Math related functions are defined here
#include <ctime>        //  Random number generator
#include <string>       //  std is here
#include <array>        //  array is defined here
#include <algorithm>    //  algorithms related are defined here like sort, 
#include <vector>       //  conatains std::vector
#include <memory>       //  std::unique pointer is referenced here
//#include "headers.h"
//////////////////////////////////////////////////////////////////////////////////


/*  -----------------------------------   MACROS ---------------------------------   */
#define POINTER_REFERENCE
//////////////////////////////////////////////////////////////////////////////////

/*  -----------------------------------   TYPEDEF ---------------------------------   */
#if defined TYPEDEF // First method of naming the "#if defined our text"
//  Typedef Approach
typedef std::string text_t; //created a new name for the std::string datatype, it so common notation to use "_t" at the end of typedef name to show that it is alias name
typedef int number_t;  

//  Using Approach
//using text_t = std::string;   // same as above typedef
//using number_t = int;         // same as above typedef
using schar_t = char;
using dec_t = double;
//////////////////////////////////////////////////////////////////////////////////
#endif
/*  -----------------------------------   MAIN_CODE ---------------------------------   */
#if defined(NAMESPACE)   // Most of the compilers accept "if defined" and "elif defined" instead of "ifdef" and "elif".
namespace first{
    int x = 1;
}
namespace second{
    int x = 2;
}
#endif

#if defined(BASIC)  // second method of naming the "#if defined(our text)"
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
}
    
#elif defined(VARIABLES)
int main(){
    //  integer (whole number)
    int age;            //declaration
    age = 5;            //assignment
    int year = 2024;
    int days = 7.5;     // will be truncated to 7

    //  double (number including decimal)
    double price = 4.78;
    double gpa = 2.5;
    double temperature = 25.1;

    //  float
    float myFloat = 10.34F;
    float myFloat_two = 10.34;

    //  single character
    char grade = 'A';
    char initial = 'C';
    char currency = '$';

    //  boolean (true or false)
    bool student = false;
    bool power = true;
    bool forSale = 0;
    bool sale = 1;

    //  auto data type
    auto unknown = 6.04;    // auto data type is mainly used when we dont know what is the data type that we are gonna use.
                            // compiler will decide what is the data type as per the data assigned to it


    //  strings (object that represents a sequence of text), strings are provided from the standard name space
    std::string name = "Arun";
    std::string day = "Friday";
    std::string food = "Pizza";
    std::string address = "123 fake st";
    std::cout << "Hello " << name << '\n';
    std::cout << "you are " << age << " years old"<<'\n';
    std::cout << "Unknown : " << unknown << '\n';
}

#elif defined(KEYWORDS)
int main(){
    const double pi =3.14159;   // const will make it unchangeable
    double radius;
    std::cout<<"Enter the radius: ";
    std::cin >> radius;
    double circumference = 2 * pi * radius;

    std::cout << circumference << "cm"<<'\n';
}

#elif defined(NAMESPACE)
#define NORMAL
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

#elif defined(TYPEDEF)
int main(){
    /* typedef  =   Reserved keywords used to create an additional name (alias) for another data type.
                New identifier for an existing type, helps with readability and reduce typos
                Use when there is a clear benefit
                Replaced with 'using' (work better with templates)*/

    text_t wel = "Hai";
    number_t age = 21;
    schar_t sty = 'G';
    dec_t fgr = 5.67;
    std::cout << wel << '\n';
    std::cout << age << '\n';
    std::cout << sty << '\n';
    std::cout << fgr << '\n';
}

#elif defined(ARITHMETIC)
int main(){
    int students = 20;
    students = students + 1;
    students += 1;
    students++;
    std::cout << students << '\n';

    students = students - 1;
    students -= 1;
    students--;
    std::cout << students << '\n'; 

    students = students * 2;
    students *= 2;
    std::cout << students << '\n'; 

    students = students / 2;    //  Decimal values will be truncated as we are using a int here
    students /= 2;
    std::cout << students << '\n'; 

    int remainder = students % 3;
    std::cout << remainder << '\n';
}

#elif defined(TYPECONVERSION)
int main(){
    /* Type Conversion  =   Conversion of a value from one data type to another data type
                        Implicit    =   Automatic
                        Explicit    =   Precede value with new data type EX:(int) */
    double x = 3.14;
    char a = 100;
    std::cout << x << '\n';
    std::cout << (int)x << '\n';    //  Explicit type cast
    std::cout << a << '\n';         //  Implicit cast, 100 ASCII value is 'd' and it is done by complier automatically
}

#elif defined(MATH)
int main(){
    // Math related functions in cpp
    double x = 5.55;
    double y = 6;
    double z;
    // Below functions are defined in "iostream" header file
    z = std::max(x,y);                                      //  returns the max value between these two variables
    std::cout<<"Max:"<<z<<'\n';       
    std::cout<<"Min:"<<std::min(x,y)<<'\n';                 //  returns the min value between these two variables
    std::cout<<"Absolute Value is:"<<std::abs(-3)<<'\n';    //  produce the positive version of the number

    // Below functions are defined in "cmath" header file
    std::cout<<"Pow:"<<pow(2,3)<<'\n';  //  2^3 
    std::cout<<"Square Root of:"<<sqrt(9)<<'\n';        //  Square root of 9    
    std::cout<<"Round-off Value is:"<<round(x)<<'\n';   //  produce the round-off the value (>=0.5 than o/p is 1, <0.5 than o/p is 0)
    std::cout<<"Ceil Value is:"<<ceil(x)<<'\n';         //  produce the ceil value ( Produce the max value even though its in decimal 0.4 or 0.6 still o/p is 1)
    std::cout<<"Floor Value is:"<<floor(x)<<'\n';       //  produce the floor value ( Produce the min value even though its in decimal 0.4 or 0.6 still o/p is 0)
}

#elif defined(CONDITIONAL_STATEMENT)
int main(){
    /*  if statement    =   do something if a condition is true
                        if not check the elif part*()
                        if not execute the else part */
    double val;
    std::cout<< "Enter the whole value:";
    std::cin>>val;
    if(val >=1)
    {
        std::cout<<"Value is Positive"<<'\n';
    }
    else if(val == 0)
    {
        std::cout<<"Value is Zero"<<'\n';
    }
    else if(val < 0)
    {
        std::cout<<"Value is Negative"<<'\n';
    }
    else
    {
        std::cout<<"Invalid Input"<<'\n';
    }
}

#elif defined(SWITCH)
int main(){
    /*  Switch   =  alternative to using many "else if" statements compare one value against matching case */
    int month;
    std::cout << "Enter the day (1 - 7): ";
    std::cin >> month;
    switch(month)
    {
        case 1:
            std::cout << "It is Sunday";
        break;
        case 2:
            std::cout << "It is Monday";
        break;
        case 3:
            std::cout << "It is Tuesday";
        break;
        case 4:
            std::cout << "It is Wednesday";
        break;
        case 5:
            std::cout << "It is Thursday";
        break;
        case 6:
            std::cout << "It is Friday";
        break;
        case 7:
            std::cout << "It is Saturday";
        break;
        default:
            std::cout << "Invalid Input";
    }
}

#elif defined(TERNARY)
int main(){
    /* Ternary Operator ?: = Replacement to an if/else statement
    Condition ? expression1 : espression2; */
    int grade = 60;
    bool hungry = true;
    grade >=60 ? std::cout << "You Pass!" <<'\n' : std::cout << "You Fail!" <<'\n';
    std::cout << (hungry ? "You are hungry" : "You are full");  // Another method of using ternary operator
}

#elif defined(LOGICAL)
int main(){
    /*  &&  =   Check if both the conditions are true
        ||  =   Check if at least one of the conditions are true
        !   =   Reverses the logical state of its operand   */

    int temp = 25;
    bool sunny = true;
    if(temp > 0 && temp < 30){
        std::cout << "The temperature is good!" <<'\n';
    }    
    else if(temp < 0 || temp > 30){
        std::cout << "The temperature is bad!" <<'\n';
    }
    if(!sunny){
        std::cout << "Not sunny outside!" <<'\n';
    }
    else if(sunny){
        std::cout << "Sunny outside!" <<'\n';
    }
}

#elif defined(STRING_FUNCTIONS)
int main(){
    std::string name;
    std::cout<<"Enter your name: ";
    std::getline(std::cin,name);
    std::cout<<name.length()<<'\n';         // Length of the string 
    std::cout<<name.empty()<<'\n';          // Returns boolean value, whether sting is empty or not 
    //std::cout<<name.clear()<<'\n';        // Clear the string, Need to know which header file it is defined
    name = "ARUN";
    name.append("@gmail.com");              // Append to the string 
    std::cout<<name<<'\n';
    std::cout<<name.at(0)<<'\n';            // Returns the character at specific location
    std::cout<<name.insert(0,"@")<<'\n';    // Insert the specific string at specific location
    std::cout<<name.find('A')<<'\n';        // Returns the first position of the character we are looking
    std::cout<<name.erase(0,3)<<'\n';       // Erase the portion of the string, Syntax ===> erase(Start_Index, End_Index)
}

#elif defined(LOOPS)
    /*      1.While     =   Loop until the condition satisfies or infinite 
            Syntax      =   while(Contiion)
                            {   }
            2.do while  =   do some block of code first than check condition, miminum one time the condition will be checked
            Syntax      =   do
                            {   }while(condition);
            3. for loop =   do some intial counter creation, check condition, do the logic and increment
            Syntax      =   for(int i, i>=10;i++)
                            {   }   */
            // Dint create a code as it is basic and takes time to create a content here

#elif defined(FOREACHLOOP)
int main(){
    // foreach loop =   loop that eases the traversal over an iterable data set

    std::string cars[] = {"Benz", "BMW", "Mustang","Ferrari"};  // here we didnt set the indices value
    int size = sizeof(cars)/sizeof(cars[0]);

    // Iterate over an array
    for(std::string i:cars)                                     //  syntax==> for(datatype iterator name:data set to traverse)
    {
        std::cout<<"Cars--"<<i<<'\n';
    }
    return 0;
}

#elif defined(BREAK_CONTINUE)
int main(){
    for(int i = 1; i <= 10; i++)
    {
        if(i==2){
            continue;        // will continue the iteration of loop without executing the piece of code next to it
        }
        else if(i==7){
            break;          // will break the loop when the condition satisfies
        }
        std::cout<<"i="<<i<<'\n';
    }
}

#elif defined(RANDOM)
int main(){
    //Pseudo-random = NOT truly random (but close)

    //srand(time(NULL)); // srand function with seed as "time"
    int range = 0,random = 0;
    random = rand();
    std::cout<<"Random Number is: "<<random<<'\n';
    std::cout<<"Enter the range to display: ";
    std::cin>>range;

    int num = (random % range) + 1;
    std::cout<<"Range of numbers: " <<num<<'\n';
}

#elif defined(VARIABLE_SCOPE)
    //  Local Variables     =   Declared inside a function or block {}
    //  Global Variables    =   Declared outside of all functions
int myNum = 3;
void printNum();
int main(){
    int myNum = 1;
    printNum();
    std::cout<<"Main fn variable = "<<myNum<<'\n';
    // "::" means scope resolution opertaion in this case it is global variable, thereby we can access
    // Global variable even if we have two variables with the same name
    std::cout<<"Global variable in main = "<<::myNum<<'\n';   
    return 0;
}
void printNum(){
    int myNum = 2;
    std::cout<<"printNum fn variable = "<<myNum<<'\n';
    // "::" means scope resolution opertaion in this case it is global variable
    std::cout<<"Global variable in printNum = "<<::myNum<<'\n';
}

#elif defined(SIZEOF)
int main(){
    //  Sizeof()    ==  determines the size in bytes of a variable, data type, class
    //                  objects, etc...
    double gpa = 2.3;
    int val = 5;
    char grade = 'S';
    std::string name = "ARUN";
    bool flag = true;

    std::cout<<"Double:"<<sizeof(gpa)<< " bytes\n";
    std::cout<<"int:"<<sizeof(val)<< " bytes\n";
    std::cout<<"char:"<<sizeof(grade)<< " bytes\n";
    std::cout<<"string:"<<sizeof(name)<< " bytes\n";
    std::cout<<"flag:"<<sizeof(flag)<< " bytes\n";
}

#elif defined(OVERLOAD_FUNCTION)
void bakePizza();
void bakePizza(std::string topping1);
void bakePizza(std::string topping1,std::string topping2);

int main(){
    /*  Funtion name and function arguments together called as "Function Signature"
      even though the function names are same but fn signature is different
      so only the "bakePizza function" is called as per the fn arguments
      This is called as "overload function" in c++    */
    /*  Note:   If we have a same function name with same signature for 2 functions, only function body changes than compiler throws an error "redefenition" of function
                We should make sure we are maintaining the same function body for different data types. See the below examples and all functions has the same body with different data type */
    bakePizza();                    
    bakePizza("pepperoni");
    bakePizza("pepperoni","mushroom");  
}

void bakePizza(void)
{
    std::cout<<"Here is your pizza!"<<'\n';
}
//  Redefenition error bcs of having same function signature with different function body. This is bcs compiler doesnt know which function to choose, as both has same signature
/*void bakePizza(void)
{
    std::cout<<"Here is your pizza!"<<'\n';
    std::cout<<'\n';                            
}*/
void bakePizza(std::string topping1)
{
    std::cout<<"Here is your "<<topping1<<" Pizza!"<<'\n';
}
void bakePizza(std::string topping1,std::string topping2)
{
    std::cout<<"Here is your "<<topping1<<" and "<<topping2<<" pizza!"<<'\n';
}

#elif defined(ARRAY)
    //  Array   =   An array is an data structure that can hold multiple values of same data type in contiguos location
    //              Values are accessed by an index number
    //              "Its same as like variable that holds multiple values"
int main(){
    //  if we are gonna set the array variable during array declaration then we dont need to set the indices value of the array. 
    //  If we are gonna set variable later than we need to specify indices value
    std::string cars[] = {"Corvette", "BMW", "Mustang"}; // here we didnt set the indices value
    std::string cars_test[3];       //  Here we set the indices so that we can specify the values later
    std::cout<<cars<<'\n';          //  Prints arrays base address as array name means base address
    std::cout<<cars[2]<<'\n';       //  Prints arrays 3rd value, as we tried to access using the index methods
    cars[0]= "Camaro";
    std::cout<<cars[0]<<'\n';
    int size = sizeof(cars)/sizeof(cars[0]);
    // Iterate over an array
    for(int i=0;i<size;i++)
    {
        std::cout<<"Cars--"<<i<<":"<<cars[i]<<'\n';
    }
    return 0;
}

#elif defined(ARRAY_FUNCTION)
double getTotal(double prices[], int size_array);
int main(){
    double prices[] = {49.9, 1.23, 16.53, 90.67};
    int size = sizeof(prices)/sizeof(prices[0]);
    /*  While passing array to a function, we need to specify the size as well,
        because the "getTotal" function arguments holds the base address of the array,
        which is pointer and its impossible to know the size with base address alone.
        So, we need to call with array and its size as well */

    //double total = getTotal(prices);
    double total = getTotal(prices,size);
    std::cout<<"$"<<total;
    return 0;
}
/*double getTotal(double prices[]){
    doublt total = 0;

    for(int i =0; i < sizeof(prices)/sizeof(prices[0]);i++){
        total += prices[i];
    }
    return total;
}*/
double getTotal(double prices[], int size_array){
    double total = 0;

    for(int i =0; i < size_array; i++){
        total += prices[i];
    }
    return total;
}

#elif defined(FILL_FUNCTION)
int main(){
    //  fill()  =   fills a range of elements with a specified value
    //              fill(begin, end, value)
    const int SIZE = 99;
    std::string foods[SIZE];

    fill(foods, foods + (SIZE/3), "Pizza");
    fill(foods + (SIZE/3), foods + (SIZE/3)*2, "Bread");
    fill(foods + (SIZE/3)*2, foods + SIZE, "Noodles");

    for(std::string i:foods){
        std::cout << i << '\n';
    }
}

#elif defined(POINTER)
int main(){
    //  Declaring Pointers
    int* number_p{};    //  Can only store an address of a variable of type int
    double* fractionalNumber_p{};   //  Can only store an address of a variable of type double

    //  Explicitly initialize to nullptr
    int* number_p1{nullptr};
    int* fractionalNumber_ptr{nullptr};

    //  All pointer will have the same size as it only stores the size
    std::cout<< "Size of number pointer: " << sizeof(number_p) << ", size of int: " << sizeof(int) << std::endl;
    std::cout<< "Size of fractional pointer: " << sizeof(number_p) << ", size of int: " << sizeof(int) << std::endl;
    std::cout<< "Size of number pointer: " << sizeof(number_p) << ", size of int: " << sizeof(int) << std::endl;
    std::cout<< "Size of number pointer: " << sizeof(number_p) << ", size of int: " << sizeof(int) << std::endl;
}

#elif defined(REFERENCE)
//using std::format;
int main(){
    int x {7};  // x = 7 or x{7} both are same. Its just value assignment
    int* ip = &x;
    int &y = x; // this is a reference variable so its recommended to make it as const so that the software cant change it at run time or during development
    // Reference is nothing but alias for the same variable but new name. So the address will be same

    std::cout << "The value of   x is "<<x << " address is "<< &x <<std::endl;
    std::cout << "The value of *ip is "<<*ip << " address is "<< &ip <<std::endl;;
    std::cout << "The value of   y is "<< y << " address is "<< &y <<std::endl;

    y = 42;

    std::cout << "The value of   x is "<<x << " address is "<< &x <<std::endl;
    std::cout << "The value of *ip is "<<*ip << " address is "<< &ip <<std::endl;
    std::cout << "The value of   y is "<< y << " address is "<< &y <<std::endl;
}

#elif defined(PASSBY_VALUE)
// by default the C++ function calls are of pass by value. Function definition just receive the copy of the actual value passed into it, so if the changes in formal argument value not gonna affect the actual argument value
// here I have used the vector as value but we can use anything
void addElements(std::vector<int> value, int N){
    for(int i=0; i<N; i++){
        vector.push_back(i);
    }
}
int main(){
    std::vector<int> myVector;
    addElements(mvVector, 10);

    for(auto value : myVector){
        std::cout << value << ' ';
    }
    std::cout << '\n';
    return 0;
}

#elif defined(PASSBY_REFERENCE)
// as we can see that the formal arugments are of reference format, if we do some changes here will affect the actual arguments too
// here I have used the vector as value but we can use anything
void addElements(std::vector<int> &value, int N){
    for(int i=0; i<N; i++){
        vector.push_back(i);
    }
}
int main(){
    std::vector<int> myVector;
    addElements(mvVector, 10);

    for(auto value : myVector){
        std::cout << value << ' ';
    }
    std::cout << '\n';
    return 0;
}

#elif defined(DYNAMIC_MEMORY_ALLOCATION)
int main(){
    int *int_ptr = new int; //  Dynamically allocates memory to hold an integer and assigns the address of the allocated memory to the pointer variable 'int_ptr'
    *int_ptr = 243;
    std::cout << "Value " << *int_ptr << '\n';
    std::cout << "Address " << int_ptr << '\n';
    delete int_ptr; //  free that dynamically allocated memory when not in use

    int *array_ptr = new int[10]; // allocates 10 int in memory location 
    // we cant delete this like above, if so only the 1st element in the array will be deleted
    delete[] array_ptr; //  this method deletes the entire array allocated in the memory
    return 0;
}

#elif defined(UNIQUE_POINTER)
//  std::unique_ptr is a small pointer that owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope.
int main(){
    std::unique_ptr<int> ptr(new int);          //  uinque_ptr of int type where dynamic memory allocation is done for int via new
    std::unique_ptr<int[]> ptr(new int[10]);    //  uinque_ptr of int array type where dynamic memory allocation is done for int arrya of 10 elements via new
    
    
    return 0;

}


#elif defined(STANDARD_ARRAY)
/*  std::array is defined in header "array". Its a container that encapsulates fixed size arrays and its a template   */
int main(){
    std::array<int, 3> my_array = {67,24,39};   //  Create a std::array of int with 3 elements named "my_array"
    //  std::cout<<my_array<<'\n';              //  cout wont work for std::array as its not supported for it and we need to use other methods to print which is especially for std::cout
    std::cout<<my_array.at(0)<<'\n';            //  using "at" member function we can get access to individual members of an array
    std::cout<<my_array[1]<<'\n';               //  Normal array accessing method also works
    std::cout<<my_array.front()<<'\n';          //  to get the first element 
    std::cout<<my_array.back()<<'\n';           //  to get the last element
    my_array[0] = 12;
    std::cout<<my_array[0]<<'\n';
    my_array.fill(89);                          //  to fill the entire elements to specified value
    std::cout<<my_array[0]<<'\n';
    std::cout<<my_array.size()<<'\n';           //  to get the size of the array
    return 0;
}

#elif defined(FUNCTION_TEMPLATE)
    #define EXAMPLE_5
    # if defined(EXAMPLE_1)  // used a nested "#if defined", go through that as well
    //Example 1: Same function name used for different data types or different arguments are called as "function overloading". Provided we specified the fun definiton for different data type already
    //It is explained clearly in OVERLOAD_FUNCTION_17
    int max(int x, int y)   {   return (x > y)? x : y;  }
    int max(int x, int y, int z){   if((x>y) && (x>z))  return x;   else if((y>x) && (y>z)) return y;   else    return z;}
    double max(double x, double y)  {   return (x > y)? x : y;  }

    char max(char x, char y)    {   return (x > y)? x : y;  }

    int main(){
        std::cout<<"Example:1 Function Overloading\n";
        std::cout<<max(12,15)<<'\n';        //Same function name with 2 integers
        std::cout<<max(12,15,19)<<'\n';     //Same function name with 3 integers
        std::cout<<max(12.01,15.01)<<'\n';  //Same function name with different data type
        std::cout<<max('A','B')<<'\n';      //Same function name with different data type
        std::cout<<"-----------\n";
        return 0;
    }

    # elif defined(EXAMPLE_2)
    // Example 2: Function Template with same data type
    /*  -----------What if we want to have a single function which can accept a different data type(cant have different number of arguments). This can be achieved by using "Function Template"-----------
        -----------Inorder to accept any data replace the data type into 'T' (we can use any name we want instead of 'T') -----------
        -----------Compiler doesnt know what 'T' is, so we need to add a "Template Parameter Declaration" ( Template <typename T> ) ------------    */
    template <typename T>   //  'T' is the data type
    T max(T x, T y)         //  Return type and function arguments are same data type as we mentioned it as 'T'
    {
        return (x > y) ? x : y;
    }
    int main(){
        std::cout<<"Example:2 Function Template same data type\n";
        std::cout<<"Integer: "<<max(5,7)<<'\n';
        std::cout<<"Character: "<<max('A','B')<<'\n';
        std::cout<<"Double: "<<max(9.034,4.67)<<'\n';
        std::cout<<"-----------\n";
    }

    # elif defined(EXAMPLE_3)
    // Example 3: Function Template with different data type
    template <typename T, typename U>   //  As am gonna use different data type for 1st and 2nd arguments in the function. I have specified here the different typename
    //  As we can see clearly that 2 different arguments (T,U) are used here in the function, 
    //  "auto" is used as return type as the value returning from the function can be any data type, compiler can identify it automatically. (Refer VARIABLES_2 for "auto" data type)
    auto max(T x, U y){
        return (x > y) ? x : y;
    }
    int main(){
        std::cout<<"Example:3 Function Template different data type\n";
        std::cout<<"Integer/Double: "<<max(5,7.234)<<'\n';
        std::cout<<"Character/Integer: "<<max('Z',89)<<'\n';
        std::cout<<"Integer/Double: "<<max(10,9.034)<<'\n'; 
        std::cout<<"-----------\n";
    }

    # elif defined(EXAMPLE_4)
    // Here even though we didnt use template still consider this as template format as it takes different data type as input. 
    // if we do normal compilation then this will throw an error during compilation, we need to use --std=c++20 flag
    // Eg: g++ c++_Notes.cpp -o out --std=c++20 
    auto max(auto x, auto y){
        return (x > y) ? x : y;
        }
    int main(){
        std::cout<<"Example:4 Function Template with 'auto' data type\n";
        std::cout<<"Integer/Double: "<<max(5,7.234)<<'\n';
        std::cout<<"Character/Integer: "<<max('Z',89)<<'\n';
        std::cout<<"Integer/Double: "<<max(10,9.034)<<'\n'; 
        std::cout<<"-----------\n";
    }

    # else   //EXAMPLE_5 Template Specialization
    // If we need to execute special things in the function body for specific data type, and need to execute the template function for the all other data type
    // than we need to add template<> just above the function name 
    // if we do normal compilation then this will throw an error during compilation, we need to use --std=c++20 flag
    // Eg: g++ c++_Notes.cpp -o out --std=c++20 

    auto max(auto x, auto y){
        return (x > y) ? x : y;
    }

    template<>
    auto max(int x, int y){
        std::cout<<"printing from template specialization"<<'\n';
        return (x > y) ? x : y;
    }
    int main(){
        std::cout<<max(204,35)<<'\n';
        std::cout<<max(34.56,45.67)<<'\n';
    }
    # endif


#elif defined(ALGORITHM)
    // Refer the cpp reference documents for the further details
    #define VECTOR
    # if defined SORT
    //  std::sort   ==> used for sorting the elements 
    void print(auto array){
        for(auto i : array){
            std::cout<<i<<' ';
        }
        std::cout<<'\n';
    }
    int main(){
        std::array<int, 5>my_array = {8, 90, 7, 45,-58};
        print(my_array);

        std::sort(my_array.begin(), my_array.end());    
        print(my_array);
        my_array[2] = 100;
        print(my_array);

        std::ranges::sort(my_array);    //  Now this is in ranges library
        print(my_array);
        return 0;
    }

    # else //defined VECTOR
    //  std::vector   ==> vector is a sequence container that encapsulates dynamic size arrays
    void print(std::vector<int> test_var){
        for(auto i : test_var){
            std::cout<<i<<' ';
        }
        std::cout<<'\n';
    }
    int main(){
        std::vector<int> my_var ={8,9,-6,3,-42};
        print(my_var);
        my_var.push_back(6);    //  add an element at the end. As you can see my_var has initalized with 5 elements and now we are increasing it to 6 in run time
        print(my_var);
        my_var.pop_back();      //  removes an element at the end.
        print(my_var);
        std::vector<int> testVar;
        //testVar.reserve(10);     //  It will reserve a space of 10 before run time. comment and umcommnet it to check the output
        for(int i=0;i<10;i++){
            testVar.push_back(i);
            std::cout<<"Size: "<<testVar.size()<<'\n';           //  Returns the number of elements the variable has
            std::cout<<"Capacity: "<<testVar.capacity()<<'\n';   //  Returns the number of elements that can be held in currently allocated storage 
        }
        return 0;
    }
    # endif

#elif defined(CLASS_OBJECTS)
    /*Object   =   A colleciton of attributes and methods. They can have characteristics and could perform actions
                    Can be used to mimic real world items (ex: Phone, Book, Dog)
                    Created from a class which acts as a 'blue-print' */
    class Human{
        public: //Access Secifier
        //Attributes
        std::string name;
        std::string occupation;
        int age;

        //Methods
        void eat(){
            std::cout<< "This person in eating\n";
        }
        void drink(){
            std::cout<< "This person in drinking\n";
        }
        void sleep(){
            std::cout<< "This person in sleeping\n";
        }
    };
int main(){
    Human human1; //Instantiation or object creation 
    human1.name = "Rick";
    human1.occupation = "Scientist";
    human1.age = 70;

    std::cout<<human1.name<<'\n';
    std::cout<<human1.occupation<<'\n';
    std::cout<<human1.age<<'\n';

    human1.eat();
    human1.drink();
    human1.sleep();

    Human human2; //Instantiation or object creation 
    human2.name = "Morty";
    human2.occupation = "Student";
    human2.age = 10;

    std::cout<<human2.name<<'\n';
    std::cout<<human2.occupation<<'\n';
    std::cout<<human2.age<<'\n';
    
    human2.eat();
    human2.drink();
    human2.sleep();
       
    return 0;
}

#else //defined DEFAULT
int main(){
    std::cout<<"END"<<'\n';
}
#endif
