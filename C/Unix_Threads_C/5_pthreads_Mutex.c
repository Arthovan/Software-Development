#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/wait.h>    //  Thread 
#include<sys/types.h>   // Thread

int mails = 0;
pthread_mutex_t mutex;  //  create a mutex variable

void * routine(void* arg){
    for(int i = 0; i < 1000000;i++){
        // this below check whether lock is applied by another thread, if so wait for thread to complete 
        pthread_mutex_lock(&mutex); // Locks a mutex. If the mutex is already locked by another thread, the calling thread will be blocked.
        mails++;
        // This routine does 3 operations here
        // 1. Read mails variable
        // 2. Increment
        // 3. write mails
        pthread_mutex_unlock(&mutex); // Unlocks a mutex that was previously locked by the calling thread.
    }
    return NULL;
}

int main(int argc, char* argv[]){
    pthread_t t1,t2;
    pthread_mutex_init(&mutex,NULL);    // Initializes a mutex, which is used to prevent race conditions in concurrent programming.
    if(pthread_create(&t1,NULL,routine,NULL)){
        return 1;
    }
    if(pthread_create(&t2,NULL,routine,NULL)){
        return 2;
    }
    if(pthread_join(t1,NULL) != 0){ // pthread_join returns 0 on successfull joining of the thread, if fails we get non zero value
        return 3;
    }
    if(pthread_join(t2,NULL) != 0){
        return 4;
    }
    // We are expecting the output of 2 millions but the output wont be 2 millions it would be some other number. Because thread are executed by OS, during context switching the thread t1 
    // might have completed till 1. Read mails variable and thread t2 started and did its part. Once again the thread t2 starts from step 2: Increment and thereby value mismatch happens
    // causing a "Race Condition" here. To avoid this we need to use locking mechanism 
    // As we used the mutex (locking mechanism), now output will be in roper order.
    printf("Number of mails: %d\n", mails);
    pthread_mutex_destroy(&mutex);  // Destroys a mutex when it's no longer needed.
    return 0;
}
