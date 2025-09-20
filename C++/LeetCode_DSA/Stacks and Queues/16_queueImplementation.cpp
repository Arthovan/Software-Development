/*
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
}; */

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