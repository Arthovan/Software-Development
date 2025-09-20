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