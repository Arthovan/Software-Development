/* This below is made to stuck so that we can undestand the behaviour which is explained in the code.
    Try to execute multiple times if the code didnt stcuk anywhere
*/
    #include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>

#define THREAD_NUM 8
#define IMPROPER_LOCK

pthread_mutex_t mutexFuel;
int fuel = 50;
pthread_mutex_t mutexWater;
int water = 10;

#ifdef IMPROPER_LOCK
void* routine(void* args){
    // I have created a thread lock in a way that depends upon the rand key value the lock will be applied
    // if Thread 1 applied a lock for mutexFuel and Thread 2 applied a lock for mutexWater then Thread 1 has to wait for mutexWater to be released and Thread2 has to wait for mutexFuel to be released
    // This causes a deadlock
    if(rand() % 2 == 0){
        pthread_mutex_lock(&mutexFuel);
        pthread_mutex_lock(&mutexWater); 
    } else {
        pthread_mutex_lock(&mutexWater);
        pthread_mutex_lock(&mutexFuel);
    }
    // We need to be careful at the order of locking the mutex
    fuel += 50;
    water = fuel;
    printf("Incremented fuel to: %d set water to %d\n", fuel, water);
    pthread_mutex_unlock(&mutexFuel);
    pthread_mutex_unlock(&mutexWater);
    return NULL;
}

int main(int argc, char*argv[]){
    srand(time(NULL));
    pthread_t thread[THREAD_NUM];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_mutex_init(&mutexWater, NULL);
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
    printf("Final Fuel : %d\n", fuel);
    pthread_mutex_destroy(&mutexFuel);
    pthread_mutex_destroy(&mutexWater);
    return 0;
}
#endif

#ifdef PROPER_LOCK
void* routine(void* args){
    pthread_mutex_lock(&mutexFuel);
    pthread_mutex_lock(&mutexWater); 
    fuel += 50;
    water = fuel;
    printf("Incremented fuel to: %d set water to %d\n", fuel, water);
    pthread_mutex_unlock(&mutexFuel);
    pthread_mutex_unlock(&mutexWater);
    return NULL;
}

int main(int argc, char*argv[]){
    pthread_t thread[THREAD_NUM];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_mutex_init(&mutexWater, NULL);
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
    pthread_mutex_destroy(&mutexWater);
    return 0;
}
#endif
