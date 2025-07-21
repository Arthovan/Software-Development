class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        
        int len = nums.size();
        vector<int> temp(len,-1);
        int windowSize = 2*k+1;
        vector<long long> preSum(len+1);
        
        if( k == 0){
            return nums;
        }
        if(k > len){
            return temp;
        }
    // here we didnt calculate the presum[0], but still this program works need to dive deep in future
        for(int i = 0;i < len; i++){
            preSum[i+1]= preSum[i]+nums[i];    
        }
        
        for(int i = k; i < len-k; i++){
            temp[i]=((preSum[i+k+1]-preSum[i-k])/windowSize);
        }
        return temp;
    }
};
