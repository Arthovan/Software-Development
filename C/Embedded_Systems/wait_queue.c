#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/* ---------------- WAIT QUEUE IMPLEMENTATION ---------------- */

typedef struct wait_queue_ {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int condition;
} wait_queue_t;

/* Initialize a wait queue */
void wait_queue_init(wait_queue_t *wq) {
    pthread_mutex_init(&wq->mutex, NULL);
    pthread_cond_init(&wq->cond, NULL);
    wq->condition = 0;
}

/* Destroy a wait queue */
void wait_queue_destroy(wait_queue_t *wq) {
    pthread_mutex_destroy(&wq->mutex);
    pthread_cond_destroy(&wq->cond);
}

/* Wait until condition is true (blocking) */
void wait_queue_wait(wait_queue_t *wq) {
    pthread_mutex_lock(&wq->mutex);
    while (wq->condition == 0) {
        pthread_cond_wait(&wq->cond, &wq->mutex);
    }
    pthread_mutex_unlock(&wq->mutex);
}

/* Wake up one waiting thread */
void wait_queue_wake_one(wait_queue_t *wq) {
    pthread_mutex_lock(&wq->mutex);
    wq->condition = 1;
    pthread_cond_signal(&wq->cond);
    pthread_mutex_unlock(&wq->mutex);
}

/* Wake up all waiting threads */
void wait_queue_wake_all(wait_queue_t *wq) {
    pthread_mutex_lock(&wq->mutex);
    wq->condition = 1;
    pthread_cond_broadcast(&wq->cond);
    pthread_mutex_unlock(&wq->mutex);
}

/* ---------------- DEMO: PRODUCER / CONSUMER ---------------- */

wait_queue_t wq;
int shared_data = 0;
int data_ready = 0;

void *producer(void *arg) {
    sleep(2); // simulate work
    pthread_mutex_lock(&wq.mutex);
    shared_data = 42;
    data_ready = 1;
    printf("Producer: data produced = %d\n", shared_data);
    pthread_mutex_unlock(&wq.mutex);

    // signal waiting threads
    wait_queue_wake_all(&wq);
    return NULL;
}

void *consumer(void *arg) {
    int id = *(int *)arg;
    printf("Consumer %d: waiting for data...\n", id);

    // Wait for producer signal
    wait_queue_wait(&wq);

    pthread_mutex_lock(&wq.mutex);
    if (data_ready)
        printf("Consumer %d: got data = %d\n", id, shared_data);
    pthread_mutex_unlock(&wq.mutex);
    return NULL;
}

int main() {
    pthread_t prod, cons1, cons2;
    int c1 = 1, c2 = 2;

    wait_queue_init(&wq);

    pthread_create(&cons1, NULL, consumer, &c1);
    pthread_create(&cons2, NULL, consumer, &c2);
    pthread_create(&prod, NULL, producer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons1, NULL);
    pthread_join(cons2, NULL);

    wait_queue_destroy(&wq);
    return 0;
}
