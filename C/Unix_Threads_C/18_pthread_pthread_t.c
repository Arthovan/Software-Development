#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/syscall.h> //  SYS_gettid() is here

#define THREAD_NUM 2

void* routine(void* args){
    // Usually we shouldnt print the pthread_t, as the specification of the pthread API
    // mentioned that pthread_t should be treated as opaque data type
    // which means that pthread_t is not always gonna be the unsigned long it can be of unsigned long char or something
    pthread_t th = pthread_self(); // this is realted to phread_t API implementation so its no where related to OS
    printf("%ld\n",th);

    // like pthread_t value, we can also get thread id in linux systems
    // using syscall
    printf("%d\n",(pid_t)syscall(SYS_gettid)); // gettid is realted to OS 
    return NULL;
}

int main(int argc, char*argv[]){
    // format of pthread_t in header file is (typedef unsigned long pthread_t)
    pthread_t thread[THREAD_NUM];  
    int i;
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_create(&thread[i],NULL,&routine,NULL) != 0){
            perror("Failed to create thread");
        }
        // Usually we shouldnt print the pthread_t, as the specification of the pthread API
        // mentioned that pthread_t should be treated as opaque data type
        // which means that pthread_t is not always gonna be the unsigned long it can be of unsigned long char or something
        printf("%ln\n",thread);
    }
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("Failed to join thread");
        }
    }
   return 0; // we may get field to join thread : Success bcs the main process finished before the thread even complete 
}
