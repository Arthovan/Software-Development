/* 239. Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:  Input: nums = [1,3,-1,-3,5,3,6,7], k = 3    Output: [3,3,5,5,6,7]
Explanation:    Window position                Max
                ---------------               -----
                [1  3  -1] -3  5  3  6  7       3
                1 [3  -1  -3] 5  3  6  7       3
                1  3 [-1  -3  5] 3  6  7       5
                1  3  -1 [-3  5  3] 6  7       5
                1  3  -1  -3 [5  3  6] 7       6
                1  3  -1  -3  5 [3  6  7]      7
Example 2:  Input: nums = [1], k = 1    Output: [1]     */

// Even though I understand this problem and its some what difficult 
// so need some time to prepare in future as it is monotonic concept related problem in stack and queue

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> output;
    deque<int> queue;

    for(int i = 0; i < nums.size(); i++){
        while(!queue.empty() and nums[i] > nums[queue.back()]) {
            queue.pop_back();
        }
        queue.push_back(i);

        // first element indices is greater then window size (which is k) so we are removing it from window. Ex: front is 0 
        // and k is 3 ==> 0 + 3  = 3 and i is 3 which is 4th index and greater then K so we need to remove the front  
        if(queue.front() + k == i) {
            queue.pop_front();
        }
        
        // here we are stroing the largest element in the current window, if i is > k then we need to store that window max in output vector
        if(i >= k - 1){
            output.push_back(nums[queue.front()]);
        }
    }
    return output;       
}

int main(int argc, char*argv[]) {
    vector<int> val{1,3,-1,-3,5,3,6,7};
    vector<int> out = maxSlidingWindow(val, 3);
    for(auto ele : out) {
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
/////////////////////////////////////////