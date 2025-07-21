/*  This project will receive sum the first 5 elements of primes in thread 1 and sum the remaining in thread 2 
then return the results to main()
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int primes[10] = {2,3,5,7,11,13,17,19,23,29};

void* routine(void* arg){
    int index = *(int*)arg;
    int sum = 0;
    for(int j = 0; j < 5; j++){
        sum += primes[index+j];
    }
    printf("Local Sum : %d\n",sum);
    *(int*)arg = sum;
    return arg;
    
}

int main(){
    pthread_t thread[2];
    int i, globalSum = 0;
    for(i = 0; i < 2;i++){
        int *a = (int*)malloc(sizeof(int));
        *a = i * 5; //  first iteration we are sending 0th index of primes and second iteration we are sending 5th index, thereby half of primes are presum in thread 1 and remaining in thread 2
        if(pthread_create(&thread[i],NULL,&routine,a) != 0){
            perror("Failed to create a thread");
        }
    }
    for(i = 0; i < 2;i++){
        int *r;
        if(pthread_join(thread[i],(void**)&r) != 0){
            perror("Failed to join thread");
        }
        globalSum += (*r);
        free(r);
    }
    printf("Global Sum : %d\n",globalSum);
    return 0;
}
