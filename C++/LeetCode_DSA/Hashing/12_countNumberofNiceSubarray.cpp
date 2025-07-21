/* Example 5: 1248. Count Number of Nice Subarrays
Given an array of positive integers nums and an integer k. Find the number of subarrays with exactly k odd numbers in them.
For example, given nums = [1, 1, 2, 1, 1], k = 3, the answer is 2. The subarrays with 3 odd numbers in them are [1, 1, 2, 1, 1] and [1, 1, 2, 1, 1].
*/

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int numberOfSubarrays(vector<int> ele, int k) {
    unordered_map<int,int> temp;
    temp[0] = 1;                    //  subarray initial value is 0:1 , it means the sum - k = 0 that instance we need to store by default
    int ans = 0, curr = 0;
    for(int num : ele){
        curr += num%2;
        ans += temp[curr -k];       //  here now it is temp[1-3]=>temp[-2] so there is no -2 indices so this wont do anything only the ans is updated with ans = ans + 0;
        temp[curr]++;
    }
    cout<<endl;
    return ans;
}

int main(){
    vector<int> val{1,1,2,1,1};
    int k = 3;
    cout<<"Subarray Sum : "<<numberOfSubarrays(val,k)<<endl;
    return 0;

}
