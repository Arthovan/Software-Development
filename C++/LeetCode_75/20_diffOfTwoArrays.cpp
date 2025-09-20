/* 2215. Find the Difference of Two Arrays

Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.

Example 1:  Input: nums1 = [1,2,3], nums2 = [2,4,6]     
            Output: [[1,3],[4,6]]
            Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums1. Therefore, answer[1] = [4,6].

Example 2:  Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
            Output: [[3],[]]
            Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
*/

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    vector<int> num1,num2;
    for(auto val : set1) {
        if(set2.find(val) == set2.end()) {
            num1.push_back(val);
        }
    } 
    for(auto val : set2) {
        if(set1.find(val) == set1.end()) {
            num2.push_back(val);
        }
    }     

    return {num1,num2};
}

int main(int argc, char*argv[]) {
    vector<int> val1{1,2,3}, val2{2,4,6};
    vector<vector<int>> out = findDifference(val1,val2);
    
    for(auto val : out){
        for(auto i : val) {
            cout<<i<<" ";
        }
        cout<<endl;
    }        
    return 0;
}