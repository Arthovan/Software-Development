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

// Thread function : it returns void pointer and receives void pointer as argument
void* routine_One(void* arg){       
    for(int i = 0; i < 5; i++){
        sleep(1);
        printf("Routine One is Running %d\n",i);
    }
    /***********    1. Thread finishes its execution and return to main ***********/
    return NULL;
}

void* routine_Two(void* arg){       
    for(int i = 0; i < 10; i++){
        sleep(1);
        printf("Routine One is Running %d\n",i);
        if(a == 5){
            /***********    2. By calling the pthread_exit(0) API  ***********/
            pthread_exit(0);
        }
    }
    
    return NULL;
}

int main(int argc, char* argv[]){
    pthread_t t1;   // pthread variable which will store thread realted information
    pthread_create(&t1,NULL,routine_One,NULL);  //  creating the pthread

    pthread_join(t1,NULL);
    // pause(); //we can use the pause function to halt the main function here so that the child can execute but main then wont terminate. We have to terminate forcibly. Instead we can use pthread_join to wait for thread exit then terminate the main() 
    return 0;
    // We can see clearly while executing this program that main() waits for thread to complete 
}
