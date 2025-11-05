/*********************** Read  Write Lock *********************
This examople is implemented with the below considerations 

*   A read-write lock allows multiple readers to hold the lock simultaneously (shared access).

*   Only one writer to hold the lock at a time (exclusive access).

*   Writers have priority if they are waiting (this version supports writer preference).

***********************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

typedef struct rwlock_{
    pthread_mutex_t mutex;
    pthread_cond_t readers;  // Condition variable for readers
    pthread_cond_t writers;  // Condition variable for writers
    int active_readers;      // Number of readers currently holding the lock
    int active_writers;      // Number of writers currently holding the lock (0 or 1)
    int waiting_writers;     // Number of writers waiting
}rwlock_t;

/* Initialize the read-write lock */
void rwlock_init(rwlock_t *rw) {
    pthread_mutex_init(&rw->mutex, NULL);
    pthread_cond_init(&rw->readers, NULL);
    pthread_cond_init(&rw->writers, NULL);
    rw->active_readers = 0;
    rw->active_writers = 0;
    rw->waiting_writers = 0;
}

/* Acquire read lock */
void rwlock_read_lock(rwlock_t *rw) {
    pthread_mutex_lock(&rw->mutex);
    while(rw->active_writers > 0 || rw->waiting_writers > 0) {
        pthread_cond_wait(&rw->readers,&rw->mutex);
    }
    rw->active_readers++;  //  we are updating the readers only when the writer or writer waiting is not available
    pthread_mutex_unlock(&rw->mutex);
}

/* Release read lock */
void rwlock_read_unlock(rwlock_t *rw) {
    pthread_mutex_lock(&rw->mutex);
    rw->active_readers--;
    if(rw->active_readers == 0) {
        pthread_cond_signal(&rw->writers);
    }
    pthread_mutex_unlock(&rw->mutex);
}

/* Acquire write lock */
void rwlock_write_lock(rwlock_t *rw) {
    pthread_mutex_lock(&rw->mutex);
    rw->waiting_writers++;  //  before predicate condition writer (waiting_writers) should be in waiting state
    while(rw->active_readers > 0 || rw->active_writers > 0) { // once predicate fails then only waiting_writer should become 0
        pthread_cond_wait(&rw->writers,&rw->mutex);
    }
    rw->waiting_writers--;
    rw->active_writers = 1; //  current active_writers is 1 now
    pthread_mutex_unlock(&rw->mutex);
}

/* Release write lock */
void rwlock_write_unlock(rwlock_t *rw) {
    pthread_mutex_lock(&rw->mutex);
    rw->active_writers = 0; //  current active_writers is 0 now
    if(rw->waiting_writers > 0) { 
        pthread_cond_signal(&rw->writers);
    } else {
        pthread_cond_broadcast(&rw->readers);
    }
    pthread_mutex_unlock(&rw->mutex);
}

/* Destroy the read-write lock */
void rwlock_destroy(rwlock_t *rw) {
    pthread_mutex_destroy(&rw->mutex);
    pthread_cond_destroy(&rw->readers);
    pthread_cond_destroy(&rw->writers);
}

/* ---------------- DEMO ---------------- */

rwlock_t lock;
int shared_data = 0;

void *reader(void *arg) {
    int id = *(int *)arg;
    rwlock_read_lock(&lock);
    printf("Reader %d: read %d\n", id, shared_data);
    rwlock_read_unlock(&lock);
    return NULL;
}

void *writer(void *arg) {
    int id = *(int *)arg;
    rwlock_write_lock(&lock);
    shared_data += 10;
    printf("Writer %d: wrote %d\n", id, shared_data);
    rwlock_write_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t r1, r2, w1, w2;
    rwlock_init(&lock);

    static int id1 = 1, id2 = 2, id3 = 3, id4 = 4;

    pthread_create(&r1, NULL, reader, &id1);
    pthread_create(&w1, NULL, writer, &id2);
    pthread_create(&r2, NULL, reader, &id3);
    pthread_create(&w2, NULL, writer, &id4);

    pthread_join(r1, NULL);
    pthread_join(w1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w2, NULL);

    rwlock_destroy(&lock);
    return 0;
}