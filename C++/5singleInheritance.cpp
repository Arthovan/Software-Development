/*  1. Single Inheritance : In single inheritance, a class is allowed to inherit from only one class. i.e. one base class is inherited by one derived class only. */

#include <iostream>
using namespace std;

class Base {
public:
    int n;
    Base(int data) {
        this->n = data;
    }
    void printN() {
        cout <<"Base : "<< n << endl;
    }
};

// Inheriting Base class publicly
class Derived : public Base {
public:
    // Constructor for Derived class that calls Base class constructor
    Derived(int data) : Base(data) {}	// without this there will be error as we need to initialize the base class data using constructor

    void func() {
        // Accessing Base class members
        n = 22;
    }
};

int main() {
	// Create a base class
	Base ta(12);
	ta.printN();
    // Create an instance of Derived class
    Derived d(10);
    d.printN();  // Output will be 10
	d.func();
	d.printN();  // Output will be 22

    return 0;
}
