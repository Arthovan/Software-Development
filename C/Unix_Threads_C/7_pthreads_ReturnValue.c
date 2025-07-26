#include<stdio.h>
#include<stdlib.h>
#include<time.h>    //  time() function is here
#include<unistd.h>  //  contains sleep function, mostly contains linux realted stuffs
#include<pthread.h> //  library contains the pthreads
#include<sys/wait.h>    //  Thread 
#include<sys/types.h>   // Thread

void * rollDice(void* arg){
    int *results = (int*)malloc(sizeof(int));   // I have to return the thread value to main function, I cant return local varible as it gonna die, so am using the heap memory here
    *results = (rand() % 6) + 1;    //  rand() generates a random number and % 6 gives values from 0 to 5 but we need from 1 to 6 for Dice, so only +1 at the end
    printf("Thread result variable address : %p\n",results);
    printf("Thread result variable value : %d\n",*results);
    return (void*)results;
}

int main(int argc, char* argv[]){
    int *res;
    srand(time(NULL));
    pthread_t t1;
        
    if(pthread_create(&t1,NULL,rollDice,NULL)){
        return 1;
    }
    // as pthread_join() second argument is the return value from rollDice thread, we need a pointer variable there.
    if(pthread_join(t1,(void**)&res) != 0){ // pthread_join returns 0 on successfull joining of the thread, if fails we get non zero value
        return 2;
    }
    printf("Main res variable address : %p\n",&res);    //local pointer variable address 
    printf("Main res variable address : %p\n",res);
    printf("Main res variable value: %d\n", *res);
    // Allocating DM in another function and free() it in another function is not a proper method in larger scale software development. We will see in future code how we can avoid this
    free(res);  
    return 0;
}
