/*  Binary semaphore : Binary Semaphore is a semaphore that can be either 0 or 1
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <threads.h>
#include<unistd.h>
#include<time.h>
#include<semaphore.h>

#define THREAD_NUM 1

sem_t semFuel;

int *fuel;

void* routine(void* args){    
    *fuel += 50; // as fuel is created and allocated in main and not here so we dont have to wait here
    printf("Current Value is %d\n", *fuel);
    sem_post(&semFuel);
    return NULL;
}

int main(int argc, char*argv[]){
    pthread_t thread[THREAD_NUM];
    fuel = (int*)malloc(sizeof(int));
    *fuel = 50;    
    sem_init(&semFuel, 0, 0); // we made the initial value as 0 here as we dont have to wait in thread (routine)
    int i;
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_create(&thread[i],NULL,routine,NULL) != 0){
            perror("Failed to create a thread");
        }
    }

    sem_wait(&semFuel); // this semaphore wait until the thread finishes the sem_post(), then we know that the thread used the fuel variable for something
    printf("Deallocating Fuel\n");
    free(fuel);
    
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("Failed to join a thread");
        }
    }
  
    sem_destroy(&semFuel);
    return 0;
}
