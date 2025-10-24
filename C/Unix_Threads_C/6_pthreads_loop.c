#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/wait.h>    //  Thread 
#include<sys/types.h>   // Thread
// Note : Execute the sequence and see the output, we can clearly see that its executing in the sequence order
// But we need to execute in parallel so we have to use the PARALLEL method only for creating and joining pthreads
#define PARALLEL
int mails = 0;
pthread_mutex_t mutex;  //  create a mutex variable

void * routine(void* arg){
    for(int i = 0; i < 1000000;i++){
        pthread_mutex_lock(&mutex); // Locks a mutex. If the mutex is already locked by another thread, the calling thread will be blocked.
        mails++;
        pthread_mutex_unlock(&mutex); // Unlocks a mutex that was previously locked by the calling thread.
    }
    return NULL;
}

#ifdef SEQUENCE // This is a wrong implementation of threads in loop
int main(int argc, char* argv[]){
    pthread_t t[4];
    pthread_mutex_init(&mutex,NULL);    // Initializes a mutex, which is used to prevent race conditions in concurrent programming.
    for(int i = 0; i < 4;i++){
        if(pthread_create(&t[i],NULL,routine,NULL)){
            return 1;
        }
        printf("Thread %d has started\n",i);
        if(pthread_join(t[i],NULL) != 0){ // pthread_join returns 0 on successfull joining of the thread, if fails we get non zero value
            return 2;
        }
        printf("Thread %d has finished execution\n",i);
    }
    printf("Number of mails: %d\n", mails);
    pthread_mutex_destroy(&mutex);  // Destroys a mutex when it's no longer needed.
    return 0;
}
#endif

#ifdef PARALLEL // Correct implementation of a threads in loop
int main(int argc, char* argv[]){
    pthread_t t[4];
    pthread_mutex_init(&mutex,NULL);    // Initializes a mutex, which is used to prevent race conditions in concurrent programming.
    for(int i = 0; i < 4;i++){
        if(pthread_create(&t[i],NULL,routine,NULL)){
            return 1;
        }
        printf("Thread %d has started\n",i);
    }
    for(int i = 0; i < 4;i++){       
        if(pthread_join(t[i],NULL) != 0){ // pthread_join returns 0 on successfull joining of the thread, if fails we get non zero value
            return 2;
        }
        printf("Thread %d has finished execution\n",i);
    }
    printf("Number of mails: %d\n", mails);
    pthread_mutex_destroy(&mutex);  // Destroys a mutex when it's no longer needed.
    return 0;
}
#endif
