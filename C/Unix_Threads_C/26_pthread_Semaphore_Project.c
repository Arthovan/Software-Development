/* Semaphore : There are 2 things that we can do in thread with semaphore, that is wait and post
    wait : simillar like mutex lock
    post : similar like mutex unlock
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <threads.h>
#include<unistd.h>
#include<time.h>
#include<semaphore.h>

#define THREAD_NUM 16

sem_t semaphore;

void* routine(void* args){
    printf("(%d) waiting in the login queue\n", *(int*)args);
    sem_wait(&semaphore); // it check for semaphore value is equal to 0 then wait, if semaphore value > 0 then decrement it and start executing the next lines of code
    printf("(%d) Logged in\n", *(int*)args);
    sleep(rand() % 5 + 1);
    printf("(%d) Logged out\n",*(int*)args);
    sem_post(&semaphore); // semp_post just increment the semaphore value
    free(args);
    return NULL;
}

int main(int argc, char*argv[]){
    pthread_t thread[THREAD_NUM];
    // important thing to note is that semaphore has a initial value that is stored in the semaphore structure for it
    sem_init(&semaphore, 0, 1); // init semaphore with (semaphore variable, process (1) or threads(0), Initial value of semaphore)
    // as thread wait and post just increment and decrement semaphore value, it acts like the "n" number of threads can excute at time 
    // where "n" is the semaphore initial value. In our case it is 1
    // in mutex 1 thread only can able to lock and use the shared region but in semaphore mutliple threads can apply lock and use by sem_wait & sem_post
    int i;

    for(i = 0; i < THREAD_NUM; i++){
        int *a = (int*)malloc(sizeof(int));
        *a = i;
        if(pthread_create(&thread[i],NULL,routine,a) != 0){
            perror("Failed to create a thread");
        }
    }    
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("Failed to join a thread");
        }
    }
    sem_destroy(&semaphore);    // this tells the program that we dont need the semaphore anymore and free the resources
    return 0;
}
