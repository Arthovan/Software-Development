#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/* ---------------- SEMAPHORE STRUCT ---------------- */

typedef struct {
    int count;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} semaphore_t;

/* ---------------- SEMAPHORE FUNCTIONS ---------------- */

void sem_init_custom(semaphore_t *sem, int value) {
    sem->count = value;
    pthread_mutex_init(&sem->mutex, NULL);
    pthread_cond_init(&sem->cond, NULL);
}

void sem_wait_custom(semaphore_t *sem) {
    pthread_mutex_lock(&sem->mutex);
    while (sem->count == 0) {
        pthread_cond_wait(&sem->cond, &sem->mutex);
    }
    sem->count--;
    pthread_mutex_unlock(&sem->mutex);
}

void sem_signal_custom(semaphore_t *sem) {
    pthread_mutex_lock(&sem->mutex);
    sem->count++;
    pthread_cond_signal(&sem->cond);
    pthread_mutex_unlock(&sem->mutex);
}

void sem_destroy_custom(semaphore_t *sem) {
    pthread_mutex_destroy(&sem->mutex);
    pthread_cond_destroy(&sem->cond);
}

/* ---------------- DEMO: PRODUCER–CONSUMER ---------------- */

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0;

semaphore_t empty_slots; // counts empty buffer spaces
semaphore_t full_slots;  // counts full buffer spaces
pthread_mutex_t buffer_lock;

/* Producer thread */
void *producer(void *arg) {
    for (int i = 0; i < 10; i++) {
        sem_wait_custom(&empty_slots); // Wait for empty slot
        pthread_mutex_lock(&buffer_lock);

        buffer[count++] = i;
        printf("Producer produced item %d (buffer count = %d)\n", i, count);

        pthread_mutex_unlock(&buffer_lock);
        sem_signal_custom(&full_slots); // Signal that a slot is full
        sleep(1);
    }
    return NULL;
}

/* Consumer thread */
void *consumer(void *arg) {
    for (int i = 0; i < 10; i++) {
        sem_wait_custom(&full_slots); // Wait for full slot
        pthread_mutex_lock(&buffer_lock);

        int item = buffer[--count];
        printf("Consumer consumed item %d (buffer count = %d)\n", item, count);

        pthread_mutex_unlock(&buffer_lock);
        sem_signal_custom(&empty_slots); // Signal an empty slot
        sleep(2);
    }
    return NULL;
}

/* ---------------- MAIN ---------------- */

int main() {
    pthread_t prod, cons;

    pthread_mutex_init(&buffer_lock, NULL);
    sem_init_custom(&empty_slots, BUFFER_SIZE);
    sem_init_custom(&full_slots, 0);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy_custom(&empty_slots);
    sem_destroy_custom(&full_slots);
    pthread_mutex_destroy(&buffer_lock);

    return 0;
}
