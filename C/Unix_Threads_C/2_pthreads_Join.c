/* Create a pthread which will wait for all threads to finish then terminate the program
Note : Inorder to finish the thread and main has to wait, for that we have to use the pthread_join function

Thread Termination : A thread can terminate in 3 ways 
    1. Thread finishes is execution and return to main 
*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>      //  contains sleep function, mostly contains linux realted stuffs
#include<pthread.h>     // library contains the pthreads

// Thread function : it returns void pointer and receives void pointer as argument
void* routine_One(void* arg){       
    for(int i = 0;i < 5;i++){
        sleep(1);
        printf("Routine One is Running %d\n",i);
    }
    //  1. Thread finishes is execution and return to main
    return NULL;
}

// Normal Function in C
void normal_Function(void){
    for(int i=0;i<2;i++){
        sleep(1);
        printf("Normal Function is Running %d\n",i);
    }
}

int main(int argc, char* argv[]){
    pthread_t t1;   // pthread variable which will store thread realted information
    pthread_create(&t1,NULL,routine_One,NULL);  //  creating the pthread
    normal_Function();
    pthread_join(t1,NULL);
    // pause(); //we can use the pause function to halt the main function here so that the child can execute but main then wont terminate. We have to terminate forcibly. Instead we can use pthread_join to wait for thread exit then terminate the main() 
    return 0;
    // We can see clearly while executing this program that main() waits for thread to 
    // complete unlike the previous program which before thread completion
}
