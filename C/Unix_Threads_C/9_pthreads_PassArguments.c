#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int primes[10] = {2,3,5,7,11,13,17,19,23,29};

void* routine(void* arg){
    int index = *(int*)arg;
    printf("%d ",primes[index]);
    free(arg);
    return NULL;
}
int main(int argc, char*argv[]){
    pthread_t task[10];

    for(int i = 0;i < 10;i++){
        // if we send the iterator "i" directly to pthread_create () then we will get some random values at the thread so to avoid that we are allocating a memory in heap and sending 
        // the fourth argument is reference to the variable in main(), so only we are getting errors as reference is changing and didnt catch the value properly while doing the pthread_join()
        int* a = (int*)malloc(sizeof(int));
        *a = i;
        // Passsing the index to the routine thread
        if(pthread_create(&task[i],NULL,&routine,a) != 0){
            perror("Failed to create a thread");
        }
    }
    for(int i = 0;i < 10;i++){
        if(pthread_join(task[i],NULL) != 0){
            perror("Failed to join a thread");
        }
    }
    printf("\n");
    return 0;
}
