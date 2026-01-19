/************ Interface *****************
An interface in Java is a blueprint of a class that defines a contract for behavior but does not provide an implementation. It contains a set of abstract methods (methods without a body) that a class must implement if it chooses to "sign the contract" by implementing the interface. Think of it as a way to specify what a class should do without dictating how it should do it.

Consider the following code Snippet: */

#include <bits/stdc++.h>
using namespace std;

// Interface
class Animal {
public:
    virtual void eat() = 0;
    virtual void sleep() = 0;
};

// Implementing the interface
class Dog : public Animal {
public:
    void eat() override {
        cout << "Dog eats bones." << endl;
    }

    void sleep() override {
        cout << "Dog sleeps in a kennel." << endl;
    }
};

/* Here, Animal is the interface, and Dog is a class implementing it by providing specific behaviors for eat and sleep methods.

/*********** Can interface have instance variables? ***************
No, an interface cannot have instance variables. All fields in an interface are implicitly public, static, and final. This means they act as constants and cannot be changed. Attempting to declare a non-static or non-final field will result in a compilation error.

/*********** Can Interfaces Have Constructors? ****************
No, interfaces cannot have constructors. This is because constructors are used to initialize the state of an object, and interfaces cannot have state (no instance variables). Since interfaces are not classes and cannot be instantiated directly, they do not need constructors.

However, a class that implements an interface can have its own constructors to initialize its objects. For example: */

#include <bits/stdc++.h>
using namespace std;

// Interface
class Vehicle {
public:
    virtual void start() = 0;
    virtual ~Vehicle() = default;
};

// Car implements Vehicle
class Car : public Vehicle {
private:
    string brand;

public:
    Car(string b) {
        brand = b;
    }

    void start() override {
        cout << brand << " car is starting." << endl;
    }
};

/* In the above example, the Car class provides a constructor for initialization, but the Vehicle interface does not.

/************ Can a Class Implement Multiple Interfaces? *****************
Yes, a class in Java can implement multiple interfaces. This is one of the key advantages of using interfaces because Java does not support multiple inheritance with classes, but it does with interfaces. For example: */

#include <bits/stdc++.h>
using namespace std;

class Flyable {
public:
    virtual void fly() = 0;
    virtual ~Flyable() = default;
};

class Swimmable {
public:
    virtual void swim() = 0;
    virtual ~Swimmable() = default;
};

class Duck : public Flyable, public Swimmable {
public:
    void fly() override {
        cout << "Duck is flying." << endl;
    }

    void swim() override {
        cout << "Duck is swimming." << endl;
    }
};

/* Here, the Duck class implements both Flyable and Swimmable interfaces, providing specific behaviors for flying and swimming.

/***************** Key Features of Interfaces ******************
Interfaces are powerful because they enable several key benefits:

    *   Multiple Inheritance: As mentioned earlier, a class can implement multiple interfaces, allowing for functionality from various sources to be combined.
    *   Contracts: An interface acts as a contract that a class must fulfill. This ensures consistency across different classes implementing the interface.
    *   Loosely Coupled Systems: By programming to an interface rather than a concrete class, your code becomes more flexible and easier to maintain.
To better understand, consider the given code snippet: */

#include <bits/stdc++.h>
using namespace std;

// Interface
class PaymentGateway {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentGateway() = default;
};

// PayPal implements PaymentGateway
class PayPal : public PaymentGateway {
public:
    void processPayment(double amount) override {
        cout << "Processing payment via PayPal: $" << amount << endl;
    }
};

// Stripe implements PaymentGateway
class Stripe : public PaymentGateway {
public:
    void processPayment(double amount) override {
        cout << "Processing payment via Stripe: $" << amount << endl;
    }
};

/* Here, a client can use any implementation of PaymentGateway (e.g., PayPal or Stripe) without being tightly coupled to a specific one.

/************* Default and Static Methods in Interfaces *******************

/*********** 1. Static Method ***********
Static methods belong to the class rather than any instance of the class. This means that they can be called without creating an object of the class. Static methods can only directly access static members of the class, not instance variables or instance methods. They are defined using the static keyword. */

#include <iostream>
using namespace std;

class Example {
public:
    static void staticMethod() {
        cout << "This is a static method." << endl;
    }
};

int main() {
    Example::staticMethod();  // Accessing static method using class name
    return 0;
}

/************  Keypoints: **************
    *   They are called on the class itself, not on an instance of the class.
    *   They can be used to perform operations that are common to all instances of a class.
    *   They can access only other static members (variables, methods) of the class.
    *   They cannot access instance variables or methods.

/***************** 2. Default Method *************
Default methods were introduced in Java 8 to allow adding new functionality to interfaces without breaking existing implementations. Prior to Java 8, interfaces could only declare method signatures, leaving the implementation to the classes that implemented the interface. With the introduction of default methods, interfaces can now provide default implementations for methods. */

#include <iostream>
using namespace std;

class Example {
public:
    virtual void defaultMethod() {
        cout << "This is a default method." << endl;
    }
    virtual ~Example() = default;
};

class Demo : public Example {
    // Inherits defaultMethod() from Example
};

int main() {
    Example* obj = new Demo();
    obj->defaultMethod();  // Accessing default method
    delete obj;
    return 0;
}

/***************** Keypoints: **********************
    *   Default methods have a body and are defined using the default keyword in the interface.
    *   They can be called on objects that implement the interface.
    *   They allow user to add new methods to an interface without affecting existing classes that implement the interface.
    *   If a class implements an interface with a default method, the class can override the method if needed.
    
/************ Why Default Method were Introduced? ***********
Before Java 8, adding a new method to an interface would break all existing implementations of that interface. This was a limitation when you wanted to evolve libraries and APIs without breaking backward compatibility. To solve this, Java 8 introduced default methods, allowing interfaces to provide method implementations, ensuring existing classes can still work without modification.

/***************** Use Cases for Defaul Method: ****************
    *   Backward compatibility: Allows the addition of new methods to interfaces without affecting existing classes that implement the interface.
    *   Multiple interfaces: In cases where a class implements multiple interfaces that may have the same method signature, a default method can be used to avoid conflicts by providing a default implementation.
    
/************* Interface Inheritance ****************
Interfaces in Java can extend other interfaces, allowing for inheritance. When an interface inherits another, it can add new methods to the contract defined by the parent interface.
Consider the following code snippet: */

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void eat() = 0;  // pure virtual function
    virtual ~Animal() {}     // virtual destructor
};

class Mammal : public Animal {
public:
    virtual void walk() = 0; // pure virtual function
    virtual ~Mammal() {}
};

class Human : public Mammal {
public:
    void eat() override {
        cout << "Human eats food." << endl;
    }
    void walk() override {
        cout << "Human walks on two legs." << endl;
    }
};

/* Here, the Mammal interface inherits the eat method from Animal and adds the walk method. The Human class implements both methods. */