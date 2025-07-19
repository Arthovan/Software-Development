#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>    // contains the wait function


int main(int argc, char* argv[]){
    // Our goal is to print the numbers from 1 to 5 in child process and 6 to 10 in main process
    int id = fork();     // This will create child process + the current main process
    int n = 1;
    if(id == 0){
        n = 1;
    } else {
        n = 6;
    }
    if(id != 0){
       // Since we've already used fork(), the wait() function will be executed in both the main and child processes. 
       // However, in our program, the child process does not have any further child processes, which will just return -1 as the child has no child. 
       // Therefore, we check if the process ID belongs to the main process before calling the wait() function.
        wait(NULL); // The main process will wait until one of its child processes terminates. When a child process terminates, the wait() function returns the process ID of the terminated child. 
        // If there are no child processes to wait for, the function returns -1.
    }
    for(int i = n;i < n+5;i++){
        printf("%d ",i);
        fflush(stdout);
    }
    if(id != 0){
    printf("\n");
    }
}
