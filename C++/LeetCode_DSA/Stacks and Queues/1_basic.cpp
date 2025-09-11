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
///////////////////////////////////////////////////////////
/*  71. Simplify Path : You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. 
                        Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:
    *   A single period '.' represents the current directory.
    *   A double period '..' represents the previous/parent directory.
    *   Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
    *   Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.

The simplified canonical path should follow these rules:
    *   The path must start with a single slash '/'.
    *   Directories within the path must be separated by exactly one slash '/'.
    *   The path must not end with a slash '/', unless it is the root directory.
    *   The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.

Return the simplified canonical path.
Example 1:  Input: path = "/home/"  Output: "/home"
Explanation:    The trailing slash should be removed.

Example 2:  Input: path = "/home//foo/" Output: "/home/foo"
Explanation:    Multiple consecutive slashes are replaced by a single one.

Example 3:  Input: path = "/home/user/Documents/../Pictures"    Output: "/home/user/Pictures"
Explanation:    A double period ".." refers to the directory up a level (the parent directory).

Example 4:  Input: path = "/../"    Output: "/"
Explanation:    Going one level up from the root directory is not possible.

Example 5:  Input: path = "/.../a/../b/c/../d/./"   Output: "/.../b/d"
Explanation:    "..." is a valid name for a directory in this problem.      */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string simplifyPath(string path) {
    vector<string> stack;
    stringstream ss(path);
    string temp;
    string result;
    while(getline(ss, temp, '/')) {
        if(temp == ".."){
            if(!stack.empty())
                stack.pop_back();
        } else if (temp !="." && !temp.empty()) {
                stack.push_back(temp);
        }
    }

    for(auto str : stack){
        result += "/" + str;
    }
    if(result.empty()) {
        return "/";
    } else {
        return result;
    }
}

int main(int argc, char*argv[]) {
    string path = "/home/user/Documents/../Pictures";
    path = simplifyPath(path);
    cout<<path<<endl;    
    return 0;
}
/////////////////////////////////////////////////////
/*  1544. Make The String Great :   Given a string s of lower and upper case English letters.
A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:
    *   0 <= i <= s.length - 2
    *   s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them.
You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.

Example 1:  Input: s = "leEeetcode"     Output: "leetcode"      
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".

Example 2:  Input: s = "abBAcC"         Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
    "abBAcC" --> "aAcC" --> "cC" --> ""
    "abBAcC" --> "abBA" --> "aA" --> ""

Example 3:  Input: s = "s"              Output: "s"     */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string makeGood(string s) {
    vector<char> stack;
    for(auto val : s) {
        if(!stack.empty() and abs(stack.back() - val) == 32) {
            stack.pop_back();
        } else {
            stack.push_back(val);
        }
    }
    string temp(stack.begin(), stack.end());
    return temp;
}

int main(int argc, char*argv[]) {
    string s = "leEeetcode";
    s = makeGood(s);
    cout<<s<<endl;    
    return 0;
}
///////////////////////////////////////////////////////////////
#include<iostream>
#include<queue>

using namespace std;

int main(int argc, char*argv[]) {
    // Declaration: C++ supports multiple implementations, but we will be using
    // std::queue. Specify the data type
    queue<int> queue;
    
    // Enqueueing/adding elements:
    queue.push(1);
    queue.push(2);
    queue.push(3);

    // Dequeing/removing elements:
    queue.pop();

    // Check if empty
    queue.empty() == 1?cout<<"Queue is empty":cout<<"Queue is not empty"<<endl; // false

    // Check element at front of queue (next element to be removed)
    cout<<"Queue front element is : "<<queue.front()<<endl; // 2

    // Get size
    cout<<"Queue size is : "<<queue.size()<<endl; // 2
    
    while (!queue.empty()) {        
        cout << queue.front() << endl;      
        queue.pop();
    }
    
    if (queue.empty()) {
        cout << "Queue is empty!" << endl;
    }
}
//////////////////////////////////
/* 933. Number of Recent Calls
You have a RecentCounter class which counts the number of recent requests within a certain time frame.

Implement the RecentCounter class:
    *   RecentCounter() Initializes the counter with zero recent requests.
    *   int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the 
        number of requests that has happened in the past 3000 milliseconds (including the new request). 
        Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].
It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.

Example 1:
Input
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]

Output
[null, 1, 2, 3, 3]

Explanation
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1
recentCounter.ping(100);   // requests = [1, 100], range is [-2900,100], return 2
recentCounter.ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3
recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3

*/

class RecentCounter {
    public:
    queue<int> queue;

    RecentCounter() {}

    int ping(int t) {
        while(!quque.empty() and queue.front() < t- 3000) {
            queue.pop();
        }
        queue.push(t);
        return queue.size();
    }
};
/////////////////////////////////////////



