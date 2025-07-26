#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define LOGIC3
pthread_mutex_t mutexFuel;
pthread_cond_t condFuel; 
int fuel = 0;

void* filling_Fuel(void* arg){
    for(int i = 0;i < 5;i++){
        pthread_mutex_lock(&mutexFuel);
        fuel += 15;
        printf("Filled fuel.... %d\n",fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_signal(&condFuel); //  Signalling to one thread that is waiting for the response from this thread
        sleep(1);
    }
    return NULL;
}

void* car(void* arg){
    #ifdef LOGIC3
    pthread_mutex_lock(&mutexFuel);
    while(fuel < 40){
        printf("No Fuel. Waiting....\n");
        pthread_cond_wait(&condFuel,&mutexFuel);    //  waiting for the thread which has mutexFuel mutex variable in it, this wait should receive the signal from it to continue
        // pthread_cond_wait(&condFuel,&mutexFuel) is Equivalent to :
        // pthread_mutex_unlock(&mutexFuel);
        // wait for siganl on condFuel
        // pthread_mutex_lock(&mutexFuel);
        sleep(1);
    }
    fuel -= 40;
    printf("Got fuel. Now left : %d\n", fuel);  
    pthread_mutex_unlock(&mutexFuel);

    #endif
    
    #ifdef LOGIC2
    // This code also wont work and will stuck in the while loop forever as the mutex is locked and fuel value never changes
    pthread_mutex_lock(&mutexFuel);
    while(fuel < 40){
        printf("No Fuel. Waiting....\n");
        sleep(1);
    }
    fuel -= 40;
    printf("Got fuel. Now left : %d\n", fuel);  
    pthread_mutex_unlock(&mutexFuel);
    #endif

    #ifdef LOGIC1
    // This code also not work as per our needs
    pthread_mutex_lock(&mutexFuel);
    if(fuel >= 40){
        fuel -= 40;
        printf("Got fuel. Now left : %d\n",fuel);
    }else{
        printf("No Fuel\n");
    }    
    pthread_mutex_unlock(&mutexFuel);
    #endif
    return NULL;
}

int main(int argc, char* argv[]){
    pthread_t thread[2];
    pthread_mutex_init(&mutexFuel,NULL);
    pthread_cond_init(&condFuel,NULL);
    for(int i = 0;i < 2; i++){
        if(i == 1){
            pthread_create(&thread[i],NULL,&filling_Fuel,NULL);
        }
        else{
            pthread_create(&thread[i],NULL,&car,NULL);
        }
    }
    for(int i = 0;i < 2; i++){
            pthread_join(thread[i],NULL);
    }
    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);
    return 0;
}

