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
    // If we give normal return or exit(0) this main process will exit and thereby thread also wont execute, but if we use pthread_exit in the main process it will wait for the thread to finish first and exit the main 
    // it is used in some usecase 
    // pthread_exit(0);
    if(pthread_join(th,(void**)&res) != 0){
        return 2;
    }
    
    printf("Result : %d\n", *res);
    return 0;
}
