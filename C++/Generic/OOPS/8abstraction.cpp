/**************** Abstraction ********************************
Abstraction is one of the fundamental concepts of Object-Oriented Programming (OOP). It is the process of hiding the implementation details and showing only the necessary features or interface to the user. In simpler terms, abstraction allows us to focus on what an object does, rather than how it does it.

Abstraction is achieved through abstract classes and interfaces in languages like Java. It allows programmers to create a blueprint or template for objects without having to worry about their specific implementation details, making the system easier to use and manage.

/************* Key Features of Abstraction *****************

    *   Hiding Implementation Details: The goal of abstraction is to hide the complex implementation details of a system and provide a simpler interface for interaction. For example, when you drive a car, you don't need to know how the engine works internally; you just need to know how to start the car, steer, and stop.

    *   Abstract Methods: These are methods declared in abstract classes or interfaces but have no body (i.e., they have no implementation). The implementation must be provided by the subclass or the class that implements the interface.

    *   Concrete Methods: These are methods with complete implementation in an abstract class. Subclasses inherit these methods, but they are also allowed to override them if necessary.

/********** Benefits of Abstraction in Programming ************
Abstraction allows the programmers to:

    *   Simplify the system: By hiding unnecessary details, it reduces complexity.
    *   Improve maintainability: It makes the code more manageable, as changes to implementation details don't affect the rest of the system.
    *   Increase reusability: It allows code to be reused across different parts of the system with different implementations.
    *   Provide security: It ensures that the user interacts with the system at a higher level, without the risk of them modifying or interacting with internal mechanisms directly.
    
/************* Methods of Achieving Abstraction *****************
In Java, abstraction can be implemented using:
    *   Abstract Classes
    *   Interfaces
    
/*********** 1. Abstract Classes:
An abstract class is a class that cannot be instantiated on its own and must be inherited by a subclass. It can have both abstract methods (without implementation) and concrete methods (with implementation).

Abstract methods are those that are declared but not implemented in the abstract class, leaving the actual implementation to be provided by the subclasses. Consider the following code snippet: */

#include <bits/stdc++.h>
using namespace std;

// Abstract class
class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }

    virtual void sound() = 0; // Pure virtual function
};

// Dog class
class Dog : public Animal {
public:
    void sound() override {
        cout << "The dog barks." << endl;
    }
};

// Cat class
class Cat : public Animal {
public:
    void sound() override {
        cout << "The cat meows." << endl;
    }
};

int main() {
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();

    myDog->eat();
    myDog->sound();

    myCat->eat();
    myCat->sound();

    delete myDog;
    delete myCat;

    return 0;
}

/********** Explanation: **************
    *   The Animal class is abstract and defines both an abstract method sound() (which has no body) and a concrete method eat() (which has a body).
    *   The Dog and Cat classes are concrete classes that extend the Animal class. They provide their own implementations for the abstract sound() method.
    *   When we create objects of Dog and Cat, we can call both the inherited concrete eat() method and the overridden sound() method.

/*********** 2. Interface:
An interface is similar to an abstract class, but it can only contain abstract methods (until Java 8, after which default methods were introduced). All methods in an interface are implicitly abstract, and it is used to represent a contract that the implementing classes must fulfill.
Consider the following code snippet: */

#include <bits/stdc++.h>
using namespace std;

// Interface
class Animal {
public:
    virtual void sound() = 0;
    virtual void eat() = 0;
};

// Dog class implementing Animal interface
class Dog : public Animal {
public:
    void sound() override {
        cout << "The dog barks." << endl;
    }

    void eat() override {
        cout << "The dog eats food." << endl;
    }
};

int main() {
    Animal* myDog = new Dog();
    myDog->eat();
    myDog->sound();
    delete myDog;
    return 0;
}

/************* Explanation: ****************
    *   The Animal interface defines two abstract methods: sound() and eat().
    *   The Dog class implements the Animal interface and provides concrete implementations for both methods.
    *   When we create an object of type Dog, we can call the eat() and sound() methods that were defined in the interface and implemented by the Dog class.


/************ Static and Default Method ****************

/************** 1. Static Method
Static methods belong to the class rather than any instance of the class. This means that they can be called without creating an object of the class. Static methods can only directly access static members of the class, not instance variables or instance methods. They are defined using the static keyword.*/

#include <bits/stdc++.h>
using namespace std;

class Example {
public:
    static void staticMethod() {
        cout << "This is a static method." << endl;
    }
};

int main() {
    Example::staticMethod();  // Accessing static method directly using the class name
    return 0;
}

