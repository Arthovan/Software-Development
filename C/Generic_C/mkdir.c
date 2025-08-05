#include<stdio.h>
#include<sys/stat.h>	//	mkdir() is defined here
#include<errno.h>		//	perror is defined here

int main(int argc, char*argv[]){
	if(mkdir("demo",0777) == -1){	//	if already directory is there then mkdir return -1 so it wont create a directory "demo" again
		perror("Error");	//	perror will give information why it got error with the string we mentioned here. Ex: Error: < info for error >
		return 1;
	}
	return 0;
}