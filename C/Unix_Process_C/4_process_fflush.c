#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    // Our goal is to print the numbers from 1 to 5 in child process and 6 to 10 in main process
    int id = fork();     // This will create child process + the current main process
    int n = 1;
    if(id == 0){
        n = 1;
    } else {
        n = 6;
    }
    for(int i = n;i < n+5;i++){
        printf("%d ",i);
        fflush(stdout);
    }
    printf("\n");
    // We can see clearly that using the fflsuh function to clear the output stream didnt solve this error
    // for this we need to use a wait() function, which will wait until the child process completes
    return 0;
}
