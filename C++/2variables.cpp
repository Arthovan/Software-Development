#include<iostream>
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
	return 0;
}