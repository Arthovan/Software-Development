/************** Understanding the static keyword in Java *********************
In Java, the static keyword is used to indicate that a member belongs to the class rather than to any specific instance of the class. It can be applied to variables, methods, blocks, and nested classes. Members marked as static are shared across all instances of the class, meaning they are loaded only once in memory during the class's lifecycle.

/******************* Static Varibles in Java ************************
Static variables, also known as class variables, are shared by all instances of a class. They are declared with the static keyword and are initialized only once when the class is loaded into memory. They are useful for storing common values or constants that are the same for all objects.
To better understand, consider the following example: */

#include <iostream>
using namespace std;

// Counter class
class Counter {
public:
    static int count; // static variable

    // Constructor
    Counter() {
        count++;
    }

    // Method to display count
    static void displayCount() {
        cout << "Count: " << count << endl;
    }
};

int Counter::count = 0; // Definition of static variable

// Main function
int main() {
    Counter c1;
    Counter c2;
    Counter::displayCount(); // Output: Count: 2
    return 0;
}

/* Here, the count variable is shared among all objects of the Counter class giving the output as 2 instead of 0.

/********************** Static Methods in Java ****************************
Static methods belong to the class rather than to any instance. They can be called without creating an object of the class. These methods are commonly used for utility or helper functions like mathematical calculations.
To better understand, consider the following example: */

#include <iostream>
using namespace std;

// Math Utility class
class MathUtils {
public:
    static int add(int a, int b) {
        return a + b;
    }
};

int main() {
    int result = MathUtils::add(5, 3); // Calling static method without object creation
    cout << "Result: " << result << endl; // Output: Result: 8
    return 0;
}

/* Here, the programwas able to call the add Utility function without creating an object (instance) of the class because it is a static method.

/****************** Keypoints: **********************
    *   Static methods cannot access non-static members (variables or methods) directly because non-static members require an instance of the class.
    *   Static methods can only directly call other static methods and access static variables.
    
/************* Static Blocks in Java ********************
Static blocks, also known as static initialization blocks, are used to initialize static variables. They are executed when the class is loaded into memory, before any objects are created or static methods are called.
Consider the following code snippet: */

#include <iostream>
using namespace std;

class Example {
public:
    static int value;

    // Static initialization block simulation
    struct StaticBlock {
        StaticBlock() {
            Example::value = 10; // Initialization of static variable
            cout << "Static block executed." << endl;
        }
    };
    static StaticBlock staticBlock;
};

int Example::value = 0;
Example::StaticBlock Example::staticBlock;

// Main function
int main() {
    cout << "Value: " << Example::value << endl; // Output: Static block executed. Value: 10
    return 0;
}

/* Static blocks are executed in the order they appear in the class.

/********************* Interaction Between Static and Non-Static Members ********************
Static methods cannot directly access or invoke non-static methods or variables because static methods do not depend on a class instance. However, non-static members can be accessed indirectly by creating an instance of the class. */

#include <bits/stdc++.h>
using namespace std;

class Example {
public:
    int instanceVar = 10;

    static void staticMethod() {
        Example obj; // Creating an instance to access non-static members
        cout << "Instance variable: " << obj.instanceVar << endl;
    }
};

int main() {
    Example::staticMethod();
    return 0;
}

/* In the above example, the static method staticMethod uses an object to access the non-static instanceVar.

/*************** Advantages of Static Members in Java *****************
There are several benefits of using Static members which are as follows:

    *   Memory Efficiency: Static variables are loaded into memory only once, reducing memory usage.
    *   Utility Functions: Static methods are ideal for utility or helper methods that do not require object-specific data (e.g., Math.sqrt()).
    *   Initialization: Static blocks allow for the initialization of static variables, ensuring that common resources are ready for use.

Consider the following code snippet: */

#include <bits/stdc++.h>
using namespace std;

// Utility Class
class Utils {
public:
    static void printMessage(string message) {
        cout << message << endl;
    }
};

int main() {
    Utils::printMessage("Hello, Static!"); // Output: Hello, Static!
    return 0;
}

/* As you can see, Static members simplify scenarios where sharing resources or creating reusable methods is required. */

/************* Practice (Static Keyword) *****************

You are required to design a class Counter to keep track of how many objects have been created from it. The tracking must be done using the static keyword to ensure a single shared variable across all instances of the class. The class should contain below specification :

/************* Attributes : ******************
count (Integer) : A static variable that tracks the total number of objects created.

/*************** Methods : ******************
A default constructor that increments the count variable each time a new object is instantiated.
/******** getCount() : A static method that returns the current value of the count variable.
/******** resetCount() : A static method to reset the value of count variable to 0.

Refer the sample examples for understanding the output format.
Refer the commented code on IDE for output statements

Example 1
Input : count = 10

Output :

Number of objects created : 10

Explanation :

Total count of objects that will be created is taken as input.
Then 'count' number of different objects are instantiated.
At each instantiation the constructor increments the count of object.
Now getCount method is called which returns the total number of objects instantiated.
At end we call the resentCount() method to resent the count to 0. */

// Your code goes here
class Counter {
private:
    static int count;
public:
    Counter() {
        count++;
       // cout<<"Number of objects created : "<<count<<endl;
    }
    static int getCount() {
        return count;
    }
    static void resetCount() {
        count = 0;
    }
};

int Counter::count = 0;
// Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your `Counter` class.

It creates objects of class `Counter`. The default constructor increments the `count` variable each time an object is created.
At the end, we simply call the `getCount` method to print the total number of objects instantiated.


// Main function to demonstrate the functionality of the Counter class
int main() {

    // Create an input stream to take input from the user
    int count;
    std::cin >> count;

    while (count-- > 0) {
        Counter obj; // Create Counter objects
    }

    std::cout << "Number of objects created : " << Counter::getCount() << std::endl;

    return 0;
}

*/





