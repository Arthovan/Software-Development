/********** Longest Band ************************
 * Given an array containing 'N' integers, find length of longest band.
 * A band is defined as a subsequence which can be reordered in such a manner all elements appear consecutive(ie with absolute difference of 1 between neighbouring elements).
 * A longest band is the band (subsequence) which contains maximum integers. */

 
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int longestBand(vector<int> arr) {
    int largest = 1;
    int size = arr.size();
    
    // we need to make sure to avoid duplicates to get the proper sequence so use unordered set
    unordered_set<int> set(arr.begin(),arr.end());
    /* I can use this below method too, to insert elements in the set
    for(auto val : arr){
        set.insert(val);
    }*/
    
    for(auto element:arr) {
        int parent = element - 1;
        if(set.find(parent) == set.end()) {
            int next_no = element + 1;
            int count = 1;
            while(set.find(next_no)!=set.end()) {
                next_no++;
                count++;
            }
            largest = max(largest,count);
        }
    }
    return largest;
}

int main(int argc, char *argv[]) {
    vector<int> arr{1,9,3,0,18,5,2,4,10,7,12,6};
    cout<<"Longest Band is : "<<longestBand(arr)<<endl;
    return 0;
}