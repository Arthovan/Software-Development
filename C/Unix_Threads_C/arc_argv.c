/*  run this command like ./a.out <argument 1> <argument 2>
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h> // it contains the strtol function

int main(int argc, char*argv[]){    //  arguments count and argument vector(array of strings)
    int i = 0;
    printf("Count of argc is %d\n",argc);   //  to print the number of arguments given in command line 
    for(int i =0;i<argc;i++){
        printf("argv[%d]: %s\n",i,argv[i]); // to print the array of the arguments given in command line with spaces
    }

    int result = 1;
    for(i=1;i<argc;i++){
        // argv is string and we need to convert it to int so that we can perform multiplication
        int x = strtol(argv[i],NULL,10);
        result *= x;
    }
    printf("Multiplication result is %d\n",result); // for this we need to give numbers after the ./a.out 
    return 0;
}