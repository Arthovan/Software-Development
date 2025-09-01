// Program to find the repeated elements in the array of minumum value

#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;
int highestOccurence(vector<int>& num) {
    unordered_map<int,int> temp;
    int maxEle = -1, maxEleCount = 0;
    int secondMaxEle = -1, secondMaxEleCount = 0;

    for(int i = 0; i < num.size(); i++) {
        if(temp.find(num[i]) != temp.end()) {
            temp[num[i]]++;
        } 
        else {
            temp[num[i]] = 1;
        }
        if(temp[num[i]] > maxEleCount) {
            secondMaxEle = maxEle;
            secondMaxEleCount = maxEleCount;
            maxEleCount = temp[num[i]];
            maxEle = num[i];
        } 
        else if(temp[num[i]] > secondMaxEleCount) {
            secondMaxEleCount = temp[num[i]];
            secondMaxEle = num[i];
        }
        else if(temp[num[i]] == maxEleCount and num[i] < maxEle){
            maxEle = num[i];
        }
        else if(temp[num[i]] == secondMaxEleCount and num[i] < secondMaxEle){
            secondMaxEle = num[i];
        }
    }
    return secondMaxEle;
}

int main(int argc, char*argv[]){
    vector<int> nums = {1,2,3,3,4,4,2,5,6,7,5,5};
    cout<<"MinVal : "<<highestOccurence(nums)<<endl;
    return 0;
}