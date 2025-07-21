// Suppose we have 2 tasks or processes, task or process A 
//    generate events and task for process B to processes them.
// Task A has higher priority than task B, if task A generate 
//    too many events exceeding certain limit, the system should 
//    start dropping old event and keep only last N events available for B to process.
// Your task is to implement the data structure needed to fulfill
//    the requirements and write sample application code for both tasks A & B.
 
 
 #include<stdio.h>
 #include<stdlib.h>
 #include<pthreads.h>


// Queue.
#define MAX_ENTRIES 10;
 
typedef void (*fp)(void *);
 
struct Node {
    fp *task;
    Node *next;    
};

struct Queue {
    Node *head;
    Node *tail;
    int currSize;
    sem_t *sm;
    mutex_t *m;
};
 
struct Queue q;
 
// task A // producer
 
int enqueue(struct Queue &q, fp foo) {
    
    if(fp == NULL)
        return -1;
    
    // head, tail check done
    
    Node *n = new Node(fp);
    
    if(q.tail == NULL) {
        q.tail = q.head = n;
        return 0;
    }
    
    q.tail->next = n;
    q.tail = n;
 
    return 0;
}
 
Node * dequeue(struct Queue &q) {
    
    if(!q.head) 
        return -1;
       
    Node *myNode = q.head;
    q.head = q.head->next;
       
    return myNode;
}
 
void taskA(fp *f) {
    
    // this has sempahore when process starts;
    
    if(f == NULL) {
        perror("Invalid task ptr!");
        return;
    }
    
    lock_mutex(&m);
     if(q->currSize < MAX_ENTRIES) {
            fp my_task = dequeue(q);
        }
    //later    
    enqueue(q, f);
    unlock_mutex(&m);
    sem_post(s);
 
    return;
}
 
// task B // consumer
void taskB() {
    
    while(1) {
        wait_sem(s);
        lock_mutex(m);
    
        unlock_mutex(m);
        
        
        
        my_task();
        
    }
    
}
