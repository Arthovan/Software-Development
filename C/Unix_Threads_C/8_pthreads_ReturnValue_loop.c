#include<stdio.h>
#include<stdlib.h>
#include<time.h>    //  time() function is here
#include<unistd.h>  //  contains sleep function, mostly contains linux realted stuffs
#include<pthread.h> //  library contains the pthreads
#include<sys/wait.h>    //  Thread 
#include<sys/types.h>   // Thread

pthread_mutex_t mutex;

void * rollDice(void* arg){
    pthread_mutex_lock(&mutex);

    int *results = (int*)malloc(sizeof(int));   // I have to return the thread value to main function, I cant return local varible as it gonna die, so am using the heap memory here    
    *results = (rand() % 6) + 1;    //  rand() generates a random number and % 6 gives values from 0 to 5 but we need from 1 to 6 for Dice, so only +1 at the end
    printf("Thread result variable address : %p\n",results);
    printf("Thread result variable value : %d\n",*results);
    
    pthread_mutex_unlock(&mutex);
    return (void*)results;    
}

int main(int argc, char* argv[]){
    int *res, *val[6];
    srand(time(NULL));
    pthread_t t[6];
    pthread_mutex_init(&mutex,NULL);

    for(int i =0;i<6;i++){
        if(pthread_create(&t[i],NULL,rollDice,NULL)){
            return 1;
        }
    }
    for(int i =0;i<6;i++){
        // as pthread_join() second argument is the return value from rollDice thread, we need a pointer variable there.
        if(pthread_join(t[i],(void**)&res) != 0){ // pthread_join returns 0 on successfull joining of the thread, if fails we get non zero value
            return 2;
        }
        val[i] = res;   //  bcs we are receiving 6 threads address in res so we need to store it effectively in the local pointer array to see the exact value in threas
    }

    for(int i =0;i<6;i++){
        printf("Main res variable address : %p\n",val[i]);
        printf("Main res variable value: %d\n", *val[i]);
    }
    // Allocating DM in another function and free() it in another function is not a proper method in larger scale software development. We will see in future code how we can avoid this
    free(res); 
    pthread_mutex_destroy(&mutex); 
    return 0;
}
