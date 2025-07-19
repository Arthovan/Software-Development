/* You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.
Return a list answer of size 2 where:
answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:       You should only consider the players that have played at least one match.
        The testcases will be generated such that no two matches will have the same outcome.

Example 1:  Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
            Output: [[1,2,10],[4,5,7,8]]
            Explanation:    Players 1, 2, and 10 have not lost any matches.
                            Players 4, 5, 7, and 8 each have lost one match.
                            Players 3, 6, and 9 each have lost two matches.
                            Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].

Example 2:  Input: matches = [[2,3],[1,3],[5,4],[6,4]]
            Output: [[1,2,5,6],[]]
            Explanation:    Players 1, 2, 5, and 6 have not lost any matches.
                            Players 3 and 4 each have lost two matches.
                            Thus, answer[0] = [1,2,5,6] and answer[1] = [].

Constraints:    1 <= matches.length <= 105
                matches[i].length == 2
                1 <= winneri, loseri <= 105
                winneri != loseri
                All matches[i] are unique.
*/

#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    unordered_set<int> zeroLoss, oneLoss, moreLoss;
    vector<vector<int>> ans(2, vector<int>());  // Need to add two one dimensional array for winners and losers
    for(auto ele : matches){
        int winner = ele[0], loser = ele[1];
        // Add winner
        if((moreLoss.find(winner) == moreLoss.end()) && oneLoss.find(winner) == oneLoss.end()){
            zeroLoss.insert(winner);
        }

        //Add or move loser
        if(zeroLoss.find(loser) != zeroLoss.end()){
            zeroLoss.erase(loser);
            oneLoss.insert(loser);
        }
        else if(oneLoss.find(loser) != oneLoss.end()){
            oneLoss.erase(loser);
            moreLoss.insert(loser);
        }
        else if(moreLoss.find(loser) != moreLoss.end()){
            continue;
        }
        else{
            oneLoss.insert(loser);  // This case is for first time when we have loser in first element itself. So this loser wont be in any set 
        }
    }

    ans[0].assign(zeroLoss.begin(),zeroLoss.end());
    ans[1].assign(oneLoss.begin(),oneLoss.end());
    sort(ans[0].begin(),ans[0].end());
    sort(ans[1].begin(),ans[1].end());

    return ans;
}

int main() {
    vector<vector<int>> val{{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    
    vector<vector<int>> temp = findWinners(val);
    for(vector<int> out : temp){
        for(int ele : out)
            cout<<ele<<" ";
        cout<<endl;
    }
    return 0;
}
   
   
   
