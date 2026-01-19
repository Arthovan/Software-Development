/***********    Inheritance *******************
Inheritance is a fundamental concept in object-oriented programming (OOP) that allows a class (subclass) to inherit the attributes (fields) and behaviors (methods) of another class (superclass). It is the mechanism that promotes code reuse and establishes a hierarchical relationship between classes.
In Java, this concept allows a subclass to inherit or extend the functionality of a superclass, enabling the subclass to reuse code and, in many cases, modify or add new behavior.

Consider the following example where a super class (parent/base class) School has a method printSchoolName(), which is inherited by the subclass Student. Because of this, the program can call the printSchoolName() method from an object of the Student class without causing any errors. Find the code snippet below: */

#include <bits/stdc++.h>
using namespace std;

// Parent class or super class
class School {
private:
    string schoolName; // Private attribute for school name

public:
    // Constructor initializes the school name
    School() {
        schoolName = "DPS"; // Default school name
    }

    // Method to print the school name
    void printSchoolName() {
        cout << "School name: " << schoolName << endl;
    }
};

// Subclass or child class
class Student : public School {
private:
    string studentName; // Private attribute for student name

public:
    // Constructor initializes the student name
    Student(string name) {
        this->studentName = name;
    }

    // Method to print the student name
    void printStudentName() {
        cout << "Student name: " << studentName << endl;
    }
};

// Main function to execute the program
int main() {
    // Create a new student object with the name "Raj"
    Student student("Raj");

    // Print the student's name
    student.printStudentName();

    // Print the school's name
    student.printSchoolName();

    return 0;
}
/*********** Parent Class ************
The parent class (also known as the superclass) is the class that provides common properties (attributes) and behaviors (methods) that are shared by one or more subclasses. It serves as a template or blueprint from which other classes (subclasses) can inherit. For example, School class.

/*********** Subclass (Child Class) ************
A subclass (also known as a child class) is a class that inherits from a parent class. The subclass can reuse, extend, or override the attributes and methods of the parent class to specialize or modify the inherited functionality. For example, Student class.

///// Types of Inheritance:
In Java, there are three major types of inheritance:
    *   Single Inheritance
    *   Multilevel Inheritance
    *   Hierarchical Inheritance
    
///// 1. Single Inheritance

In Single Inheritance, a child class inherits from one parent class. This is the simplest and most common form of inheritance. Consider the following code snippet: */

#include <bits/stdc++.h>
using namespace std;

// Parent class
class Animal {
public:
    // Method to represent the eating behavior of an animal
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

// Child class inheriting from the Animal class
class Dog : public Animal {
public:
    // Method specific to the Dog class to represent barking behavior
    void bark() {
        cout << "This dog barks." << endl;
    }
};

// Main function to execute the program
int main() {
    // Create an object of the Dog class
    Dog dog;

    // Call the eat method inherited from the Animal class
    dog.eat();  // Output: This animal eats food.

    // Call the bark method defined in the Dog class
    dog.bark(); // Output: This dog barks.

    return 0;
}

/************* Keypoints: **************
    *   In a single inheritance, a one-to-one relationship is established.
    *   The child class inherits methods and properties from a single parent class.
    
///// 2. Multilevel Inheritance

In Multilevel Inheritance, a class derives from a child class, creating a chain of inheritance. Here, the child class of one level becomes the parent class for the next level. Consider the code snippet below: */

#include <bits/stdc++.h>
using namespace std;

// Parent class representing general animals
class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

// Intermediate class representing mammals
class Mammal : public Animal {
public:
    void walk() {
        cout << "This mammal walks." << endl;
    }
};

// Subclass representing dogs
class Dog : public Mammal {
public:
    void bark() {
        cout << "This dog barks." << endl;
    }
};

// Main function to demonstrate multilevel inheritance
int main() {
    Dog dog;
    dog.eat();   // Output: This animal eats food.
    dog.walk();  // Output: This mammal walks.
    dog.bark();  // Output: This dog barks.
    return 0;
}

/*************** Keypoints: ****************
    *   In a multilevel inheritance, a one-to-one-to-one relationship across multiple levels is established.
    *   Each child class inherits from its immediate parent, and the chain continues.
    
//// 3. Hierarchical Inheritance
Hierarchical inheritance
In Hierarchical Inheritance, multiple child classes inherit from a single parent class. Consider the code snippet below: */

#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "This dog barks." << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "This cat meows." << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;

    dog.eat();   // Output: This animal eats food.
    dog.bark();  // Output: This dog barks.

    cat.eat();   // Output: This animal eats food.
    cat.meow();  // Output: This cat meows.

    return 0;
}

