#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(int argc, char*argv[]){
    // Declaration: C++ supports multiple implementations, but we will be using
    // std::stack. Specify the data type
    stack<int> stack;

    // Pushing elements:
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // Popping elements:
    // Note, unlike other languages, popping here does not return the popped value
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;

    // Check if empty
    stack.empty()==0?cout<<"Stack is Not Empty"<<endl:cout<<"Stack is Empty"<<endl; // false

    // Check element at top
    cout<<"Stack top value is : "<<stack.top()<<endl; // 1

    // Get size
    cout<<"Stack size is : "<<stack.size()<<endl; // 1
    return 0;
}
///////////////////////////////////////////////////
/*  346. Moving Average from Data Stream
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:
MovingAverage(int size) Initializes the object with the size of the window size.
double next(int val) Returns the moving average of the last size values of the stream.

Example 1:  Input   ["MovingAverage", "next", "next", "next", "next"]
                    [[3], [1], [10], [3], [5]]
            Output  [null, 1.0, 5.5, 4.66667, 6.0]
Explanation:
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // return 1.0 = 1 / 1
movingAverage.next(10); // return 5.5 = (1 + 10) / 2
movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3
*/

#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

class MovingAverage {
    private:
        int windowSize = 0;
        vector<int> queue;
    public:
        MovingAverage(int size) {
            this->windowSize = size;
        }
        double next(int val) {
            queue.push_back(val);
            int windowSum = 0;
            // Reason for this below method of for loop is we need to always provide a windowSum upto the windowSize, just like sliding window.
            // if windowSize = 3 and queue size is 1 which results in in i = max( 0, 1-3). so i will be 0 until queue size more than 3 which inturn act as sliding window here
            for(int i = max(0, (int)queue.size()-windowSize); i < queue.size(); i++){
                windowSum += queue[i];
            }
            
            // we need to return the average of the number of elements in queue until windowSize so we use min of queue size and windowSize
            return (windowSum * 1.0) / min((int)queue.size(), windowSize);
        }
};

int main(int argc, char*argv[]) {
    MovingAverage obj(3);
    cout<<"val: "<<obj.next(4)<<endl;
    return 0;
}
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
/* 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

Example 1:  Input: nums = [8,2,4,7], limit = 4          Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.

Example 2:  Input: nums = [10,1,2,4,7,2], limit = 5     Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

Example 3:  Input: nums = [4,2,2,2,4,4,2,2], limit = 0  Output: 3  */

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int longestSubarray(vector<int>& nums, int limit) {
    deque<int> increasing;
    deque<int> decreasing;
    int left = 0, ans = 0;
    for(int right = 0; right < nums.size(); right++) {
        while(!increasing.empty() and increasing.back() > nums[right]) {
            increasing.pop_back();
        }

        while(!decreasing.empty() and decreasing.back() < nums[right]) {
            decreasing.pop_back();
        }

        increasing.push_back(nums[right]);
        decreasing.push_back(nums[right]);

        while(decreasing.front() - increasing.front() > limit) {
            if(nums[left] == decreasing.front()) { 
                decreasing.pop_front();
            }
            if(nums[left] == increasing.front()) {
                increasing.pop_front();
            }
            left++;
        }
        ans = max(ans, right-left+1);
    }
    
    return ans;
}

int main(int argc, char*argv[]) {
    vector<int> val{4,2,2,2,4,4,2,2};
    int limit = 0;
    cout<<"Longest Continuous Subarray with Absolute Difference Less than or Equal to Limit is : "<<longestSubarray(val, limit)<<endl;
    return 0;
}
/////////////////////////////////////////
/*  496. Next Greater Element I
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
/*  496. Next Greater Element I
    The next greater element of some element x in an array is the first greater element that is to the right of x in the same array. You are given two distinct 0-indexed integer 
    arrays nums1 and nums2, where nums1 is a subset of nums2. For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater 
    element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1. Return an array ans of length nums1.length such that ans[i] is the next 
    greater element as described above. 

Example 1:  Input: nums1 = [4,1,2], nums2 = [1,3,4,2]   Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
    - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
    - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
    - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

Example 2:  Input: nums1 = [2,4], nums2 = [1,2,3,4]     Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
    - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
    - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.  */
    
#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack <int> stack;
    unordered_map <int,int> hashMap;
    vector <int> ans;
    
    for(auto num : nums2) {
        while(!stack.empty() and num > stack.top()) {
            hashMap[stack.top()] = num;
            stack.pop();
        }
        stack.push(num);
    }
    
    while(!stack.empty()) {
        hashMap[stack.top()] = -1;
        stack.pop();
    }
    
    for(auto num : nums1) {
        ans.push_back(hashMap[num]); 
    }
    
    return ans;
}

