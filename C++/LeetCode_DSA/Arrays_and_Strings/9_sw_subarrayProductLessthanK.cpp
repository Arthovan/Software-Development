/* Example 3: 713. Subarray Product Less Than K.
Given an array of positive integers nums and an integer k, return the number of subarrays where the product of all the elements in the subarray is strictly less than k.
For example, given the input nums = [10, 5, 2, 6], k = 100, the answer is 8. The subarrays with products less than k are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Time Complexity     :   O(n) 
Space Complexity    :   O(1)
*/
#include<iostream>
#include<vector>

using namespace std;

int subarrayProduct(vector<int> arr, int K) {
    int right = 0, left = 0;
    int cSum = 1;
    int ans = 0;
    int len = arr.size();
    if(K <= 1)
        return 0;

    for(right = 0; right < len; right++){
        cSum *= arr[right];

        while(cSum >= K){
            cSum = cSum / arr[left]; // As we did multiplication, inorder to remove that we need to do division here
            left++;
        }  
        ans += right-left+1;  
    }
    return ans;
}  

int main(){
    vector<int> arr{10,5,2,6};
    int k = 100;
    cout<<"Subarray product less than K is : "<<subarrayProduct(arr,k)<<endl;
    return 0;    
}
