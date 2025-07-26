#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t mutex;

// With this routine the thread 1 will lock and threads from 2 to 4 will wait for thread 1 to release lock
void* routine_lock(void* arg){
    pthread_mutex_lock(&mutex);
    printf("Got Lock\n");
    sleep(1);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

// With this routine the thread 1 will lock and threads from 2 to 4 will check if it is unlocked and if not then executes the other parts of the code in the thread 
void* routine_trylock(void* arg){
    if(pthread_mutex_trylock(&mutex) != 0){ //  trylock returns 0 if it get lock, ifnot then it will throw some non zero value which is EBUSY and it is defined in errno.h header file
        printf("Got Lock\n");
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }
    else{
        printf("Dindnt get the lock\n");
    }
    return NULL;
}

int main(int argc, char*argv[]){
    pthread_t thread[4];
    pthread_mutex_init(&mutex,NULL);
    for(int i = 0; i < 4; i++){
        if(pthread_create(&thread[i],NULL,&routine_trylock,NULL) != 0){
            perror("error at creating thread");
        }
    }
    for(int i = 0; i < 4; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("error at joining thread");
        }
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}
