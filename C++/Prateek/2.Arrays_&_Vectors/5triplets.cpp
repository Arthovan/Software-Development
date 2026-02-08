/* Given an array containing 'N' integers, and an number 'S' denoting a target sum.

Find all distinct integerts that can add up to form target sum. The numbers in each triplet should be ordered in ascending order, and triplets should be ordered too. 

Return empty array if no such triplet exists. */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> triplets(vector<int> arr, int target) {
    vector<vector<int>>out;
    sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); ++i) {
        int j = i + 1;
        int k = arr.size() - 1;
        while(j < k) {
            int currentSum = arr[i];
            currentSum += arr[j];
            currentSum += arr[k];

            if(currentSum == target) {
                out.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;
            }
            else if(currentSum > target) {
                k--;
            }
            else {
                j++;
            }
        }
    }
    return out;
}

int main(int argc, char *argv[]) {
    vector<int> arr{1,2,3,4,5,6,7,8,9,15};
    int S = 18;

    auto result = triplets(arr,S);

    for(auto v : result){
        for(auto tem:v){
            cout<<tem<<",";
        }
        cout<<endl;
    }
    return 0;
}