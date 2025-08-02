#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel; 
int fuel = 0;

void* filling_Fuel(void* arg){
    for(int i = 0;i < 5;i++){
        pthread_mutex_lock(&mutexFuel);
        fuel += 30; //  if we use 15 then it will create issues bcs of math where we are reducing by 40 and increasing only by 15 here
        printf("Filled fuel.... %d\n",fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_broadcast(&condFuel); //  Signalling to all thread that are waiting for the response from this thread
        sleep(1);
    }
    return NULL;
}

void* car(void* arg){
    pthread_mutex_lock(&mutexFuel);
    while(fuel < 40){
        printf("No Fuel. Waiting....\n");
        pthread_cond_wait(&condFuel,&mutexFuel);    //  waiting for the thread which has mutexFuel mutex variable in it, this wait should receive the signal from it to continue
        // pthread_cond_wait(&condFuel,&mutexFuel) is Equivalent to :
        // pthread_mutex_unlock(&mutexFuel);
        // wait for siganl on condFuel
        // pthread_mutex_lock(&mutexFuel);
    }
    fuel -= 40;
    printf("Got fuel. Now left : %d\n", fuel);  
    pthread_mutex_unlock(&mutexFuel);
    return NULL;
}

int main(int argc, char* argv[]){
    pthread_t thread[6];
    pthread_mutex_init(&mutexFuel,NULL);
    pthread_cond_init(&condFuel,NULL);
    for(int i = 0;i < 6; i++){
        if(i == 4 || i == 5){
            if(pthread_create(&thread[i],NULL,&filling_Fuel,NULL) != 0)
                perror("Failed to create a thread");
        }
        else{
            if(pthread_create(&thread[i],NULL,&car,NULL) != 0)
                perror("Failed to create a thread");
        }
    }
    for(int i = 0;i < 6; i++){
        if(pthread_join(thread[i],NULL) != 0)
             perror("Failed to join a thread");

    }
    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);
    return 0;
}

