#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    // Generally if we create a fork it will create 2^n process, where n is number of fork()
    fork();     // This will create child process + the current main process
    fork();     //   
    fork();
    fork();
    // After this we will have 16 process where 2^4 = 16 
    printf("Hello world\n");
    return 0;
    // we will see how to create a only main process and child process individually 
    // without 2^n process in next program
}
