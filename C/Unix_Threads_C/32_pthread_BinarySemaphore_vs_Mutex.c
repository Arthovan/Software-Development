/*  This code will explain the difference between binary semaphore and mutex */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <threads.h>
#include<unistd.h>
#include<time.h>
#include<semaphore.h>

#define THREAD_NUM 4
#define SEM_MUTEX_DIFFERENCE

pthread_mutex_t mutexFuel;
sem_t semFuel;

int fuel = 50;

#ifdef SEM_MUTEX_DIFFERENCE
// Try to execute this code with sempahore once and commnet the sempahore, uncomment the mutex and run. We can see clearly that Semaphore works fine and mutex produce some undefined results
// Mutex has a concept called ownership where the thread locks the mutex should the same mutex. So in our case routine1 locks mutex and routine2 unlocks mutex which are 2 different threads
// So the mutex created some undefined behaviours
// But semaphore can be incremented and decremented by different threads so thats why it works fine here
void* routine1(void* args){
    while(1){
        pthread_mutex_lock(&mutexFuel);
        //sem_wait(&semFuel);
        fuel += 50; 
        printf("Current Value is %d\n", fuel);
    }
    return NULL;
}
void* routine2(void* args){
    while(1){
        pthread_mutex_unlock(&mutexFuel);
        //sem_post(&semFuel);
        usleep(5000);
    }
    return NULL;
}

int main(int argc, char*argv[]){
    pthread_t thread[THREAD_NUM];   
    sem_init(&semFuel, 0, 1); 
    int i;
    for(i = 0; i < THREAD_NUM; i++){
        if(i % 2 == 0){
            if(pthread_create(&thread[i],NULL,routine1,NULL) != 0){
                perror("Failed to create a thread");
            }
        } 
        else{
            if(pthread_create(&thread[i],NULL,routine2,NULL) != 0){
                perror("Failed to create a thread");
            }
        }
    }
    
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("Failed to join a thread");
        }
    }
    pthread_mutex_destroy(&mutexFuel);
    sem_destroy(&semFuel);
    return 0;
}

#endif

#ifdef SEM_MUTEX_COMMON
void* routine(void* args){
    sem_wait(&semFuel); // comment the mutex in the routine and enable this semaphore to see the results
    //pthread_mutex_lock(&mutexFuel); // both the above semaphore and this mutex will result in same values as the sem value is 1 it act as binary semaphore here
    fuel += 50; 
    printf("Current Value is %d\n", fuel);
    //pthread_mutex_unlock(&mutexFuel);
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
    pthread_mutex_destroy(&mutexFuel);
    sem_destroy(&semFuel);
    return 0;
}
#endif
