#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>

#define THREAD_NUM 8

pthread_mutex_t mutexFuel;
int fuel = 50;

void* routine(void* args){
    pthread_mutex_lock(&mutexFuel);
    pthread_mutex_lock(&mutexFuel); // deadlock bcs in a thread, mutexFuel is already locked in the above code and same thread trying to lock again. Where thread cant lock if the source is already locked
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
