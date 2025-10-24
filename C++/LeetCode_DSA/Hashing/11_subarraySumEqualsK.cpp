/* Example 4: 560. Subarray Sum Equals K
Given an integer array nums and an integer k, find the number of subarrays whose sum is equal to k.
*/

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int subarraySum(vector<int> ele, int k) {
    unordered_map<int,int> temp;
    temp[0] = 1;                //  subarray - k may get the answer as 0. That instance we need to store by default.Ex subarray is 3 and k is 3 so 3-3 = 0
    int ans = 0, curr = 0;
    for(int num : ele){
        curr += num;
        ans += temp[curr -k];       //  here now it is temp[1-3]=>temp[-2] so there is no -2 indices so this wont do anything only the ans is updated with ans = ans + 0;
        temp[curr]++;
    }
    cout<<endl;
    return ans;
}

int main(){
    vector<int> val{1,2,1,2,1};
    int k = 3;
    cout<<"Subarray Sum : "<<subarraySum(val,k)<<endl;
    return 0;

}
