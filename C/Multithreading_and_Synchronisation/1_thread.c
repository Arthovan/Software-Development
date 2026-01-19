#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>      //  contains sleep function, mostly contains linux related stuffs
#include<pthread.h>     // library contains the pthreads

void* thread_fn_callback(void *arg) {
    char *input = (char *)arg;
    while(1) {
        printf("Input string = %s\n", input);
        sleep(1);
    }
}
void thread1_create() {
    pthread_t thread1;  //  opaque object, dont bother about its internal members

    /*  If we need to pass some data as a argument to the thread then it should be of static or heap memory (Dynamically allocated memory only).
    Do not pass some local variable or stack memory */
    static char *thread_input1 = "I am thread no 1";

    /* pthread_create() returns 0 on success, otherwise returns error code, all pthread functions returns -ve error code on failure. They do not
    set global variable.
        thread1                     =   thread handler
        NULL
        thread_fn_callback          =   Pointer to the function 
        thread_input1			    =   (input data to the thread) Data that can be passed to thread as an argument and it should be of static or heap memory but not from stack. 
		Reason is after this pthread_create call the new thread is going to be created if the passed value is local and the called thread dies then there 
		wont be any local value as the function dies already. This behaviour can be catostrophic in reading the data in thread as an argument. */
    int rc = pthread_create(&thread1, NULL, thread_fn_callback, (void*)thread_input1);

    if(rc != 0) {
        printf("Error occured, thread could not be created, errno = %d\n", rc);
        exit(0);
    }
}

int main(int argc, char* argv[]) {
    thread1_create();
    printf("Main function paused\n");
    pause();    //  without this, main thread will simply exit so all other child threads terminate by default
    return 0;
}