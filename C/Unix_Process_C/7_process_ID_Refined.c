#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>    // contains the wait function


int main(int argc, char* argv[]){
    int id = fork();     // This will create child process + the current main process

    if(id == 0){
        sleep(1); // sleep for 1 second in the child process, by this we are making the child alive even after parent dies. As there is no delay in parent
    }
    // so the below function will print the different parent ID, as parent dies already. So the child is assigned to different parent. This child is called as "Zombie Process"
    printf("Current ID: %d, Parent ID: %d \n",getpid(),getppid());
    // To avoid this zombie process we can use wait() function to make to child process complete first then exit the parent process
     //comment this conditional statement with wait() first and uncomment to see the zombie process 
    //-------- wait returns -1 if there is no child
    int res = wait(NULL);
    if(res == -1)
    {
        printf("No children to wait for\n");    //  this will be printed by child process, as child has no further child
    } else {
        printf("%d finished execution\n",res);  //  this will be executed by parent process, with the child PID
    }
       return 0;
}
