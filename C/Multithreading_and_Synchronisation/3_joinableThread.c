#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>      //  for pause() and sleep()
#include<pthread.h>     //  for working with POSIX threads
#include<errno.h>       //  for using global variable errno

pthread_t pthread2;
pthread_t pthread3;

void* thread_fn_callback(void *arg) {
    int input = *(int *)arg;
    free(arg);
    int a = 0;
    while(a != input) {
        printf("Thread %d doing some work\n", input);
        sleep(1);
        a++;
    }
    int *result = (int*)calloc(1, sizeof(int));   //  just like input argument the return argument also should be of static or heap
    *result = input * input;
    return (void *)result;
}
void thread_create(pthread_t *pthread_handle, int thread_ID) {  // not a actual thread_ID just for reference
    //  we can set the properties before invoking the pthread_create(), by default the thread created via pthread_create() is joinable thread, incase of detached thread only we need to use the below 3 lines before invoking the pthread_create()
    //////////////////////////////////////////////////////////////////////
    pthread_attr_t attribute;   //  this variable is used to specify the properties of the new variable that is created
    pthread_attr_init(&attribute);
    /*  PTHREAD_CREATE_JOINABLE =   Joinable thread
        PTHREAD_CREATE_DETACHED =   Detached thread*/
    pthread_attr_setdetachstate(&attribute, PTHREAD_CREATE_JOINABLE);   //  API to set the thread state as joinable or detached
    /////////////////////////////////////////////////////////////////////

    int *_th_id = (int*)calloc(1,sizeof(int));
    *_th_id = thread_ID;    //  passing arguments should be of static or heap which we have seen in 2_threadTermination.c
    int rc = pthread_create(pthread_handle, &attribute, thread_fn_callback, (void*)_th_id);
    if(rc != 0) {
        printf("Error occured, thread could not be created, errno = %d\n",rc);
        exit(0);
    }
}

int main(int argc, char* argv[]) {
    void *thread_result2 = NULL;
    void *thread_result3 = NULL;

    thread_create(&pthread2, 2);
    thread_create(&pthread3, 10);

    printf("main fn blocked on pthread join for thread with thread_ID = 2\n");
    pthread_join(pthread2, &thread_result2);    //  the 2nd argument is the return from the thread fn callback which we need to store in void pointer
    if(thread_result2) {
        printf("Return result from thread 2 = %d\n", *(int*)thread_result2);
        free(thread_result2);   // we freed the thread fn callback allocated memeory 
        //thread_result2 = NULL;  //  but our local void pointer should point to something after we freed the memory of where it pointing to
    }

    printf("main fn blocked on pthread join for thread with thread_ID = 10\n");
    pthread_join(pthread3, &thread_result3);    //  the 2nd argument is the return from the thread fn callback which we need to store in void pointer
    if(thread_result3) {
        printf("Return result from thread 3 = %d\n", *(int*)thread_result3);
        free(thread_result3);   // we freed the thread fn callback allocated memeory 
        //thread_result3 = NULL;  //  but our local void pointer should point to something after we freed the memory of where it pointing to
    }
    return 0;
}
