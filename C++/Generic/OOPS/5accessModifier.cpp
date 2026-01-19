/************** Access Modifiers ********************
Access modifiers in object-oriented programming are keywords that define the visibility and accessibility of classes, methods, variables, and other members of a program. They determine which parts of the program can interact with a particular component, ensuring that code adheres to encapsulation — a key principle of object-oriented programming.
Access modifiers provide a controlled interaction between objects and help enforce good design practices, making programs more reliable, scalable, and easy to debug.

/*********** Purpose of Access Modifiers ***************
In object-oriented programming, the access modifiers play a key role and serve the following purposes:

    *   Encapsulation: Ensures sensitive data and methods are protected from unintended access.
    *   Controlled Access: Allows programmers to specify which parts of the program can interact with certain components.
    *   Modularity and Security: Helps in maintaining the integrity of data by restricting unwanted modifications.
    *   Flexibility: Provides mechanisms for controlled sharing of data between classes and packages.
    
/*********** Types of Access Modifiers *****************
Most of the Object Oriented Progamming languages provide the following four acess levels:

    *   Public: Accessible everywhere (within the same class, same package, and outside the package).
    *   Private: Accessible only within the class where it is declared.
    *   Protected: Accessible within the same package and by subclasses in other packages.
    *   Default: (No Modifier) Accessible within the same package (package-private).
    
///// 1. Public Access Modifier
The Public Access Modifier can make the attributes and methods of a class accessible from anywhere in the program, including classes outside the package. For example, consider the following code snippet: */

#include <bits/stdc++.h>
using namespace std;

class Employee {
public:
    string name; // Public attribute

    void displayName() { // Public method
        cout << "Employee Name: " << name << endl;
    }
};

int main() {
    Employee emp;
    emp.name = "Alice"; // Accessible globally
    emp.displayName();  // Accessible globally
    return 0;
} 

/*
Here, the name attribute and displayName() method is set to public because of which they can be accessed from a separate class (Main class).

///// Keypoints:
    *   Used to provide attributes and methods global access.
    *   Best suited for methods and attributes that need to be universally available.
    *   Does not restrict usage or visibility.
    
//// 2. Private Access Modifier
The Private Access Modifier can make the attributes and methods of a class accessible only within the class where they were declared. For example, consider the following code snippet: */

#include <bits/stdc++.h>
using namespace std;

class BankAccount {
private:
    double balance; // Private attribute

public:
    // Getter to provide controlled access
    double getBalance() {
        return balance;
    }

    // Public method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
};

int main() {
    // Creating an object
    BankAccount acnt;

    // cout << acnt.balance << endl; //  Error: 'balance' is private within this context
    cout << acnt.getBalance() << endl;

    return 0;
}

/* Here, the balance attribute is set to private because of which it can only be access from within the class (using getBalance() method) and throws an error when accessed outside of the class.

///// Keypoints:
    *   Restricts access to sensitive data (balance).
    *   Encourages the use of getter and setter methods to provide controlled access.
    *   Not visible to subclasses or classes within the same package.
    
///// 3. Protected Access Modifier
The Protected Access Modifier can make the attributes and methods of a class accessible within the same package and in subclasses (even if they are in different packages). For example, consider the following code snippet: */

#include <bits/stdc++.h>
using namespace std;

class Vehicle {
protected:
    string type; // Protected attribute

    void displayType() { // Protected method
        cout << "Vehicle Type: " << type << endl;
    }
};

class Car : public Vehicle {
public:
    Car() {
        this->type = "Car"; // Accessible in the subclass
    }
};

/* Here, the Subclasses can inherit and use the type attribute and displayType() method.

///// Keypoints:
    *   Promotes inheritance by allowing child classes to access certain members of the parent class.
    *   Provides more visibility than private but less than public.
    *   Not accessible to unrelated classes outside the package.
    
///// 4. Default (No modifier)
When there is no access modifier specified, by default, the member is package-private. Consider the following code snippet: */

#include <bits/stdc++.h>
using namespace std;

class PackageDemo {
public: // No package-level scope in C++, so we use public
    void showMessage() {
        cout << "Default access in the same package." << endl;
    }
};

int main() {
    PackageDemo demo;
    demo.showMessage(); // Accessible
    return 0;
}

/* Here, the showMessage() method can be accessed from the main method of Main class because it belongs to the same package.

///// Keypoints:
    *   Accessible only within classes in the same package.
    *   Not accessible in subclasses or classes outside the package.
    *   Helps in maintaining package-level encapsulation.
    
//// Comparison table
Here's a table showing whether different scopes like Class, Package, Subclass or World can access the members and attributed defined under different access specifiers:

AccessModifier      Class   Package     Subclass    World
Public              ✔️      ✔️	        ✔️	        ✔️
Protected           ✔️      ✔️	        ✔️          ❌
Default	            ✔️	    ✔️	        ❌	       ❌
Private	            ✔️	    ❌	       ❌	      ❌ 
*/
