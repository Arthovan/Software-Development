/************************ Constructor ****************************
A constructor is a special method in a class designed to initialize an object when it is created. It ensures that the object is set up with the required attributes and state before it is used.

Consider the following example to understand the syntax and working of Constructors: */

#include <bits/stdc++.h>
using namespace std;

class Employee {
private:
    int salary; // to store the salary of employee

public:
    string employeeName; // to store the name of employee

    // Constructor
    Employee() {
        employeeName = "John Doe";
        salary = 5000;
    }

    // Method to set the employee name as given input
    void setName(string s) {
        employeeName = s;
    }

    // Method to set the salary as given input
    void setSalary(int val) {
        salary = val;
    }

    // Method to get the salary of the employee
    int getSalary() {
        return salary;
    }
};

// Main Class
int main() {
    // Creating an object of Employee class
    Employee obj;

    // Attributes of object initialized by the constructor
    cout << "Default values initialized by the constructor:\n" << endl;
    cout << "Employee Name: " << obj.employeeName << endl;
    cout << "Salary: " << obj.getSalary() << endl;

    return 0;
}

/************ Keypoints: ***************

    *   Syntax: A constructor is a method that has the exact same name as the class and does not have a return type (not even void).
    *   A constructor is called when an object is created. This justifies why the above code snippets gives the shown output.
    *   If there is no constructor written for the given class, the language by-default triggers the default constructor.

/************** Purpose of Constructor ******************
There are three major purposes behind creating a constructor for a class which are as follows:

    *   Object Initialization: Constructor helps in initializing an object at the time of creation by assigning it default or user-defined values to object attributes.
    *   Code Reusability: Everytime an object is created, the same code is reused preventing writing mulitple lines of codes to initialize different objects.
    *   Ensures Default Value: Ensures that the object is always started in a default state with default values when initiated.

/****************** Types of Constructor: *********************
There are three different types of constructos:

    *   Non-parameterized Constructor
    *   Parameterized Constructor
    *   Copy Constructor
    
///// 1. Non-parameterized Constructor:
    When a constructor does not take any arguments as the input, it is called a Non-parameterized Constructor. For example, in the given code snippet there are not arguments taken by the constructor. */

class Employee {
public:
    // Non-parameterised constructor
    Employee() {
        cout << "Employee created!" << endl;
    }
};

///// 2. Parameterized Constructor:
/* It is a type of constructor that accepts arguments to initialize attributes with specific values. For example, the following code snippet shows a parameterized constructor initializing the attributes of the object with the arguments provided by the user. */

#include <bits/stdc++.h>
using namespace std;

class Employee {
public:
    string employeeName; // To store the name of the employee
    int salary;          // To store the salary of the employee

    // Parameterized constructor
    Employee(string name, int salary) {
        this->employeeName = name;
        this->salary = salary;
    }
};

// Main Class
int main() {
    /* Creating an object of Employee class and passing 
    values for the parameterized constructor */
    Employee obj("Raj", 10000);

    // Output
    cout << "The salary of employee named " 
         << obj.employeeName << " is " << obj.salary << endl;

    return 0;
}

/*************  Keypoints: ********************
    *   The keyword "this" in Java is a reference to the current instance of the class. It is used to distinguish between instance variables (attributes) and parameters or local variables with the same name.
    *   It is useful in cases when the object must be initialized with user-defined attributes.
    
///// 3. Copy Constructor:
It enables the programmer to create a new object by copying the attributes of an existing object. Java doesn't have an explicit copy constructor like C++ does. However, a copy constructor can be implemented manually by creating a constructor that takes an object of the same class as a parameter and copies its attributes using Constructor Chaining. Here's an example: */

#include <bits/stdc++.h>
using namespace std;

class Employee {
public:
    string employeeName; // To store the name of the employee
    int salary;          // To store the salary of the employee

    // Parameterized constructor
    Employee(string name, int salary) {
        this->employeeName = name;
        this->salary = salary;
    }

    // Copy Constructor
    Employee(const Employee &employee) {
        // Calling another constructor
        this->employeeName = employee.employeeName;
        this->salary = employee.salary;
    }
};

// Main Class
int main() {
    /* Creating an object of Employee class and passing 
    values for the parameterized constructor */
    Employee obj("Raj", 10000);

    // Creating a copy of obj using Copy constructor
    Employee objCopy(obj);

    // Printing the attibutes of copied object
    cout << "Name of the copied employee: " << objCopy.employeeName << endl;
    cout << "Salary of the copied employee: " << objCopy.salary << endl;

    return 0;
}

/******************  Constructor Chaining  **********************
In Java, a constructor can call another constructor of the same class using the this() keyword. This is known as constructor chaining and is used to reduce code duplication and simplify initialization logic.

///// Keypoints:
    *   The this() call must always be the first statement in the constructor.
    *   It allows one constructor to reuse the logic of another constructor in the same class.
    *   The chaining stops when the constructor without a this() call (usually the one with the least number of parameters) is invoked.
    *   There is no limit on the chain length in constructor chaining.
    
///// Use-case:
Constructor chaining is particularly useful in scenarios where a class has multiple constructors with different levels of detail for initializing an object. By chaining constructors, duplicating initialization logic can be avoided while maintaining a single point of truth for setting up the object's state.

///// Constructor Overloading
Constructor overloading occurs when a class has more than one constructor, but each constructor has a different parameter list or different parameter type. It allows an object to be initialized in different ways depending on the parameters provided at the time of object creation. Consider the code snippet given below: */

#include <bits/stdc++.h>
using namespace std;

class Employee {
public:
    string employeeName; // To store the name of the employee
    int salary;          // To store the salary of the employee

    // Default Constructor
    Employee() {
        this->employeeName = "Unknown";
        this->salary = 0;
    }

    // Constructor with one parameter
    Employee(string employeeName) {
        this->employeeName = employeeName;
        this->salary = 0; // Default salary
    }

    // Constructor with two parameters
    Employee(string employeeName, int salary) {
        this->employeeName = employeeName;
        this->salary = salary;
    }

    // Method to display employee details
    void displayDetails() {
        cout << "Employee Name: " << employeeName << endl;
        cout << "Salary: " << salary << endl;
    }
};

// Main Class
int main() {
    // Using Default Constructor
    Employee emp1;
    cout << "Details of Employee 1 (Default Constructor):" << endl;
    emp1.displayDetails();

    cout << endl; // Line break for clarity

    // Using Constructor with one parameter
    Employee emp2("Raj");
    cout << "Details of Employee 2 (One Parameter Constructor):" << endl;
    emp2.displayDetails();

    cout << endl; // Line break for clarity

    // Using Constructor with two parameters
    Employee emp3("Rahul", 5000);
    cout << "Details of Employee 3 (Two Parameters Constructor):" << endl;
    emp3.displayDetails();

    return 0;
}

/************ Advantages: ******************
    *   Flexibility: It provides different ways to create and initialize objects based on available data.
    *   Code Reusability: Allows user to reuse the same class for different initialization scenarios without duplicating code.
    *   Improved Readability: Makes the code more readable and cleaner by grouping related logic in one class. */