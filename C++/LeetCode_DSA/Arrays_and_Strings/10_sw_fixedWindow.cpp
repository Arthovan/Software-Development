/* Example 4: Given an integer array nums and an integer k, 
find the sum of the subarray with the largest sum whose length is k.
Time Complexity     :   O(n) 
Space Complexity    :   O(1)
*/
#include<iostream>
#include<vector>

using namespace std;

int fixedWindow(vector<int> arr, int K) {
    int i=0;
    int cSum = 0;
    int maxSum = 0;
    int len = arr.size();
    for(i = 0; i < K; i++)
        cSum += arr[i];
    maxSum = cSum;
    for(i = K; i < len; i++){
        cSum += arr[i];
        cSum -= arr[i-K]; 
        maxSum = max(maxSum,cSum);  
    }
    return maxSum;
}  

int main(){
    vector<int> arr{3,-1,4,12,-8,5,6};
    int k = 4;
    cout<<"Subarray largerst sum: "<<fixedWindow(arr,k)<<endl;
    return 0;    
}
