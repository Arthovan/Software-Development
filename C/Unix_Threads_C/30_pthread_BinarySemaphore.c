/*  Binary semaphore : Binary Semaphore is a semaphore that can be either 0 or 1
 We can see that the both mutex and binary semaphore of the below code produces same results
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <threads.h>
#include<unistd.h>
#include<time.h>
#include<semaphore.h>

#define THREAD_NUM 4
#define BINARY_SEMAPHORE

int fuel = 50;

#ifdef BINARY_SEMAPHORE

sem_t semFuel;

void* routine(void* args){
    sem_wait(&semFuel); 
    fuel += 50;
    printf("Incremented fuel to: %d\n", fuel);
    sem_post(&semFuel);
    return NULL;
}

int main(int argc, char*argv[]){
    pthread_t thread[THREAD_NUM];
    sem_init(&semFuel, 0, 1);
    int i;
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_create(&thread[i],NULL,routine,NULL) != 0){
            perror("Failed to create a thread");
        }
    }    
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("Failed to join a thread");
        }
    }
    printf(" %d\n", fuel);
    sem_destroy(&semFuel);

    return 0;
}
#endif

#ifdef MUTEX

pthread_mutex_t mutexFuel;

void* routine(void* args){
    pthread_mutex_lock(&mutexFuel); 
    fuel += 50;
    printf("Incremented fuel to: %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
    return NULL;
}

int main(int argc, char*argv[]){
    pthread_t thread[THREAD_NUM];
    pthread_mutex_init(&mutexFuel, NULL);
    int i;
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_create(&thread[i],NULL,routine,NULL) != 0){
            perror("Failed to create a thread");
        }
    }    
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("Failed to join a thread");
        }
    }
    printf(" %d\n", fuel);
    pthread_mutex_destroy(&mutexFuel);
    return 0;
}
#endif