int main(int argc, char* argv[]) {
    vector<int> nums1{4,1,2}, nums2{1,3,4,2};
    vector<int> output = nextGreaterElement(nums1,nums2);

    cout<<"Next Greater Element is : ";
    for(auto val : output) {
        cout<<val<<" "; 
    }
    cout<<endl;    
    return 0;
}
////////////////////////////////////
/* 901. Online Stock Span
    Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day. The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.
        *   For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
        *   Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.

    Implement the StockSpanner class:
        *   StockSpanner() Initializes the object of the class.
        *   int next(int price) Returns the span of the stock's price given that today's price is price.
 
Example 1:

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6         */

class StockSpanner {
public:
    stack<pair<int,int>> stack;
    int next(int price) {
        int ans = 1;
        while(!stack.empty() && stack.top().first <= price) {
            ans += stack.top().second;
            stack.pop();
        }

        stack.push({price,ans});
        return ans;
    }
};
////////////////////////////////////////////////////////
/*  2390. Removing Stars From a String

You are given a string s, which contains stars *.

In one operation, you can:
    *   Choose a star in s.
    *   Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:
    *   The input will be generated such that the operation is always possible.
    *   It can be shown that the resulting string will always be unique.
 
Example 1:
Input: s = "leet**cod*e"    Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".

Example 2:
Input: s = "erase*****"     Output: ""
Explanation: The entire string is removed, so we return an empty string.    */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

string removeStars(string s) {
    stack <char> stack;
    string temp = "";
    for(auto val : s) {
        if(!stack.empty() and val == '*') {
            stack.pop();
        } else {
            stack.push(val);
        }
    }
    while(!stack.empty()) {
        temp += stack.top();
        stack.pop();
    }
    reverse(temp.begin(),temp.end());
    return temp;
}

int main(int argc, char* argv[]) {
    string str{"leet**cod*e"};
    cout<<"After * is removed from string, the output is : "<<removeStars(str)<<endl;
    return 0;
}

class MyQueue {
public:
    stack<int>st;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int>temp;
        while(!st.empty())
        {
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        return;
    }
    
    int pop() {
        if(empty())
        return -1;

        int val = st.top();
        st.pop();
        return val;
    }
    
    int peek() {
        if(empty())
        return -1;

        int val = st.top();
        return val;
    }
    
