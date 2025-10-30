/*************************************** Example 1 ***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 2
#define TASKS_PER_PRODUCER 5

typedef void (*task_func)(int);

// ------------------ Ring Buffer Structure ------------------
typedef struct {
    task_func buffer[BUFFER_SIZE];
    int args[BUFFER_SIZE];
    int head;
    int tail;
    int count;
    bool done; // Flag to signal no more tasks will be produced
    pthread_mutex_t mutex;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;
} RingBuffer;

RingBuffer queue;

// ------------------ Example Task Functions ------------------
void print_task(int n) {
    printf("[Task] print_task(%d)\n", n);
    usleep(100000);
}

void square_task(int n) {
    printf("[Task] square_task(%d) = %d\n", n, n * n);
    usleep(100000);
}

// ------------------ Ring Buffer Operations ------------------
void init_buffer(RingBuffer *q) {
    q->head = q->tail = q->count = 0;
    q->done = false;
    pthread_mutex_init(&q->mutex, NULL);
    pthread_cond_init(&q->not_full, NULL);
    pthread_cond_init(&q->not_empty, NULL);
}

void destroy_buffer(RingBuffer *q) {
    pthread_mutex_destroy(&q->mutex);
    pthread_cond_destroy(&q->not_full);
    pthread_cond_destroy(&q->not_empty);
}

void enqueue(RingBuffer *q, task_func func, int arg) {
    pthread_mutex_lock(&q->mutex);
    while (q->count == BUFFER_SIZE)
        pthread_cond_wait(&q->not_full, &q->mutex);

    q->buffer[q->tail] = func;
    q->args[q->tail] = arg;
    q->tail = (q->tail + 1) % BUFFER_SIZE;
    q->count++;

    pthread_cond_signal(&q->not_empty);
    pthread_mutex_unlock(&q->mutex);
}

bool dequeue(RingBuffer *q, task_func *func, int *arg) {
    pthread_mutex_lock(&q->mutex);
    while (q->count == 0 && !q->done)
        pthread_cond_wait(&q->not_empty, &q->mutex);

    if (q->count == 0 && q->done) {
        pthread_mutex_unlock(&q->mutex);
        return false; // No more tasks, and producers finished
    }

    *func = q->buffer[q->head];
    *arg = q->args[q->head];
    q->head = (q->head + 1) % BUFFER_SIZE;
    q->count--;

    pthread_cond_signal(&q->not_full);
    pthread_mutex_unlock(&q->mutex);
    return true;
}

// ------------------ Producer / Consumer Threads ------------------
void *producer(void *arg) {
    int id = *(int *)arg;

    for (int i = 0; i < TASKS_PER_PRODUCER; i++) {
        task_func func = (i % 2 == 0) ? print_task : square_task;
        int value = id * 100 + i;
        printf("[Producer %d] producing task %d\n", id, value);
        enqueue(&queue, func, value);
        usleep(200000);
    }

    printf("[Producer %d] done producing.\n", id);
    return NULL;
}

void *consumer(void *arg) {
    int id = *(int *)arg;

    task_func func;
    int val;
    while (dequeue(&queue, &func, &val)) {
        printf("[Consumer %d] executing task %d\n", id, val);
        func(val);
    }

    printf("[Consumer %d] exiting gracefully.\n", id);
    return NULL;
}

// ------------------ Main ------------------
int main() {
    pthread_t producers[NUM_PRODUCERS];
    pthread_t consumers[NUM_CONSUMERS];
    static int prod_ids[NUM_PRODUCERS], cons_ids[NUM_CONSUMERS];

    init_buffer(&queue);

    // Start consumers first
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        cons_ids[i] = i;
        pthread_create(&consumers[i], NULL, consumer, &cons_ids[i]);
    }

    // Start producers
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        prod_ids[i] = i;
        pthread_create(&producers[i], NULL, producer, &prod_ids[i]);
    }

    // Wait for all producers
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producers[i], NULL);
    }

    // Signal consumers that production is done
    pthread_mutex_lock(&queue.mutex);
    queue.done = true;
    pthread_cond_broadcast(&queue.not_empty);
    pthread_mutex_unlock(&queue.mutex);

    // Wait for all consumers
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumers[i], NULL);
    }

    printf("\nAll producers and consumers exited cleanly.\n");
    destroy_buffer(&queue);
    return 0;
}
/*************************************************************************************/

/*********************************** Basic Producer Consumer Examples *****************************/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

typedef struct {
    int buffer[BUFFER_SIZE];
    int count;
    int in;
    int out;
    pthread_mutex_t mutex;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;
} bounded_buffer_t;

bounded_buffer_t bb = {
    .count = 0,
    .in = 0,
    .out = 0,
    .mutex = PTHREAD_MUTEX_INITIALIZER,
    .not_full = PTHREAD_COND_INITIALIZER,
    .not_empty = PTHREAD_COND_INITIALIZER
};

void produce(int item) {
    pthread_mutex_lock(&bb.mutex);
    
    // Wait while buffer is full
    while (bb.count == BUFFER_SIZE) {
        printf("Buffer full, producer waiting...\n");
        pthread_cond_wait(&bb.not_full, &bb.mutex);
    }
    
    // Add item to buffer
    bb.buffer[bb.in] = item;
    bb.in = (bb.in + 1) % BUFFER_SIZE;
    bb.count++;
    
    printf("Produced: %d (buffer count: %d)\n", item, bb.count);
    
    // Signal that buffer is not empty
    pthread_cond_signal(&bb.not_empty);
    
    pthread_mutex_unlock(&bb.mutex);
}

int consume() {
    pthread_mutex_lock(&bb.mutex);
    
    // Wait while buffer is empty
    while (bb.count == 0) {
        printf("Buffer empty, consumer waiting...\n");
        pthread_cond_wait(&bb.not_empty, &bb.mutex);
    }
    
    // Remove item from buffer
    int item = bb.buffer[bb.out];
    bb.out = (bb.out + 1) % BUFFER_SIZE;
    bb.count--;
    
    printf("Consumed: %d (buffer count: %d)\n", item, bb.count);
    
    // Signal that buffer is not full
    pthread_cond_signal(&bb.not_full);
    
    pthread_mutex_unlock(&bb.mutex);
    return item;
}

void* producer_thread(void* arg) {
    for (int i = 1; i <= 10; i++) {
        produce(i);
        usleep(100000); // 100ms
    }
    return NULL;
}

void* consumer_thread(void* arg) {
    for (int i = 0; i < 10; i++) {
        consume();
        usleep(150000); // 150ms
    }
    return NULL;
}
/*************************************************************************************/
