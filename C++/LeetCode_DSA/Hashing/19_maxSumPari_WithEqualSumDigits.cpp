#include <iostream>
#include <vector>

using namespace std;

int maximumSum(vector<int>& nums) {
    vector<int> temp;
    int val = 0, mod = 0, tval = 0 ;
    for(int i = 0; i < nums.size(); i++) {
        val = nums[i];
        while(val) {
            tval = val % 10;
            mod += tval;
            val /= 10;
        }
        temp.push_back(mod);
        //cout<<mod<<" ";
        mod = 0;
    }
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i+1; j < nums.size(); j++) {
            if(temp[i] == temp[j]){
                return nums[i] + nums[j];
            }
        }
    }
    return -1;
}

int main(int argc, char*argv[]) {
    vector<int> nums = {18,43,36,13,7};
    cout<<"Maximum Sum is : "<<maximumSum(nums)<<endl;
    return 0;
}