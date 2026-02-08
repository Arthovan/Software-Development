/********* Largest Element *******************
Implement a function that takes vector of integers as input and returns the largest element.

Sample Input

-3 4 1 2 3

-1 -2 -3 -3 8

Sample Output

4

8

Explanation : for test case one, 4 is the largest integer in the array.

Similarly for test case two, 8 is the largest integer in the array. */

#include <iostream>
#include <vector>
using namespace std;

int largestElement(vector<int> arr) {
    int maxval = INT32_MIN;
    for(auto val: arr) {
        maxval = max(maxval, val);
    }
    return maxval;
}

int main(int argc, char *argv[]) {
    vector<int> arr = {-3,4,1,2,3};
    cout<<"Max value is : "<<largestElement(arr)<<endl;
    return 0;
}