/*  This below code is not a proper one of task execution in parallel, its just a simple example of template. Do not use this for thread or parallel processing
It is just for illustartion purpose only
Its just normal execution of function
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

void executeTask(Task *p){
    int ret = p->a + p->b;
    printf("The sum of %d and %d is %d\n",p->a, p->b, ret);
}

int main(int argc,char*argv[]){
    Task t = {
            .a = rand() % 100,
            .b = rand() % 100
        };

    executeTask(&t);
    return 0;
}
