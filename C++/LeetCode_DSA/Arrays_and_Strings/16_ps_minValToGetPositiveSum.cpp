// I didnt understand the question yet and need to focus later on
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int minSum = 0;
        for(int i = 0; i<nums.size();i++){
            sum += nums[i];
            minSum = min(minSum, sum);
        }
        if(minSum < 0) 
            return 1-minSum;
        return 1;
        
    }
};
