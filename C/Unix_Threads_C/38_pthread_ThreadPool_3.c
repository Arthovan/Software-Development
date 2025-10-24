/*  Even this is a threadpool with a mutex and cond variable but generic one would be 
    with the function pointer which we can see in the upcoming code
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>

#define THREAD_NUM 8

typedef struct Task{
    void (*taskFunction)(int,int);
    int arg1, arg2;
} Task;

Task taskQueue[256];
int taskCount = 0;

pthread_mutex_t mutex;
pthread_cond_t cond;

void SumAndProduct(int a, int b){
    usleep(50000);
    int sum = a + b;
    int prod = a * b;
    printf("Sum and Product of %d and %d is %d and %d respectively\n",a,b,sum,prod);
}

void executeTask(Task *p){
    p->taskFunction(p->arg1,p->arg2);
}

void submitTask(Task task){
    pthread_mutex_lock(&mutex);
    taskQueue[taskCount] = task;
    taskCount++;
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);
}

void* startThread(void* args){
    while(1){ // the reason why we add while loop in thread pool is bcs of its nature. Where it is always going to execute(either reading or writing) and never gonna finish its execution. 
        Task task;

        pthread_mutex_lock(&mutex);
        while(taskCount == 0){
            pthread_cond_wait(&cond, &mutex);
        } // This loop exit only when the taskCount value > 0 so no need of "if" below
        task = taskQueue[0];
        int i;
        for(i = 0; i < taskCount - 1; i++){
            taskQueue[i] = taskQueue[i + 1]; // we are shifting the queue as the first element is already taken
        }
        taskCount--;
        pthread_mutex_unlock(&mutex);
        executeTask(&task);
    }
    return NULL;
}

int main(int argc,char*argv[]){
    pthread_t thread[THREAD_NUM];
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    int i;
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_create(&thread[i],NULL,&startThread,NULL) != 0){
            perror("Failed to create a thread\n");
        }
    }

    srand(time(NULL));
    for(i = 0; i  < 100; i++){
        Task t = {
            .taskFunction = &SumAndProduct,
            .arg1 = rand() % 100,
            .arg2 = rand() % 100
        };
        submitTask(t);
    }
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("Failed to join a thread\n");
        }
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
