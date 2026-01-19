/****************** Polymorphism **********************
Polymorphism is one of the key concepts in object-oriented programming (OOP) and refers to the ability of a single entity (like a method, operator, or object) to behave differently in different contexts. The term “polymorphism” is derived from Greek, meaning “many forms.” In programming, it allows the same method or object to perform different tasks depending on the context.

There are two main types of polymorphism in Java:
    *   Compile-Time Polymorphism (Static Polymorphism)
    *   Run-Time Polymorphism (Dynamic Polymorphism)
    
1. Compile-Time Polymorphism (Static Polymorphism)
    In compile-time polymorphism, the method to be called is resolved at compile time. When we say the method is "resolved" at compile-time, it means that the compiler determines the correct method to invoke based on the method's signature (such as method name, parameters, etc.). It is achieved through method overloading or operator overloading (not supported in Java). */

#include <bits/stdc++.h>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculator calc;

    cout << calc.add(5, 3) << endl;       // Calls int version
    cout << calc.add(5.5, 3.3) << endl;   // Calls double version

    return 0;
}
/*
In this case, the compiler determines whether to call add(int, int) or add(double, double) at compile-time based on the types of arguments passed.

/*********** Keypoints: ***************
    *   Determined at compile-time.
    *   Faster execution since the binding is done early.
    *   Examples: Method Overloading.

Note that the return type cannot be a differentiator for Method Overloading.

2. Run-Time Polymorphism (Dynamic Polymorphism)
    In run-time polymorphism, the method is resolved during the runtime. It is achieved through method overriding. When we say the method is "resolved" at run-time, it refers to the decision about which method (in the case of method overriding) to call being made at the time the program is actually running. This occurs due to the dynamic method dispatch mechanism, where the JVM decides which method of a subclass to call based on the actual object type (not the reference type) at runtime. */

#include <bits/stdc++.h>
using namespace std;

// Parent class
class Animal {
public:
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

// Child class
class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

// Main function
int main() {
    Animal* myAnimal = new Dog();  // Animal pointer but Dog object
    myAnimal->sound();             // Calls Dog's sound() method at runtime

    delete myAnimal;
    return 0;
}
/*
Here, the method to be executed is decided at runtime based on the object type.

/*********** Keypoints: ******************
    *   Determined at runtime.
    *   Slower execution compared to compile-time polymorphism due to late binding.
    *   Examples: Method Overriding. */