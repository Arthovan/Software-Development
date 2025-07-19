/* Create a pthread which will wait for all threads to finish then terminate the program
Note : Inorder to finish the thread and main has to wait, for that we have to use the pthread_join function
*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>      //  contains sleep function, mostly contains linux realted stuffs
#include<pthread.h>     // library contains the pthreads

// Thread function : it returns void pointer and receives void pointer as argument
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
    pthread_t t1;   // pthread variable which will store thread realted information
    pthread_create(&t1,NULL,routine_One,NULL);  //  creating the pthread
    normal_Function();
    pthread_join(t1,NULL);
    return 0;
    // We can see clearly while executing this program that main() waits for thread to 
    // complete unlike the previous program which before thread completion
}
