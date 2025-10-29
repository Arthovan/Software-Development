#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>                 // contains sleep function, mostly contains linux realted stuffs
#include <pthread.h>                // library contains the pthreads

void* threadCallback(void *args) {
    int TID = *(int*)args;
    printf("Thread %d created successfully\n",TID);
    sleep(1);

    int *result = (int*)calloc(1, sizeof(int));
    *result = TID + 1;

    free(args);
    return (void*)result;
}

void createThread(pthread_t *pthread_handle, int thread_ID){
    int *threadID = (int*)calloc(1, sizeof(int));
    *threadID = thread_ID;

    pthread_attr_t attribute;       //  create a attribute handler to specify whether the thread is Joinable or Detached
    pthread_attr_init(&attribute);  //  init the attribuite
    pthread_attr_setdetachstate(&attribute,PTHREAD_CREATE_JOINABLE);    //  set the state of the attribute

    if(pthread_create(pthread_handle, &attribute, &threadCallback, (void*)threadID) != 0) {
        printf("Error occured thread couldnt be created for thread : %d\n",*threadID);
        free(threadID);
        pthread_attr_destroy(&attribute);
        pthread_exit(0);
    }
    pthread_attr_destroy(&attribute);
}

int main(int argc, char* argv[]){
    void *returnValue = NULL;
    pthread_t threads[4];

    for(int i = 0; i < 4; i++) {
        createThread(&threads[i],i);
    }

    for(int i = 0; i < 4; i++) {
        if(pthread_join(threads[i],&returnValue) == 0) {
            printf("Thread return value is %d\n",*(int*)returnValue);
            free(returnValue);
        } else {
            printf("Error: Failed to join a thread %d\n", i);
        }
    }
    return 0;
}