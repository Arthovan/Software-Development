/************* Encapsulation (Data Hiding) **********************

Encapsulation is a fundamental concept in object-oriented programming (OOP) where the internal details (data and logic) of an object are hidden from the outside world. It is the process of bundling the object's data (attributes) and methods (functions) together into a single unit or class. The primary goal is to protect the internal state of an object from unintended modifications and provide controlled access to it.

In simple terms, encapsulation ensures that the object's internal workings are hidden from other objects, allowing external entities to interact with the object only through well-defined interfaces (methods).

///// Key Concept:
Encapsulation enforces data hiding and ensures that attributes (variables) within a class are not directly accessible to other classes or external code. Instead, it provides getter and setter methods to access and modify these private attributes. By making attributes private, encapsulation maintains control over how the data is accessed and modified, preventing unwanted changes or access.

///// For example:
    *   Private attributes (fields) ensure that no one can directly alter the object's state.
    *   Public getter and setter methods allow controlled access and modification of private attributes, enabling additional business logic or validation during the process.
    
///// Importance of Encapsulation
There are several benefits of using Encapsulation which are as follows:

    *   Data Security: The most significant benefit is data protection. Sensitive data can be hidden from external manipulation and can only be accessed or modified in a controlled manner.
    *   Flexibility and Maintenance: If the internal implementation needs to change, encapsulation allows you to modify the code without affecting external code. You can alter the internal representation of the data or how it's accessed, as long as the public interface (methods) remains the same.
    *   Modular Code: Encapsulation promotes cleaner, modular code by bundling related data and behaviors together. It helps in organizing the code, making it more readable and maintainable.
    *   Improved Debugging and Testing: Since all access to an object's internal state is controlled, debugging and testing become easier. You can validate the behavior of methods (like getters and setters) independently.
    *   Reduced Complexity: By hiding complex internal implementations and exposing only what is necessary, encapsulation simplifies the usage of objects and reduces the chances of errors in using the class.
    
///// Example:
Consider the following code snippet: */

#include <bits/stdc++.h>
using namespace std;

class BankAccount {
private:
    string accountHolderName; // Private attributes
    double balance;

public:
    // Constructor
    BankAccount(string accountHolderName, double balance) {
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    // Public getter for accountHolderName
    string getAccountHolderName() {
        return accountHolderName;
    }

    // Public setter for accountHolderName
    void setAccountHolderName(string accountHolderName) {
        this->accountHolderName = accountHolderName;
    }

    // Public getter for balance
    double getBalance() {
        return balance;
    }

    // Public setter for balance (only allows positive deposits)
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    // Public method to withdraw money
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            balance -= amount;
        }
    }
};

class Main {
public:
    static void main() {
        // Creating an object of BankAccount
        BankAccount account("John Doe", 5000);

        // Using getter to access private data
        cout << "Account Holder: " << account.getAccountHolderName() << endl;
        cout << "Balance: " << account.getBalance() << endl;

        // Modifying balance using setter method
        account.deposit(1500);
        cout << "Updated Balance: " << account.getBalance() << endl;

        // Trying to withdraw an amount
        account.withdraw(2000);
        cout << "Balance after Withdrawal: " << account.getBalance() << endl;
    }
};

int main() {
    Main::main();
    return 0;
}

/************* Key Takeaways: ***************
    *   Private Data: In the example above, the accountHolderName and balance attributes are private. This restricts direct access to the attributes from outside the class.
    *   Getter and Setter Methods: The getBalance() and deposit() methods are public and act as controlled interfaces to interact with the private data.
    *   Controlled Access: The deposit() method includes a check to ensure that only positive amounts are added to the balance, maintaining data integrity.

By encapsulating the BankAccount class, we make sure that the balance cannot be arbitrarily altered from outside the class, which protects it from unintended modifications and ensures proper validation is performed. */