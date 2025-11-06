#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/* Shared data */
int shared_data = 0;
int data_ready = 0;

/* Synchronization primitives */
pthread_mutex_t mutex;
pthread_cond_t cond;

/* Producer thread: creates data */
void *producer(void *arg) {
    for (int i = 1; i <= 5; i++) {
        sleep(1); // simulate work

        pthread_mutex_lock(&mutex);
        shared_data = i * 10;
        data_ready = 1;
        printf("Producer: produced %d\n", shared_data);

        // Wake up waiting consumer
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

/* Consumer thread: waits for data */
void *consumer(void *arg) {
    for (int i = 1; i <= 5; i++) {
        pthread_mutex_lock(&mutex);

        // Wait until data_ready == 1
        while (!data_ready) {
            pthread_cond_wait(&cond, &mutex);
        }

        // Consume data
        printf("Consumer: consumed %d\n", shared_data);
        data_ready = 0;  // Reset flag

        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

/* Main program */
int main() {
    pthread_t prod_thread, cons_thread;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
