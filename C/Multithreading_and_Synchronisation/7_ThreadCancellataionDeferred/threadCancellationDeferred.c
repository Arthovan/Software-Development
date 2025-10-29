/*
 * =====================================================================================
 *
 *       Filename:  master_slace.c
 *
 *    Description: This file demonstrates the use of wait and signal APIs 
 *
 *        Version:  1.0
 *        Created:  11/13/2020 12:42:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ABHISHEK SAGAR (), sachinites@gmail.com
 *   Organization:  Juniper Networks
 *
 * =====================================================================================
 */
/* This program creates a 5 threads and all 5 threads write a string into a file  thread_x.txt, where x is thread id.
    String to write - I am thread<thread id>    */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define N_SLAVES	5

pthread_t slaves[N_SLAVES];
void memory_cleanup_handler(void *arg){
	printf("%s invoked....\n",__FUNCTION__);	//	to print this function name
	free(arg);
}

void file_cleanup_handler(void *arg){
	printf("%s invoked....\n",__FUNCTION__);	//	to print this function name
	fclose((FILE*)arg);
}

void *  write_into_file(void *arg){

	char file_name[64];
	char string_to_write[64];
	int len;
	int count = 0;
    /* Mark the thread elligible for cancellation */
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,0);
    /* Mode of cancellation */
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,0);   //  1 : Change for deferred 

	int *thread_id = (int  *)arg;
	/* Resource Leaking prevention by memory Clean Up handler*/
	pthread_cleanup_push(memory_cleanup_handler,arg);	//	Cleanup handler 1

	sprintf(file_name, "thread_%d.txt", *thread_id);

	FILE *fptr = fopen(file_name, "w");

	if(!fptr){
		printf("Error : Could not open log file %s, errno = %d\n",
				file_name, errno);
		//return 0;
		pthread_exit(0);	//	return 0 will not invoke the cleanup handler so we need to use the pthread_exit(0) to invoke it 
	}
	/* Resource Leaking prevention by file Clean Up handler*/
	pthread_cleanup_push(file_cleanup_handler,fptr);	//	Cleanup handler 2

	while(1) {
		len = sprintf(string_to_write, "%d : I am thread %d\n", count++, *thread_id);
		fwrite(string_to_write, sizeof(char), len, fptr);
		fflush(fptr);
		sleep(1);
        // I have used this API below because sprintf,fwrite and fflush have the internal implementation during that execution time if I get a cancel request in asynchronous mode may cause some invarints issue. Inoder to avoid the invariant am choosing this line to test for cancel signal 
        pthread_testcancel();   //  1 : Change for deferred 
	}
	/* Resource Leaking prevention by Clean Up handler*/
	pthread_cleanup_pop(0);	//	Cleanup handler 1
	pthread_cleanup_pop(0);	//	Cleanup handler 2
	return 0; 
}

int main(int argc, char **argv){

	int i;
	int *thread_id = 0;

	for( i = 0; i < N_SLAVES; i++){
	    thread_id = (int*)calloc(1, sizeof(*thread_id));
		*thread_id = i;
		pthread_create(&slaves[i], 0, write_into_file, thread_id);
	}	

	/* main menu */
	int choice;
	int thread_num;

	while(1) {
		
		printf("1. Cancel the thread\n");
		scanf("%d", &choice);
		printf("Enter slave thread id [0-%d] :", N_SLAVES -1);
		scanf("%d", &thread_num);
		if(thread_num < 0 || thread_num >= N_SLAVES) {
			printf("Invalid Thread id\n");
			exit(0);
		}
		printf("\n");
		switch(choice) {

			case 1:
                pthread_cancel(slaves[thread_num]); //  thread cancellation request from main thread
				break;
			default:
				continue;
		}
	}
	return 0;
}