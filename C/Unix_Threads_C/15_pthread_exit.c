/*  => pthread_exit is called from the thread itself to terminate its execution (and return a result) early.
    => pthread_join is called from another thread (usually the thread that created it) to wait for a thread to terminate and obtain its return value. It can be called before or after the thread you're waiting for calls pthread_exit. If before, it will wait for the exit to occur. If after, it simply obtains the return value and releases the pthread_t resources.

    in Simple : 
    pthread_exit() : Terminates the calling thread. This does not affect other threads.
    pthread_join() : Waits for the specified thread to terminate. It blocks the calling thread until the target thread finishes.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>

void* roll_dice(void* args){
    int value = (rand() % 6) + 1;
    int* result =(int*)malloc(sizeof(int));
    *result = value;
    printf("Thread result: %d\n",value);
    //return (void*) result;
    pthread_exit((void*) result); // this is same as above which we did it in return value from routine in 7_pthread_ReturnValue.c code
}

int main(int argc, char* argv[]){
    int *res;
    srand(time(NULL));
    pthread_t th;
    if(pthread_create(&th,NULL,&roll_dice,NULL) != 0){
        return 1;
    }
    // If we give normal return or exit(0) this main process will exit and thereby thread also wont execute, but if we use pthread_exit in the main process it will exit main process and also thread can exit safely 
    // it is used in some usecase 
    pthread_exit(0); //  comment below join while executing this pthread_exit(0);
    /*if(pthread_join(th,(void**)&res) != 0){
        return 2;
    }
    */
    printf("Result : %d\n", *res);
    //return 0;*
}
