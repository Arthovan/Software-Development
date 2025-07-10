/* Example 1: Given an integer array nums, an array queries where queries[i] = [x, y] 
and an integer limit, return a boolean array that represents the answer to each query. 
A query is true if the sum of the subarray from x to y is less than limit, or false otherwise.
For example, given nums = [1, 6, 3, 2, 7, 2], queries = [[0, 3], [2, 5], [2, 4]], and limit = 13, the answer is [true, false, true]. For each query, the subarray sums are [12, 14, 12]
*/

#include<iostream>
#include<vector>

using namespace std;

vector<bool> subarraySum(vector<int> arr, vector<vector<int>> queries, int limit){
    vector<int> preSum = {arr[0]};
    for(int i = 1;i < arr.size();i++){
        preSum.push_back(preSum.back()+arr[i]);
    }
    cout<<"preSum : ";
    for(int ch : preSum)
        cout<<ch<<",";
    cout<<endl;

    vector<bool> ans;
    for(vector<int> query : queries){
        int x = query[0], y = query[1];
        // as we need only subarray with just minus operation between 2 indices 
        // will give only the difference which inturn discards the first value 
        // so we are adding the first value again
        int curr = preSum[y] - preSum[x] + arr[x]; 
        cout<<" Curr: "<<curr;
        ans.push_back(curr < limit);
    }
    cout<<endl;
    return ans;
}
int main(){
    vector<int> arr{1,6,3,2,7,2};
    vector<vector<int>> queries={{0,3},{2,5},{2,4}};
    int limit = 13;
    vector<bool> temp =  subarraySum(arr,queries,limit);
    for(bool ch : temp)
        cout<<ch<<",";
    cout<<endl;
    return 0;
}
