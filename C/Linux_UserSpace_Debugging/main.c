#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[]){
	char* buf;
	buf = (char*)malloc(1<<31); // 2^31 of data we are trying allocate, which in turn cause a segmentation fault
	fgets(buf,1024,stdin);
	printf("%s\n",buf);
	return 0;
}

