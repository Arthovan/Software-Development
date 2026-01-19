// C++ program to find 1's and 2's 
// complement of a binary number
#include <iostream>
#include <vector>
using namespace std;

// Function to find 1's complement
string onesComplement(string s) {
    
    // Traverse each bit and flip it
    for (char &c : s) {
        if (c == '0') {
            c = '1';
        } else {
            c = '0';
        }
    }
    
    return s;
}

// Function to find 2's complement
string twosComplement(string s) {
    
    // Get 1's complement of the binary number
    s = onesComplement(s); 
    int n = s.size();

    // Add 1 to the 1's complement
    for (int i = n - 1; i >= 0; i--) {
        
        // If we find '0', change it 
        // to '1' and stop
        if (s[i] == '0') {
            s[i] = '1';
            break;
        } 
        
        // If we find '1', change it 
        // to '0' and continue
        else {
            s[i] = '0';
        }
    }
    /*
    // If all bits were flipped, we need
    // to add an extra '1'
    // at the beginning to maintain 
    // correct two's complement
    if (s[0] == '0') {
        s = '1' + s;
    }
    */
    return s;
}

// Function to compute both 1's and 2's complements 
vector<string> findComplement(string s) {
    
    // Compute 1's complement
    string ones = onesComplement(s);
    
    // Compute 2's complement
    string twos = twosComplement(s);

    return {ones, twos};
}

// Driver code
int main() {
    
    string s = "1001";

    vector<string> result = findComplement(s);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}