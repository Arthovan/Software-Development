/* Create a pthread which will wait for all threads to finish then terminate the program
Note : Inorder to finish the thread and main has to wait, for that we have to use the pthread_join function

Thread Termination : A thread can terminate in 3 ways 
    1. Thread finishes its execution and return to main
    2. By calling the pthread_exit(0) API
    3. Thread cancellation (One thread cancel the other thread)
        a. Parent thread can cancel the child thread
        b. Child thread can cancel parent thread
        c. Child thread can cancel the child thread
        d. Any thread can cancel any thread.

    If a main thread dies, all other thread dies by default, but vice-versa is not true.
*/
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>      //  contains sleep function, mostly contains linux realted stuffs
#include<pthread.h>     // library contains the pthreads

void* thread_fn_callback(void *arg) {
    char *input = (char *)arg;
    int a = 0;
    while(a < 10) {
        printf("Input string = %s\n", input);
        sleep(1);
        if(a == 5) {
           pthread_exit(0); 
        }
        a++;
    }
}
void thread1_create() {
    pthread_t thread1;  //  opaque object, dont bother about its internal members

    /*  If we need to pass some data as a argument to the thread then it should be of static or heap memory (Dynamically allocated memory only).
    Do not pass some local variable or stack memory */
    static char *thread_input1 = "I am thread no 1";

    /* pthread_create() returns 0 on success, othrewise returns error code, all pthread functions returns -ve error code on failure. They do not set global variable.
        pthread1                    =   thread handler
        NULL
        thread_fn_callback          =   Pointer to the function 
        input data to the thread    =   data that can be passed to thread as an argument and it should be of static or heap memory but not from stack. Reasson is after this pthread_create call the new thread is going to be created if the passed value is local and the called thread dies then there wont be any local value as the function dies already. This behaviour can be catostrophic in reading the data in thread as an argument. */
    int rc = pthread_create(&thread1, NULL, thread_fn_callback, (void*)thread_input1);

    if(rc != 0) {
        printf("Error occured, thread could not be created, errno = %d\n", rc);
        exit(0);
    }
}

int main(int argc, char* argv[]) {
    thread1_create();
    printf("Main function paused\n");
    
    pthread_exit(0);    //  if we use pthread_exit(0), it just terminate the thread which is calling without affecting other threads in our case it terminates the main thread safely and didnt affect the child thread
    printf("Done\n");   //  this wont print in the termainal because the main terminates in the line where pthread_exit(0) in called, also we can see clearly that child thread runs without any effect.
}
