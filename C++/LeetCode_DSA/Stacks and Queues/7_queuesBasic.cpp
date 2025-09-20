///////////////////////////////////////////////////////////////
/* Queues Basic with some APIs */
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