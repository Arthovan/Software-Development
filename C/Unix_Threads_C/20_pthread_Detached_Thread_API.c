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
    // on 19_pthread_Detached_Thread.c file we saw how to create a thread and make it detached
    // now while creating itself we create a detached thread
    pthread_attr_t detachedThread; // create a detached Thread
    pthread_attr_init(&detachedThread); // init a detached Thread
    pthread_attr_setdetachstate(&detachedThread,PTHREAD_CREATE_DETACHED); // make the state for detached thread as joinable thread or detached thread
    // main reason for creating a detached thread using this above method is so that its confirmed that we are creating detached thread and during destroy memeory is freed
    // if we create normal thread and make it detach there are chances that between those steps it may or may not be detached thread. so memory wont be freed properly during destroy
    int i;
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_create(&thread[i],&detachedThread,&routine,NULL) != 0){
            perror("Failed to create thread");
        }
        //pthread_detach(thread[i]);
    }
    // the below code is useless as the heads are detached
    /*for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("Failed to join thread");
        }
    }*/
    pthread_attr_destroy(&detachedThread);
    pthread_exit(0);
}
