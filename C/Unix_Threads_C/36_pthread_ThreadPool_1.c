/*  Even with the mutex this code doesnt work fine so we will look into the proper code by using cond variable
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define THREAD_NUM 4

typedef struct Task{
    int a,b;
} Task;

Task taskQueue[256];
int taskCount = 0;

pthread_mutex_t mutex;

void executeTask(Task *p){
    int ret = p->a + p->b;
    printf("The sum of %d and %d is %d\n",p->a, p->b, ret);
}

void submitTask(Task task){
    pthread_mutex_lock(&mutex);
    taskQueue[taskCount] = task;
    taskCount++;
    pthread_mutex_unlock(&mutex);
}
void* startThread(void* args){
    while(1){ // the reason why we add while loop in thread pool is bcs of its nature. Where it is always going to execute(either reading or writing) and never gonna finish its execution. 
        Task task;
        int found = 0;
        
        pthread_mutex_lock(&mutex);
        if(taskCount > 0){
            found = 1;
            task = taskQueue[0];
            int i;
            for(i = 0; i < taskCount - 1; i++){
                taskQueue[i] = taskQueue[i + 1]; // we are shifting the queue as the first element is already taken
            }
            taskCount--;
        }

        pthread_mutex_unlock(&mutex);
        
        if(found){
            executeTask(&task);
        }
    }
}

int main(int argc,char*argv[]){
    pthread_t thread[THREAD_NUM];
    pthread_mutex_init(&mutex,NULL);

    int i;
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_create(&thread[i],NULL,&startThread,NULL) != 0){
            perror("Failed to create a thread\n");
        }
    }

    srand(time(NULL));
    for(i = 0; i  < 100; i++){
        Task t = {
            .a = rand() % 100,
            .b = rand() % 100
        };
        submitTask(t);
    }
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(thread[i],NULL) != 0){
            perror("Failed to join a thread\n");
        }
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