    bool empty() {
        if(st.size() == 0)
        return true;

        return false;  
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
//////////////////////////////////////////
/*  232. Implement Queue using Stacks   -   Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all 
the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:
    *   void push(int x) Pushes element x to the back of the queue.
    *   int pop() Removes the element from the front of the queue and returns it.
    *   int peek() Returns the element at the front of the queue.
    *   boolean empty() Returns true if the queue is empty, false otherwise.
Notes:
    *   You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
    *   Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 
Example 1:
    Input   :   ["MyQueue", "push", "push", "peek", "pop", "empty"]
                [[], [1], [2], [], [], []]
    Output  :
                [null, null, null, 1, 1, false]

Explanation :
MyQueue myQueue = new MyQueue();
myQueue.push(1);    // queue is: [1]
myQueue.push(2);    // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek();     // return 1
myQueue.pop();      // return 1, queue is [2]
myQueue.empty();    // return false     */

class MyQueue {
public:
    stack<int> first;
    stack<int> second;

    MyQueue() {}
    
    void push(int x) {
        while(!first.empty()) {
            second.push(first.top());
            first.pop();
        }
        first.push(x);
        while(!second.empty()) {
            first.push(second.top());
            second.pop();
        }
    }
    
    int pop() {
        if(!first.empty()) {
            int val = first.top();
            first.pop();
            return val; 
        } else {
            return -1;
        }
    }
    
    int peek() {
        if(!first.empty()) {
            int val = first.top();
            return val; 
        } else {
            return -1;
        }
    }

    bool empty() {
        if(first.size() == 0)
            return 1;
        else
            return 0;
    }
};
///////////////////////////////////
/*  2434. Using a Robot to Print the Lexicographically Smallest String

You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:

Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
Return the lexicographically smallest string that can be written on the paper. 

Example 1:  Input: s = "zza"    Output: "azz"
Explanation: Let p denote the written string.
Initially p="", s="zza", t="".
Perform first operation three times p="", s="", t="zza".
Perform second operation three times p="azz", s="", t="".

Example 2:  Input: s = "bac"    Output: "abc"
Explanation: Let p denote the written string.
Perform first operation twice p="", s="c", t="ba". 
Perform second operation twice p="ab", s="c", t="". 
Perform first operation p="ab", s="", t="c". 
Perform second operation p="abc", s="", t="".

Example 3:  Input: s = "bdda"   Output: "addb"
Explanation: Let p denote the written string.
Initially p="", s="bdda", t="".
Perform first operation four times p="", s="", t="bdda".
Perform second operation four times p="addb", s="", t="".       */

#include<iostream>
#include<unordered_map>
#include<stack>

using namespace std;

string robotWithString(string s) {
    unordered_map<char,int> freq;
    // This for each loop tracks the frequency of characters in the string and map into a unordered map
    for(char c : s) {
        freq[c]++;
    }

    stack<char> robot;      //  empty stack
    string res;             //  empty string
    char minCharacter = 'a';    //  assign minCharacter as 'a' as it is the first one in alphabet
    for(char c : s) {
        robot.push(c);      //  push the first element from string 's' into robot
        freq[c]--;          //  reduce the frequency as it removed from the string
        while(minCharacter != 'z' and freq[minCharacter] == 0) {    //  while current character is not 'z' and its frequency is zero then we can increment the minCharacter 
            minCharacter++;
        }
        while(!robot.empty() and robot.top() <= minCharacter) {     //  while robot is not empty and robot.top() element is less than minCharacter then we can push that element from robot to paper whcih is 'res' in our case
            res.push_back(robot.top());             //  push the robot top into the "res"
            robot.pop();                            //  remove that character from robot
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    string s{"bdda"};
    cout<<"Output of robots lexicographically smallest string is : "<<robotWithString(s)<<endl;
    return 0;
}
////////////////////////////////////////
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int i = 0;
    
    for(auto val : pushed) {
        //cout<<"Val: "<<val<<endl;
        st.push(val);       //  we keep on push the value of pushed into the stack st 
        while(!st.empty() and st.top() == popped[i]) {  // when this condition meets then we can pop the matching elements
            cout<<"st.top(): "<<st.top()<<endl;
            st.pop();
            i++;
        }
    }
    return st.empty();  // if all the elements are popped then we know that it it valid sequence
}

int main(int argc, char* argv[]) {
    vector<int> pushed{1,2,3,4,5}, popped{4,5,3,2,1};
    cout<<"Validity of Stack Sequence is : "<<validateStackSequences(pushed,popped)<<endl;
    return 0;
}
////////////////////////////
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> collide;
    vector<int> out;
    bool destroyed = false;

    for(auto val : asteroids) {
        destroyed = false;
        while(!collide.empty() and collide.top() > 0 and val < 0 ) {
            if(collide.top() < abs(val)) {
                collide.pop();
                continue;
            }
            else if(collide.top() == abs(val)) {
                collide.pop();
            }
            destroyed = true;
            break;
        }

        if(!destroyed) {
            collide.push(val);
        }
    }
    while(!collide.empty()) {
        //cout<<collide.top()<<endl;
        out.push_back(collide.top());
        collide.pop();
    }
    reverse(out.begin(),out.end());
    return out;
}

int main(int argc, char* argv[]) {
    vector<int> asteroi{-2,1,-1,-2};
    vector<int> temp = asteroidCollision(asteroi);
    if(!temp.empty()) {
        cout<<"Output is : ";
        for(auto val : temp) {
            cout<<val<<" ";
        }
        cout<<endl;
    } else {
        cout<<"Value is empty"<<endl;
    }
    return 0;
}
///////////////////////////////////
/* 155. Min Stack : Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
    Implement the MinStack class:
        *   MinStack() initializes the stack object.
        *   void push(int val) pushes the element val onto the stack.
        *   void pop() removes the element on the top of the stack.
        *   int top() gets the top element of the stack.
        *   int getMin() retrieves the minimum element in the stack.
    You must implement a solution with O(1) time complexity for each function.

Example 1:
    Input   :           ["MinStack","push","push","push","getMin","pop","top","getMin"]
                        [[],[-2],[0],[-3],[],[],[],[]]
    
    Output  :           [null,null,null,null,-3,null,0,-2]
    
    Explanation :
                        MinStack minStack = new MinStack();
                        minStack.push(-2);
                        minStack.push(0);
                        minStack.push(-3);
                        minStack.getMin(); // return -3
                        minStack.pop();
                        minStack.top();    // return 0
                        minStack.getMin(); // return -2
    */

class MinStack {
public:
    vector<int> data;
    int minVal = INT_MAX;

    MinStack() {}
    
    void push(int val) {
        data.push_back(val);
        minVal = min(minVal,val);
    }
    
    void pop() {
        data.pop_back();
        minVal = INT_MAX;
        for(auto val : data) {
            minVal = min(minVal,val);
        }              
    }
    
    int top() {
       return data.back(); 
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
////////////////////////////////////////////





