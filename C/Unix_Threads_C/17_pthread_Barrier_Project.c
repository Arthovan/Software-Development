/*Problem : Every thread rolls a dice, saved its value in a n array.
            The main thread calculates the winner then each thread prints
            a message with whether or not they lost or won
*/
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define TWO_BARRIER
#define THREAD_NUM 8

int diceValues[8] = {0};
int status[8] = {0};


#ifdef TWO_BARRIER
pthread_barrier_t barrierRolledDice;
pthread_barrier_t barrierCalculated;

void* rollDice(void* args){
    int index = *(int*)args;
    diceValues[index] = (rand() % 6) + 1; // rand % 6 is from 0 to 5 but I need from 1 to 6, so added +1 at the end
    pthread_barrier_wait(&barrierRolledDice);
    pthread_barrier_wait(&barrierCalculated);
    if(status[index] == 1){
        printf("(%d rolled %d) I won\n",index,diceValues[index]);
    } else{
        printf("(%d rolled %d) I lost\n",index,diceValues[index]);
    }
    free(args);
    return NULL;
}

int main(int argc, char* argv[]){
    srand(time(NULL));
    pthread_t thread[THREAD_NUM];
    pthread_barrier_init(&barrierRolledDice, NULL, THREAD_NUM+1); // bcs we have 8 thread and main thread 
    pthread_barrier_init(&barrierCalculated, NULL, THREAD_NUM+1); // bcs we have 8 thread and main thread 
    int i = 0;
    for(i = 0; i < THREAD_NUM; i++){
        int *a = (int*)malloc(sizeof(int));
        *a = i;
        if(pthread_create(&thread[i],NULL,&rollDice,a) != 0){
            perror("Failed to create a thread");
        }
    }

    pthread_barrier_wait(&barrierRolledDice); // main thread has to wait for all the 8 threads to roll the dice
    // Calculate the winner
    int max = 0;
    for(i = 0; i < THREAD_NUM; i++){
        if(diceValues[i] > max){
            max = diceValues[i];
        }
    }
    for(i = 0; i < THREAD_NUM; i++){
        if(diceValues[i] == max){
            status[i] = 1;
        }else {
            status[i] = 0;
        }
    }
    // exec 2
    pthread_barrier_wait(&barrierCalculated);
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("Failed to join a thread");
        }
    }
    pthread_barrier_destroy(&barrierRolledDice);
    pthread_barrier_destroy(&barrierCalculated);
    return 0;
}
#endif

#ifdef ONE_BARRIER
// This code will execute as expected but there is a catch where exec 2 finishes before rolldice status check
pthread_barrier_t barrierRolledDice;

void* rollDice(void* args){
    int index = *(int*)args;
    diceValues[index] = (rand() % 6) + 1; // rand % 6 is from 0 to 5 but I need from 1 to 6, so added +1 at the end
    pthread_barrier_wait(&barrierRolledDice);
    if(status[index] == 1){
        printf("(%d rolled %d) I won\n",index,diceValues[index]);
    } else{
        printf("(%d rolled %d) I lost\n",index,diceValues[index]);
    }
    free(args);
    return NULL;
}

int main(int argc, char* argv[]){
    srand(time(NULL));
    pthread_t thread[THREAD_NUM];
    pthread_barrier_init(&barrierRolledDice, NULL, THREAD_NUM+1); // bcs we have 8 thread and main thread 
    int i = 0;
    for(i = 0; i < THREAD_NUM; i++){
        int *a = (int*)malloc(sizeof(int));
        *a = i;
        if(pthread_create(&thread[i],NULL,&rollDice,a) != 0){
            perror("Failed to create a thread");
        }
    }

    pthread_barrier_wait(&barrierRolledDice); // main thread has to wait for all the 8 threads to roll the dice
    // Calculate the winner
    int max = 0;
    for(i = 0; i < THREAD_NUM; i++){
        if(diceValues[i] > max){
            max = diceValues[i];
        }
    }
    for(i = 0; i < THREAD_NUM; i++){
        if(diceValues[i] == max){
            status[i] = 1;
        }else {
            status[i] = 0;
        }
    }
    // exec 2
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("Failed to join a thread");
        }
    }
    pthread_barrier_destroy(&barrierRolledDice);
    return 0;
}
#endif

#ifdef NO_BARRIER
// This code wont work as expected because thread has to execute once the 2 "for" loops 
// before the pthread_join finish executing first. But it wont be the case in multithreading 
// we cant predict which executes first
void* rollDice(void* args){
    int index = *(int*)args;
    diceValues[index] = (rand() % 6) + 1; // rand % 6 is from 0 to 5 but I need from 1 to 6, so added +1 at the end
    if(status[index] == 1){
        printf("(%d rolled %d) I won\n",index,diceValues[index]);
    } else{
        printf("(%d rolled %d) I lost\n",index,diceValues[index]);
    }
    free(args);
    return NULL;
}

int main(int argc, char* argv[]){
    srand(time(NULL));
    pthread_t thread[THREAD_NUM];
    int i = 0;

    for(i = 0; i < THREAD_NUM; i++){
        int *a = (int*)malloc(sizeof(int));
        *a = i;
        if(pthread_create(&thread[i],NULL,&rollDice,a) != 0){
            perror("Failed to create a thread");
        }
    }
    int max = 0;
    for(i = 0; i < THREAD_NUM; i++){
        if(diceValues[i] > max){
            max = diceValues[i];
        }
    }
    for(i = 0; i < THREAD_NUM; i++){
        if(diceValues[i] == max){
            status[i] = 1;
        }else {
            status[i] = 0;
        }
    }
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("Failed to join a thread");
        }
    }
    return 0;
}
#endif
