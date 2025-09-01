/* Example 2: 2260. Minimum Consecutive Cards to Pick Up
Given an integer array cards, find the length of the shortest subarray that contains at least one duplicate. If the array has no duplicates, return -1. */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int mimimumCardPickup(vector<int>& val) {
    unordered_map<int,int> dice;
    int ans = INT_MAX;

    for(int i = 0; i < val.size(); i++){
        if(dice.find(val[i]) != dice.end()) {
            // i is the current index, dice[val[i]] is previous index, just like right - left + 1 in sliding window
            ans = min(ans, i - dice[val[i]] + 1); 
        }
        dice[val[i]] = i; // storing the card value with their respective indices
    }
    return ans == INT_MAX ? -1 : ans;
}

int main(int argc, char*argv[]) {
    vector<int> cards = {1,2,6,2,1};
    cout<<" Minumum Card to Pickup is : "<<mimimumCardPickup(cards)<<endl;
    return 0;
}