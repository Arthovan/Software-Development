// Need to resolve this error
#include <iostream>
#include <vector>
using namespace std;

// Recursive function to flatten an N-dimensional array
template<typename T>
void flatten(const vector<T>& array, vector<typename T::type_name>& result) {
    for (const auto& element : array) {
        flatten(element, result);
    }
}

// Base case for recursion: when the element is not a vector, add it to the result
template<typename T>
void flatten(T element, vector<T>& result) {
    result.push_back(element);
}

int main() {
    // Example of a 3-dimensional array
    vector<vector<vector<int>>> nDimArray = {
        {{1, 2, 3}, {4, 5, 6}},
        {{7, 8, 9}, {10, 11, 12}}
    };

    // Result vector to store the flattened array
    vector<int> flattenedArray;

    // Flatten the N-dimensional array
    flatten(nDimArray, flattenedArray);

    // Print the flattened array
    cout << "Flattened array: ";
    for (const auto& element : flattenedArray) {
        cout << element << " ";
    }
    cout << std::endl;

    return 0;
}
