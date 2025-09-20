/////////////////////////////////////////////////
/*  739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
Example 1:  Input: temperatures = [73,74,75,71,69,72,76,73]
            Output: [1,1,4,2,1,1,0,0]
Example 2:  Input: temperatures = [30,40,50,60]
            Output: [1,1,1,0]
Example 3:  Input: temperatures = [30,60,90]
            Output: [1,1,0]
*/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> stack;
    vector<int> result(temperatures.size());
    int count = 0;
    for(int i = 0; i < temperatures.size(); i++) {
        while(!stack.empty() and temperatures[stack.top()] < temperatures[i]) {
            int j = stack.top();
            result[j] = i - j;
            stack.pop();
        }
        stack.push(i);                 
    }
    return result;
}

int main(int argc, char*argv[]) {
    vector<int> temp{73,74,75,71,69,72,76,73};
    vector<int> output = dailyTemperatures(temp);
    cout<<"Days to get high tempertaures are : ";
    for(auto val : output) {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
///////////////////////////////////////////