/************ Keypoints: ****************
    *   They are called on the class itself, not on an instance of the class.
    *   They can be used to perform operations that are common to all instances of a class.
    *   They can access only other static members (variables, methods) of the class.
    *   They cannot access instance variables or methods.

/********** 2. Default Method
Default methods were introduced in Java 8 to allow adding new functionality to interfaces without breaking existing implementations. Prior to Java 8, interfaces could only declare method signatures, leaving the implementation to the classes that implemented the interface. With the introduction of default methods, interfaces can now provide default implementations for methods.*/

#include <bits/stdc++.h>
using namespace std;

class Example {
public:
    void defaultMethod() {
        cout << "This is a default method." << endl;
    }
};

class Demo : public Example {
    // Inherits defaultMethod from Example
};

int main() {
    Example* obj = new Demo();
    obj->defaultMethod();  // Accessing default method
    delete obj;
    return 0;
}

/************** Keypoints: **************
    *   Default methods have a body and are defined using the default keyword in the interface.
    *   They can be called on objects that implement the interface.
    *   They allow user to add new methods to an interface without affecting existing classes that implement the interface.
    *   If a class implements an interface with a default method, the class can override the method if needed.
    
/********* Why Default Method were Introduced?
Before Java 8, adding a new method to an interface would break all existing implementations of that interface. This was a limitation when you wanted to evolve libraries and APIs without breaking backward compatibility. To solve this, Java 8 introduced default methods, allowing interfaces to provide method implementations, ensuring existing classes can still work without modification.

/********** Use Cases for Default Method:
    *   Backward compatibility: Allows the addition of new methods to interfaces without affecting existing classes that implement the interface.
    *   Multiple interfaces: In cases where a class implements multiple interfaces that may have the same method signature, a default method can be used to avoid conflicts by providing a default implementation.

/********** Important Questions *************
/***** Ques: Can an abstract class extend another abstract class?

/***** Ans: Yes, an abstract class can extend another abstract class in Java.
An abstract class can inherit from another abstract class just like a regular class would. The subclass (child abstract class) will inherit the abstract methods and behaviors of the parent class, but it is not required to implement the abstract methods from the parent class unless it is a concrete class (i.e., a class that is not abstract).
If the subclass is also abstract, it can either:
    *   Implement the abstract methods from the parent class, or
    *   Leave them unimplemented (in which case, the subclass must also be declared as abstract).

/***** Ques: Can an abstract class have a constructor and can we create an instance of it?

/***** Ans: No, you cannot create an instance of an abstract class directly in Java. An abstract class is designed to be inherited by other classes, and it is not meant to be instantiated on its own.

However, an abstract class can have a constructor, which can be invoked by a subclass when an instance of the subclass is created. This allows the abstract class to initialize its fields before the subclass adds its own specific behaviors.

/********** Keypoints: ******
    *   Abstract Class Constructor: An abstract class can have constructors, but you cannot create an instance of the abstract class directly. The constructor is only called when a subclass object is created.
    *   Subclass Constructor: When a subclass is instantiated, its constructor can call the constructor of the abstract class using the super() keyword. */

    /******** Exercise *********/
    //Your code goes here
class Animal {
public:
    string name;
    Animal(string l) : name(l){}    //  Constructor for Animal 
    virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
    Dog(string d) :Animal(d){}
    void makeSound() override {
        cout<<"The dog "<<name<<" says : Woof!"<<endl;
    }
};

class Cat : public Animal {
public:
    Cat(string d) :Animal(d){}
    void makeSound() override {
        cout<<"The cat "<<name<<" says : Meow!"<<endl;
    }
};



//Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your abstract class `Animal` and the derived classes 'Dog', 'Cat'.

First, the object of the class Dog is created along with the dog name.
Then the Dog class object is used to call the method makeSound() to print the corresponding text of Dog class.

Next, the object of the class Cat is created along with the cat name.
Then the Cat class object is used to call the method makeSound() to print the corresponding text of Cat class.


int main() {

    // Input names for dog and cat
    string dName, cName;
    getline(cin, dName);
    getline(cin, cName);

    // Create Dog object
    Animal* dog = new Dog(dName);
    dog->makeSound();

    // Create Cat object
    Animal* cat = new Cat(cName);
    cat->makeSound();

    // Clean up
    delete dog;
    delete cat;

    return 0;
}

*/


/*
//Below are the output statements

cout << "The dog " << name << " says : Woof!" << endl;
cout << "The cat " << name << " says : Meow!" << endl;

*/