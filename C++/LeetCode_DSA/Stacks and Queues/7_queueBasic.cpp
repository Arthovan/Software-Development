///////////////////////////////////////////////////////////////
/* Queues Basic with some APIs 
	A queue is a linear data structure that follows the First In, First Out (FIFO) principle. 
	This means that the first element added to the queue will be the first one to be removed. 
	Queues are similar to a line of people waiting for a service where the first person in line 
	is the first to be served. Common operations in a queue include:
	
	*	Enqueue (push()): Adding an element to the end of the queue.
	*	Dequeue (pop()): Removing the front element from the queue.
	*	Front/Peek (front()): Retrieving the front element without removing it.
	*	Size: To get the size of the queue(shows how many elements in the queue)
	
	Queues are widely used in scenarios like scheduling processes in operating systems, handling 
	requests in web servers, and in breadth-first search algorithms'
	Understanding stacks and queues is fundamental in computer science as they provide the basis 
	for more complex data structures and algorithms.*/
	
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