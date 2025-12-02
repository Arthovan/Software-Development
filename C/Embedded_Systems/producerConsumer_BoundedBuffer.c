/*********************************** Producer Consumer Bounded Buffer *****************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5

typedef struct {
    int buffer[BUFFER_SIZE];
    int count;
    int in;
    int out;
    pthread_mutex_t mutex;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;
}bounded_buffer_t;

bounded_buffer_t *mb;

void init_buffer(void) {
    // Allocate memory for the buffer structure
    mb = (bounded_buffer_t*)malloc(sizeof(bounded_buffer_t));
    // Initialize all buffer elements to 0
    for(int i = 0; i < BUFFER_SIZE; i++) {
        mb->buffer[i] = 0;
    }

    mb->count = 0;
    mb->in = 0;
    mb->out = 0;

    // Initialize mutex and condition variables
    pthread_mutex_init(&mb->mutex,NULL);
    pthread_cond_init(&mb->not_full,NULL);
    pthread_cond_init(&mb->not_empty,NULL);
}

void destroy_buffer(void) {
    pthread_mutex_destroy(&mb->mutex);
    pthread_cond_destroy(&mb->not_full);
    pthread_cond_destroy(&mb->not_empty);
    free(mb);   // Free allocated memory
}

void call_back_produce(int item) {
    pthread_mutex_lock(&mb->mutex);

    // Wait while buffer is full
    while(mb->count == BUFFER_SIZE) {
        printf("Buffer is full, producer waiting...\n");
        pthread_cond_wait(&mb->not_full, &mb->mutex);
    }
    // Add item to buffer, its keep on going to update the buffer upto the size of BUFFER_SIZE 
    mb->buffer[mb->in] = item;
    mb->in = (mb->in + 1) % BUFFER_SIZE;
    mb->count++;

    printf("Produced : %d (buffer count : %d)\n",item, mb->count);
    
    // Signal that buffer is not empty
    pthread_cond_signal(&mb->not_empty);

    pthread_mutex_unlock(&mb->mutex);
}

int call_back_consume() {
    pthread_mutex_lock(&mb->mutex);

    // Wait while buffer is empty
    while(mb->count == 0) {
        printf("Buffer is empty, consumer waiting...\n");
        pthread_cond_wait(&mb->not_empty, &mb->mutex);
    }
    // remove item from buffer
    int item = mb->buffer[mb->out];
    mb->out = (mb->out + 1) % BUFFER_SIZE;
    mb->count--;

    printf("Consumed : %d (buffer count : %d)\n",item, mb->count);

    // Signal that buffer is not full
    pthread_cond_signal(&mb->not_full);

    pthread_mutex_unlock(&mb->mutex);
    return item;
}

void* producer(void *arg) {
    //int *temp = *(int*)arg;
    //printf("")
    for(int i = 1; i <= 10; i++) {
        call_back_produce(i);
        usleep(10000);
    }
    return NULL;
}

void* consumer(void *arg) {
    for(int i = 1; i <= 10; i++) {
        int item = call_back_consume();
        printf("Item received in consumer is %d\n",item);
        usleep(10000);
    }
    return NULL;
}

int main(int argc, char*argv[]) {
    
    init_buffer();

    pthread_t thread[2];    // 0 is produce and 1 is consumer

    // Create producer and consumer threads
    pthread_create(&thread[0], NULL, producer, NULL);   // Producer
    pthread_create(&thread[1], NULL, consumer, NULL);   // Consumer

    // Wait for both threads to complete
    for(int i = 0; i < 2; i++) {
        pthread_join(thread[i],NULL);
        printf("Thread Joined successfully\n");
    }
    
    destroy_buffer();
    return 0;
}