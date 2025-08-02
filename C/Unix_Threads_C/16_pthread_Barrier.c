#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>

pthread_barrier_t barrier;

void* routine(void *args){
    printf("Waiting at the barrier...\n");
    sleep(1);
    // barrier will wait for number of thread to wait and then executes the remaining piece of code. 
    pthread_barrier_wait(&barrier);
    printf("We passed the barrier\n");
    sleep(1);
    return NULL;
}
int main(int argc, char*argv[]){
    pthread_t thread[3];
    int i;
    pthread_barrier_init(&barrier,NULL,3);  // as we used 3 , then the barrier will wait for 3 thread to be in wait state then it will execute the remaining piece of code
    for(int i = 0; i < 3; i++){
        if(pthread_create(&thread[i], NULL, &routine, NULL) != 0){
            perror("Failed to create thread");
        }
    }
    for(int i = 0; i < 3; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("Failed to join thread");
        }
    }
    pthread_barrier_destroy(&barrier);
    return 0;
}
