// Program to find the repeated elements in the array of minumum value

#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;
int highestOccurence(vector<int>& num) {
    unordered_map<int,int> temp;
    int maxEleCount = 0, minEleCount = INT_MAX;

    for(int i = 0; i < num.size(); i++) {
        if(temp.find(num[i]) != temp.end()) {
            temp[num[i]]++;
        } 
        else {
            temp[num[i]] = 1;
        }
        if(temp[num[i]] > maxEleCount) {
            maxEleCount = temp[num[i]];
        } 
        else if(temp[num[i]] < minEleCount) {
            minEleCount = temp[num[i]];
        }
    }
    return maxEleCount + minEleCount;
}

int main(int argc, char*argv[]){
    vector<int> nums = {10,9,7,7,8,8,8};
    cout<<"MinVal : "<<highestOccurence(nums)<<endl;
    return 0;
}