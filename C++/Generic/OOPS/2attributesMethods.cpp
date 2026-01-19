/**************** Attributes and Methods *************************

///// Attributes:
Attributes (also called properties or fields) are the data or characteristics of an object. They represent the state of the object at any given moment. Attributes are typically defined within a class and can hold different types of information related to the object.

For example: We wish to create two data fields for our BankAccount class:
    *   Name: to store the name of the account holder. The String data-type would be best suited for it.
    *   Balance: to store the account balance. The double data-type would be the perfect fit for this.

Since the attribute, balance is a personal information of account holder, in the real world scenario, these things will be hidden from the outside world, i.e, no user will be able to check the account balance of a different user. To handle such cases, the balance attribute must be declared with the access-modifier set to private.

///// Methods:
Methods are functions that are defined inside a class and represent the behavior or actions that an object of the class can perform. Methods define what an object can do, and they often operate on the attributes (or fields) of the class. Every object of a class can call the methods of the class to perform specific tasks.

For example: In a BankAccount class, there are different functions that are provided to the user:
    *   Check Balance: The user can check the account balance.
    *   Deposit: The user can make a deposit of a certain amount.
    *   Withdraw: The user can withdraw money from his/her bank account.


Consider the following class implementing the BankAccount in real-world: */

#include <bits/stdc++.h>
using namespace std;

class BankAccount {
private:
    string name; // to store the name of account holder
    double balance; // to store the balance

public:
    // Constructor
    BankAccount(string name, double balance) {
        this->name = name;
        this->balance = balance;
    }

    // Method to set the name
    void setName(string name) {
        this->name = name;
    }

    // Method to get the name
    string getName() {
        return name;
    }

    // Method to get the balance
    double getBalance() {
        return balance;
    }

    // Method to make a deposit
    void deposit(double amount) {
        balance += amount; // Update the balance
    }

    // Method to make a withdrawal
    bool withdrawal(double amount) {
        if (amount >= balance) {
            cout << "Insufficient amount" << endl;
            return false;
        }
        balance -= amount; // Update the balance
        return true;
    }
};

/******************** Understanding the Interaction Between Attributes and Methods ********************
In a class implementing a real-world scenarios, the attributes and methods interact with each other constantly. Methods allow controlled access to the attributes. In many cases, attributes are marked as private to restrict direct access from outside the class, promoting encapsulation. Methods then provide a controlled way of interacting with those attributes.

For example: The balance attribute was set as private in the BankAccount class.

Now, in order to get the balance there must be some method implemented that can access the private attribute. This brings the two major methods used in real-world OOP projects:

    *   Setters: A method to set the value of a particular attribute say setName().
    *   Getters: A method to get or retrieve the value of a particular attribute say getName().

These methods are necessary because they provide the user to access the private data attributes which otherwise cannot be accessed directly from the object.

///// Important Points
There are some important points that must be taken care of while implementing real-world entities using Object-oriented programming:
    *   Accessing Attributes: Use methods (getters and setters) to access private attributes. Example, getBalance() retrieves the current balance.
    *   Encapsulation: Keep attributes private and provide controlled access using public methods to ensure data integrity.
    *   Default Values: Attributes have default values if not explicitly initialized (e.g., 0 for numeric types, null for objects in Java).
    *   Method Parameters: Methods can take parameters to modify attributes (e.g., deposit(double amount)).
    *   Error Handling: Ensure methods validate inputs (e.g., disallow negative deposits or withdrawals exceeding balance). */