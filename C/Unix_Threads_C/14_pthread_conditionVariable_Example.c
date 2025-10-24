/* Example project of trylock in the mutex */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<pthread.h>

// chefs  =  threads
// stove  =  shared data (+mutex)

pthread_mutex_t stoveMutex[4];
int stoveFuel[4] = {100,100,100,100};

void* routine(void* args){
    for(int i = 0; i< 4; i++){
        if(pthread_mutex_trylock(&stoveMutex[i]) == 0){ // on successfull lock ,mutex returns 0 so we are executing this below code on successfull lock
            int fuelNeeded = (rand() % 30);
            if(stoveFuel[i] - fuelNeeded < 0){
                printf("No more fuel... going home\n");
            }else{
                stoveFuel[i] -= fuelNeeded;
                usleep(500000);
                printf("Fuel left %d\n", stoveFuel[i]);
            }
            pthread_mutex_unlock(&stoveMutex[i]);
            break;              //  each mutex for each thread so we are giving break 
        } else { // if we just use above if conditional statement only 4 threads will execute at it has only 4 mutex and all 4 might have been locked by 4 threads so remaining 6 threads wont get a chance to execute
            // inorder to avoid that we are creating a else statement and restart the for loop after some delay so mutex will be unlocked so that we can use the 4 mutex again and so on
            if(i == 3){
                printf("No stove available yet, waiting... \n");
                usleep(300000);
                i = 0;
            }
        }
    }
    return NULL;
}

int main(int argc, char*argv[]){
    srand(time(NULL));
    pthread_t thread[10];

    for(int i = 0; i < 4; i++){
        pthread_mutex_init(&stoveMutex[i], NULL);
    }
    pthread_mutex_init(&stoveMutex[4],NULL);

    for(int i = 0; i < 10; i++){
        if(pthread_create(&thread[i], NULL, &routine, NULL) != 0){
            perror("Failed to create thread");
        }
    }

    for(int i = 0; i < 10; i++){
        if(pthread_join(thread[i], NULL) != 0){
            perror("Failed to join thread");
        }
    }

    for(int i = 0; i < 4; i++){
        pthread_mutex_destroy(&stoveMutex[i]);
    }
    return 0;
}
