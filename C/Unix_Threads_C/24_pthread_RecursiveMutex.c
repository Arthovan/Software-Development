/*  In the code 22_pthread_Deadlock.c we saw that if we try to lock the same mutex times then code will stuck in deadlock, but there are scenarios we need to use that kind of lock
which we call it as "recursive mutex". For that we need use the attributes of mutex, to work on recursive mutex
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <threads.h>
#include<unistd.h>
#include<time.h>

#define THREAD_NUM 8

pthread_mutex_t mutexFuel;
int fuel = 50;

void* routine(void* args){
    pthread_mutex_lock(&mutexFuel);
    pthread_mutex_lock(&mutexFuel); 
    fuel += 50;
    printf("Incremented fuel to: %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
    pthread_mutex_unlock(&mutexFuel);   //  also we need to unlock the mutex for how many times we locked it, by this only the recursive mutex works fine
    // Even we can have "n" number of lock in mutex as long as we are unlocking it "n" number of times
    return NULL;
}

int main(int argc, char*argv[]){
    pthread_t thread[THREAD_NUM];
    // Recursive Mutex starts
    pthread_mutexattr_t recursiveMutexAttributes;       // Created a recursive mutex variable
    pthread_mutexattr_init(&recursiveMutexAttributes);  // init the recursive mutex
    pthread_mutexattr_settype(&recursiveMutexAttributes,PTHREAD_MUTEX_RECURSIVE);   //  set the type as recursive 
    // Recursive Mutex code ends
    pthread_mutex_init(&mutexFuel, &recursiveMutexAttributes);   // Also note that while initializing the normal mutex, we used the recursive mutex variable as second argument instead of NULL
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
    pthread_mutexattr_destroy(&recursiveMutexAttributes);   // also note that we need to close the mutex attr before the normal mutex
    pthread_mutex_destroy(&mutexFuel);
    return 0;
}
