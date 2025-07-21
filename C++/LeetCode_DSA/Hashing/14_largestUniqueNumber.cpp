#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;
int maxfun(int a, int b){
    return a > b? a:b;
}
int largestUniqueNumber(vector<int>& nums) {
    unordered_map<int,int> ans;
    for(auto ele : nums){
        ans[ele]++;            
    }

    int maxValue = -1;
    for(auto [key, value]:ans){
        if(value == 1){
            maxValue = maxfun(maxValue,key);    //Instead of using library function "max" am using own funciton
        }    
    }
        
    return maxValue;
}

int main(){
    vector<int> val{5,7,3,9,4,9,8,3,1};
    cout<<"Largest Unique Number is : "<<largestUniqueNumber(val)<<endl;
    return 0;
}
