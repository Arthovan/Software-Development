/* This code doesnt have anything to execute so you cant see any valid output
Just read the comments and go through the previous code to see the technical details

*/#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/syscall.h> //  SYS_gettid() is here

#define THREAD_NUM 2
/* Static Initializer Method */
pthread_mutex_t mutexFuel = PTHREAD_MUTEX_INITIALIZER; // by this we dont need init for mutex also
// this is a macro for some mutex values which we can use for single mutex and for array of mutex
// we need to use normal init mutex method only

// below is wrong implementation, we need to loop over array and use the init method to initilaize the mutex
// pthread_mutex_t mutexArr[THREAD_NUM] = PTHREAD_MUTEX_INITIALIZER;

/* Normal method */
// pthread_mutex_t mutexFuel;

// Also we can use the static initializer for conditon varlable also but not for barrier
pthread_cond_t condFuel = PTHREAD_COND_INITIALIZER;

void* routine(void* args){
    return NULL;
}

int main(int argc, char*argv[]){
    pthread_t thread[THREAD_NUM];
    pthread_mutex_init(&mutexFuel,NULL);
    
    int i;
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_create(&thread[i],NULL,&routine,NULL) != 0){
            perror("Failed to create thread");
        }
    }
     for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("Failed to join thread");
        }
    }
    // this below code also not mandatory as most of the system can cleanup automatically
    // but it is a good practice to destroy the mutex
    pthread_mutex_destroy(&mutexFuel); 
    pthread_exit(0);
}
