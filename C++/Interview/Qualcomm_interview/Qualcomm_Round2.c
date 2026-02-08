/* Questions asked :    1.  Mostly questions came from project working experience like 
							a.Multicore, Dual core architecture, 
							b. Lauterbauch and Trace32 debug related questions and ELF file loading process in Lauterbach and internal operations
							c. RTOS working experience and Vtune related questions
						2. 	Thread program question minimal pseudo code and questions realted to it */

/** Write a program in C which has 2 functions (which will be invoked into 2 threads) 
func1 writes data to a shared memory and func2 should read the data & print it.
It is allowed to use minimal pseudo code to avoid exact syntax. **/

#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

int sharedData = 0;
bool dataReady = false;

pthread_t producerThread, consumerThread;
pthread_mutex_t mutex;
pthread_cond_t cond;

void* producer(void* args) {
	pthread_mutex_lock(&mutex);
	sharedData++;
	dataReady = true;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mutex);
	return NULL;
}

void* consumer(void* args) {
	pthread_mutex_lock(&mutex);
	while(!dataReady) {
		pthread_cond_wait(&cond,&mutex);
	}
	printf("Shared Data : %d\n",sharedData);
	pthread_mutex_unlock(&mutex);
}

int main() {
	pthread_mutex_init(&mutex, NULL);

    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
    return 0;
}
 