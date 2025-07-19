#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[]){
    /*------------ Memcmp--------------*/
    int arr1[] = {1,2};   //  it has four bytes *2 so 8 bytes with data 0x0001, 0x0002
    int arr2[] = {1,2};   //  it has four bytes *2 so 8 bytes with data 0x0001, 0x0002
    // memcpy compares with the size then read those size data, so 8 bytes against 8 (2*sizeof(int)) bytes so we got same data
    if(memcmp(arr1,arr2, 2*sizeof(int)) == 0){
        printf("Arrays are the same\n");
    }
    else{
        printf("Arryas are not the same\n");
    }
    int arr3[] = {3,4};   //  it has four bytes *2 so 8 bytes with data 0x0001, 0x0002
    short int arr4[] = {3,4};   //  it has 2 bytes *2 so 4 bytes with data 0x01, 0x02
    // memcpy compares with the size then read those size data, so 4 bytes against 4 (2*sizeof(short int))bytes so we got different  data
    if(memcmp(arr3,arr4, 2*sizeof(short int)) == 0){
        printf("Arrays are the same\n");
    }
    else{
        printf("Arryas are not the same\n");
    }

    /*------------------Memcpy----------------*/
    memcpy(arr1,arr3,2*sizeof(int));    // copy to arr1 from arr3 of 8 bytes of data
    printf("%d %d\n",arr1[0],arr1[1]);
    return 0;
}