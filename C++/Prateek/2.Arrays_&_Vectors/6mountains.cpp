/* Write a function that takes an array of distinct integers and returns the length of the longest mountain
    *   A mountain consists of consecutive elements that strictly increase up to a peak and then strictly decrease 
    *   At least 3 numbers are required to form a mountain */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mountain(vector<int> arr) {
    int largest = 0;
    int size = arr.size();
    
    for(int i = 1; i < size - 1;) { // first and last element never be a peak so only 'i' start at 1 and end before one element before last. Also we are incrementing 'i' below

        // check if arr[i] is peak or not
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            int cnt = 1;
            int j = i;

            // cnt backwards (left)
            while(j >= 1 && arr[j] > arr[j-1]) {
                j--;
                cnt++;
            }

            // cnt forwards (right)
            while(i < size-1 && arr[i] > arr[i+1]) {
                i++;
                cnt++;
            }
            largest = max(largest,cnt);
        } else {
            i++;
        }
    }
    return largest;
}

int main(int argc, char *argv[]) {
    vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout<<"Mountain Peak is : "<<mountain(arr)<<endl;

    return 0;
}