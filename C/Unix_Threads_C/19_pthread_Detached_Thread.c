#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/syscall.h> //  SYS_gettid() is here

#define THREAD_NUM 2

void* routine(void* args){
    sleep(1);
    printf("Finished execution\n");
    return NULL;
}

int main(int argc, char*argv[]){
    // format of pthread_t in header file is (typedef unsigned long pthread_t)
    pthread_t thread[THREAD_NUM];  
    int i;
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_create(&thread[i],NULL,&routine,NULL) != 0){
            perror("Failed to create thread");
        }
        pthread_detach(thread[i]);
    }
    // even the below part of join also not needed as the threads are already detached
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("Failed to join thread");
        }
    }
    // we may get failed to join thread : Success => bcs the main process finished before the thread even complete 
    // so main thread has to wait for thread to finish so we use pthread_exit(0)
    pthread_exit(0);
}
