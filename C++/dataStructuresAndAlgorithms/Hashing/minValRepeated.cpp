// Program to find the repeated elements in the array of minumum value

#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;
int highestOccurence(vector<int>& num) {
    unordered_map<int,int> temp;
    int maxCount = INT_MIN;
    int element = -1;

    for(int i = 0; i < num.size(); i++) {
        if(temp.find(num[i]) != temp.end()) {
            temp[num[i]]++;
            if(temp[num[i]] > maxCount) {
                maxCount = temp[num[i]];
                element = num[i];
            } else if((temp[num[i]] == maxCount) and num[i] < element) {
                element = num[i];
            }
        } else {
            temp[num[i]] = 1;
        }
    }
    return element;
}

int main(int argc, char*argv[]){
    vector<int> nums = {1,2,3,3,4,4,2,5,6,7,5,5};
    cout<<"MinVal : "<<highestOccurence(nums)<<endl;
    return 0;
}