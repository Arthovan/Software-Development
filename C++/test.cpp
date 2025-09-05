// Program to find the repeated elements in the array of minumum value

#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;
int highestOccurence(vector<int>& num) {
    unordered_map<int,int> temp;
    int minVal = INT_MIN;
    int element = -1;

    for(int i = 0; i < num.size(); i++) {
        if(temp.find(num[i]) != temp.end()) {
            temp[num[i]]++;
            if(temp[num[i]] > minVal) {
                minVal = temp[num[i]];
                element = num[i];
            } else if((temp[num[i]] == minVal) and num[i] < element) {
                element = num[i];
            }
        } else {
            temp[num[i]] = 1;
        }
    }
    return element;
}
vector<int> countBits(int n) {
    vector<int> temp;
    int count = 0,val = 0;
    for(int i = 0; i <= n; i++){
        val = i;
        while(val > 0){
            if(val&1)
                count++;
            val = val >> 1;
        }
        temp.push_back(count);
        //cout<<"Count : "<<count<<endl;
        count = 0;
    }
    return temp;        
}
int main(int argc, char*argv[]){
    vector<int> nums = {1,2,3,3,4,4,2,5,6,7,5,5};
    //cout<<"MinVal : "<<highestOccurence(nums)<<endl;
    vector<int> temp = countBits(5);
    for(int val:temp){
        cout<<val<< " ";
    }
    cout<<endl;
    return 0;
}