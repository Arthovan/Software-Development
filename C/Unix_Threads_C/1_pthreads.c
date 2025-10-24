/* Create a pthread and try to check the behaviour in real time

Note:   This program terminates even before the thread finishes bcs main exit, 
        Inorder to finish the thread and main has to wait, this we will see in next program
*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>  //  contains sleep function and linux related stuffs
#include<pthread.h> //  library contains the pthreads

/* Thread function : it returns void pointer and receives void pointer as argument. Syntax : void* (*thread_fn)(void *)  */
void* routine_One(void* arg){       
    for(int i=0;i<5;i++){
        sleep(1);
        printf("Routine One is Running %d\n",i);
    }
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
    /*pthread_t =>  opaque object, where we dont need to bother about its internal members
    t1          =>  thread handler or variable of pthread_t */
    pthread_t t1;   // pthread variable which will store thread related informations
    /*  pthread_create returns 0 on success, otherwise return errorcode, all pthread functions return -ve error code on failure. It doesnt set "errno" variable */
    pthread_create(&t1,NULL,routine_One,NULL);  //  creating the pthread
    normal_Function();
    return 0;
}
