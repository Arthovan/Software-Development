/* Example 3: Given an integer array nums, find all the numbers x in nums that satisfy the following: x + 1 is not in nums, and x - 1 is not in nums.
If a valid number x appears multiple times, you only need to include it in the answer once.
We can solve this in a straightforward manner - just iterate through nums and check if x + 1 or x - 1 
is in nums. By converting nums into a set beforehand, these checks will cost O(1).
*/

#include<iostream>
#include<unordered_set>
#include<cstring>
#include<vector>

using namespace std;

vector<int> findNumbers(vector<int> &nums) {
    vector<int> ans;
    unordered_set<char> temp(nums.begin(),nums.end());

    for(int ne:temp){
        if(!(temp.find(ne+1) != temp.end())  && !(temp.find(ne-1) != temp.end())){
            ans.push_back(ne);
        }
    }
    return ans;        
}

int main(){
    vector<int> num = {1,2,4,1,8,12,15};     
    vector<int> temp = findNumbers(num);
    for(int st:temp)
        cout<<st<<",";
    cout<<endl;
    return 0;
}