/*********** Keypoints: ***************
    *   In a hierarchical inheritance, a one-to-many relationship is established between classes.
    *   The child classes share the common methods and properties of the parent class but can also define their unique features.
    
/************* Advantages of Using Inheritance ********************
Inheritance is a cornerstone of object-oriented programming, offering significant benefits such as:

    *   Reusability: It allows you to reuse the code of an existing class in a new class. Instead of rewriting code, the subclass (child class) can inherit the methods and attributes of the parent class. This reduces redundancy and promotes efficient coding.
    *   Modularity: It promotes a modular structure by separating concerns into different classes. Each class focuses on a specific part of the program, improving clarity and manageability.
    *   Extensibility: It enables adding new features or extending existing functionality without modifying the base class. This makes it easy to adapt to changing requirements.
    *   Maintainability: Inheritance makes code easier to maintain by centralizing common features in a parent class. Changes to shared functionality only need to be made in one place, reducing the risk of errors.
    
/************** Important Concepts in Inheritance ****************

1. Access Modifier:
Access modifiers define the visibility and accessibility of classes, methods, and variables in different contexts, including inheritance. Learn more about it here: Access Modifier

2. Method Overriding:
Method overriding allows a subclass to provide a specific implementation of a method already defined in its parent class. This supports runtime polymorphism and enables dynamic behavior. There are some key rules for Overriding:
The method must have the same name, parameters, and return type as the parent class.
The method in the child class cannot have a more restrictive access modifier than the parent method.
Only inheritable methods (public or protected) can be overridden.
The @Override annotation is recommended for clarity.

3. "Super" Keyword:
The super keyword is used in inheritance to:
Access Parent Class Members: Refer to parent class methods or variables when they are shadowed by child class members.
Invoke Parent Class Constructor: Call the parent class constructor to initialize the inherited state.

/*************** Difference between Method Overloading and Method Overriding **********************

Definition:
    *   Method Overloading occurs when two or more methods in the same class have the same name but different parameter lists (number, type, or order of parameters).
    *   Method Overriding occurs when a subclass provides a specific implementation of a method already defined in its parent class.
    
Inheritance Dependency:
    *   Method Overloading does not require inheritance. It happens within the same class.
    *   Method Overriding requires inheritance; occurs between a parent class and its subclass.
    
Parameters:
    *   In Method Overloading, methods must have different parameter lists (number, type, or order).
    *   In Method Overriding, the method must have the same parameter list as the method in the parent class.
    
Access Modifiers:
    *   In Method Overloading, methods can have any access modifier; no restrictions..
    *   The access modifier in the overriding method cannot be more restrictive than in the parent class.
    
/************ Important Point ****************

///// Multiple Inheritance:
    Along with the three types of inheritances discussed above, there is another type of inheritance - Multiple Inheritance.

Multiple inheritance refers to a feature in object-oriented programming where a class can inherit properties and methods from more than one parent class. This allows the child class to combine the functionality of multiple parent classes.

/************* Diamond Problem: ***************
Diamond Problem occurs when a class inherits from two classes that have methods with the same name. The compiler cannot determine which method to execute.

If both B and C inherit from A and override a method, and D inherits from both B and C, which version of the method should D inherit? This ambiguity is why Java restricts multiple inheritance for classes.

///// Note
Note that Java does not allow multiple inheritance using classes to avoid the diamond problem, it allows multiple inheritance through interfaces, as interfaces only declare method signatures (no method bodies initially), thus preventing conflicts.

/*********** Practice (Inheritance) ********************
    You are tasked with creating a class hierarchy to represent employees in a company. Implement a base class Employee and derive classes Manager and Engineer from it. The base class should encapsulate common attributes, and the derived classes should add specific attributes while overriding methods. The derived classes should explicitly call the constructor of the parent class (Employee) to initialize common attributes.

The classes should consist of below specifications :

Base Class: Employee

Attributes : 1) name (string) : Represents the name of the employee.
2) id (Integer) : Unique identifier for the employee.

Methods : 1) displayDetails () : Prints the name and id.


Derived Classes : a) Manager

Attributes : 1) teamSize (Integer) : The size of team managed.
Methods : 1) displayDetails () : calls the parent class method displayDetails() and then prints teamSize.
b) Engineer

Attributes : 1) specialization (string) : The engineer's area of interest.
Methods : 1) displayDetails () : Calls the parent class method displayDetails() and then prints the specialization.


Refer the sample examples for understanding the output format.

The commented code has the output statements return, in order to avoid wrong answers due to case matching or whitespace.



The sample Input follows below naming convention

M -> Prefix of M means input to class Manager

E -> Prefix of E means input to class Engineer


Example 1

Input : M_name = "Jax" , M_id = 101 , M_teamSize = 8

E_name = "William" , E_id = 202 , E_specialization = "Backend Developer"


Output :

Manager Details

Name : Jax

Id : 101

Team Size : 8



Engineer Details

Name : William

Id : 202

Specialization : Backend Developer



Explanation :

The object of Manager class is created with the parametrised constructor to initialize the attributes of both Manager and Employee class.
Then we call the displayDetails of Manager class and print the data of both Employee and Manager class.
We put an empty line between the data displayed for Manger and Engineer class as shown in output. ( This is already written in driver code, user does not have to add this empty line.)
The object of Engineer class is created with the parametrised constructor to initialize the attributes of both Engineer and Employee class.
Then we call the displayDetails of Engineer class and print the data of both Employee and Engineer class. */

class Employee {    //  Base Class
private:
    string name;
    int id;
public:
    Employee(string n, int i) {
        this->name = n;
        this->id = i;
    }
    // specifiying the base class method as "virtual" to override in derived class
    virtual void displayDetails(){ 
        cout<<"Name : "<<name<<endl;
        cout<<"Id : "<<id<<endl;
    }
};

class Manager : public Employee { // Derived Class
private:
    int teamSize;
public:
    Manager(string n, int i, int t) : Employee(n, i) {
        this->teamSize = t;
    }
    void displayDetails () override{
        Employee::displayDetails();
        cout<<"Team Size : "<<teamSize<<endl;
    }
};

class Engineer : public Employee {
private:
    string specialization;
public:
    Engineer(string n, int i, string s) : Employee(n, i) {
        this->specialization = s;
    }
    void displayDetails () override{
        Employee::displayDetails();
        cout<<"Specialization : "<<specialization<<endl;
    }
};
