#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/wait.h>    //  Thread 
#include<sys/types.h>   // Thread

#define PROCESS

// Execute thread and process function code separetly to see the differences
//------------------- Thread Function code -----------------//
#ifdef THREADS 
int x = 2;
void* routine1(void *arg){
    x = x+5;
    sleep(2);
    // we will get same process id, because threads are part of process, where multiple threads can be of single process
    printf("Process id %d\n",getpid()); 
    // As the thread shares the same file space, we can see the value of x is same in both routine1 and routine 2
    printf("Value of x : %d\n",x);
    return NULL;
}

void* routine2(void *arg){
    sleep(2);
    printf("Process id %d\n",getpid());
    // As the thread shares the same file space, we can see the value of x is same in both routine1 and routine 2
    printf("Value of x : %d\n",x);
    return NULL;
}

int main(int argc,char* argv[]){
    pthread_t t1,t2;
    if(pthread_create(&t1,NULL,routine1,NULL)){
        return 1;
    }
    if(pthread_create(&t2,NULL,routine2,NULL)){
        return 2;
    }
    if(pthread_join(t1,NULL)){
        return 3;
    }
    if(pthread_join(t2,NULL)){
        return 3;
    }
    return 0;
}
#endif

#ifdef PROCESS
//------------------- Process Function code -----------------//

int main(int argc, char* argv[]){
    int x = 2;
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    // As the process shares the different file space, we can see the value of x is differnt in both parent and child process
    if(pid == 0){
        x++;
    }
    sleep(2);
    printf("Process id %d\n",getpid()); // we can get different process id for child and parent
    printf("Value of x: %d\n",x);
    if(pid != 0){
        wait(NULL);
    }
    return 0;
}
#endif
