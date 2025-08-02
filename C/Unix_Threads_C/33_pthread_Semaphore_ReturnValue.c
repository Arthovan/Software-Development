/*  This code will explain the difference between binary semaphore and mutex */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <threads.h>
#include<unistd.h>
#include<time.h>
#include<semaphore.h>

#define THREAD_NUM 4

sem_t sem;

// Make use we dont use this in actual project or somewhere as this will cause lot of race conditions 
void* routine(void* args){
    int index = *(int*)args;
    int semVal;
    // we can see clearly that in the output the semaphore is executing with unsynchronized way, we can introduce a sleep after the sem_wait to get a synchronized way of getting the output
    sem_wait(&sem);
    sleep(index + 1); // just making the wait value as index value plus 1 second
    sem_getvalue(&sem, &semVal); // this function is to get value form semaphore and store it in a variable
    printf("(%d) Current Semaphore value after wait is %d\n",index,semVal);
    sem_post(&sem);
    sem_getvalue(&sem, &semVal); // this fucntion is to get value form semaphore and store it in a variable
    printf("(%d) Current Semaphore value after post is %d\n",index,semVal);
    free(args);
    return NULL;
}

int main(int argc, char*argv[]){
    pthread_t thread[THREAD_NUM];   
    sem_init(&sem, 0, 1); 
    int i;
    for(i = 0; i < THREAD_NUM; i++){
        int* a = (int*)malloc(sizeof(int));
        *a = i;
        if(pthread_create(&thread[i],NULL,&routine,a) != 0){
            perror("Failed to create a thread");
        }
    }
    
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("Failed to join a thread");
        }
    }
    sem_destroy(&sem);
    return 0;
}
