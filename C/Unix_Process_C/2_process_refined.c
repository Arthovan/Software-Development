#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    // Typically, when a fork() is called, it creates 2^n processes, where n is the number of fork() calls. 
    // The fork() function returns an integer: 0 for the child process ID and a non-zero value for the parent process ID.
    //  By default, the child process ID is 0. This behavior allows us to use conditional statements to manage the creation of processes effectively.
    
    int id = fork();     // This will create child process + the current main process
    if(id != 0){
        fork(); // this will create only 1 process
    }
    // After this we will have 3 process only 
    printf("Hello world\n");
    /*
    if(id == 0){
        printf("Hello from child process\n");
    }
    else{
        printf("Hello from main process\n");
    }
    */
    return 0;
}
