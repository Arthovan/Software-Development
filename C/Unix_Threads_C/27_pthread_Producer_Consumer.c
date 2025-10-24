/* Things to consider in the producer and cosumer problem
    1. Manage shared memory access ==> Bcs thread access the shared memory so we need to make sure no deadlock occurs there
    2. Checking for if buffer is full ==> If we have 2 producer and 1 consumer then the buffer will be filled soon, so we need to make sure buffer is full or not
    3. Checking for if buffer is empty ==> If we have 1 producer and 2 consumer then the buffer will be accessed even if it is empty so we need to make sure its not empty
*/

// This below program is a basic one of producer, consumer problem. Will see the mutex and semaphore based in the upcoming codes
// Generally producer like web and consumer like server always producing & consuming something, so we need to make sure its running in loop

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>
#include<semaphore.h>

#define THREAD_NUM 2
int buffer[10];
int count = 0;
void* producer(void* args){
    while(1){ // without while loop program works fine
        // Produce
        int x = rand() % 100;

        // Add to the buffer
        buffer[count] = x;
        count++;
    }
    return NULL;
}

void* consumer(void* args){
    while(1){ // without while loop program works fine
        // Remove from the buffer
        int y = buffer[count - 1]; // accessing the last element in the buffer
        count--;
        // Consume
        printf("Got %d\n", y);
    }
    return NULL;
}


int main(int argc, char* argv[]){
    srand(time(NULL));
    pthread_t thread[THREAD_NUM];
    int i;
    for(i = 0; i < THREAD_NUM; i++){
        if(i % 2 == 0){
            if(pthread_create(&thread[i],NULL,&producer,NULL) != 0){
                perror("Failed to create a Thread\n");
            }
        } else {
            if(pthread_create(&thread[i],NULL,&consumer,NULL) != 0){
                perror("Failed to join a Thread\n");
            }
        }
    }
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("Failed to create a Thread\n");
        }
    }
    return 0;
}
