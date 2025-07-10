/* Example 2: Given a sorted array of unique integers and a target integer, return true if there exists a pair of numbers that sum to target, false otherwise. This problem is similar to Two Sum. (In Two Sum, the input is not sorted).
For example, given nums = [1, 2, 4, 6, 8, 9, 14, 15] and target = 13, return true because 4 + 9 = 13.
Note: a similar version of this problem can be found on LeetCode: 167. Two Sum II - Input Array Is Sorted.
    Time Complexity : O(n)
    Space Complexity : O(1)
*/
#include<iostream>
#include<vector>

using namespace std;
bool sortedArrayTarget(vector<int> arr, int tar){
    int cSum = 0;
    int i=0,j=arr.size()-1;
    while(i<j){
        cSum = arr[i] + arr[j];
        if(cSum == tar)
            return true;
        else if(cSum > tar)
            j--;
        else
            i++;
    }
    return false;
}

int main(){
    vector<int> arr{1,2,3,4,5,6,7};
    int K = 11;
    bool val = 0;
    val = sortedArrayTarget(arr, K);
    val == 1 ? cout<<"Target is found"<<endl : cout<<"Target is not found"<<endl;
    return 0;
}
