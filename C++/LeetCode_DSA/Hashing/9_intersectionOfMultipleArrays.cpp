/* Example 2: 2248. Intersection of Multiple Arrays
Given a 2D array nums that contains n arrays of distinct integers, return a sorted array
containing all the numbers that appear in all n arrays.
For example, given nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]], return [3, 4]. 3 and 4 are the 
only numbers that are in all arrays.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<int> intersection(vector<vector<int>> a){
    unordered_map<int, int> temp; 
    for(vector<int> val : a){
        for(int elements : val)
            temp[elements]++;
    }

    int size = int(a.size());
    vector<int> ans;
    for(auto [key, value] : temp){
        if(value == size){
            ans.push_back(key);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<vector<int>> arr = {{3,1,2,4,5},{1,2,3,4},{3,4,5,6}};
    vector<int>temp = intersection(arr);
    cout<<"Common value is : ";
    for(int val : temp)
        cout<<val<<" ";
    cout<<endl;
    return 0;
}
