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

pthread_mutex_t mutexBuffer;

void* producer(void* args){
    while(1){ // without while loop program works fine
        // Produce
        int x = rand() % 100;

        // Add to the buffer
        pthread_mutex_lock(&mutexBuffer);   // Mutex added to avoid deadlock 
        if(count < 10){ // this is added to make sure to add elements only when the buffer is not full, this is not an optimal solution yet
            buffer[count] = x;
            count++;
        }else { // we can clearly see that most of the numbers were skipped bcs of the above condition and we can see the best solution in the upcoming codes
            printf("Skipped %d\n",x);
        }
        pthread_mutex_unlock(&mutexBuffer);
    }
    return NULL;
}

void* consumer(void* args){
    while(1){ // without while loop program works fine
        int y = -1;
        // Remove from the buffer
        pthread_mutex_lock(&mutexBuffer);
        if(count > 0){  // this is added to make sure to remove only elements only the buffer is not empty
            y = buffer[count - 1]; // accessing the last element in the buffer
            count--;
        }
        pthread_mutex_unlock(&mutexBuffer);

        // Consume
        printf("Got %d\n", y);
        
    }
    return NULL;
}


int main(int argc, char* argv[]){
    srand(time(NULL));
    pthread_t thread[THREAD_NUM];
    pthread_mutex_init(&mutexBuffer, NULL);
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
    pthread_mutex_destroy(&mutexBuffer);
    return 0;
}
