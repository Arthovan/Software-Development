#include <stdio.h>
#include <stdint.h>

#define FUNCTION 4

/* Reverse the given input bits*/
int reverseBits(int value) {
    uint32_t reverse = 0;
    for(int i = 0; i < 32; ++i) {
        reverse = (reverse << 1) | (value & 1);
        value >>= 1;
    }
    printf("%s :",__func__); // this is just to print this function name
    return reverse;
}

/* change the even bits in a given number to zero*/
long long int  changeBits(long long int value) {
    printf("%s :",__func__); // this is just tyo print this function name
    return (value & 0xAAAAAAAA);
}

/* count the number of set bits in a given number*/
int setBits(int value) {
    int count = 0;
    while(value) {
        count++;
        value = value & (value -1);
    }
    printf("%s :",__func__); // this is just tyo print this function name
    return count;
}

int swapNibble(unsigned char value){
    return ((0x0F & value) <<4 | (0xF0 & value) >>4);
}
int main(int argc, char* argv[]) {
    int value = 0;
    unsigned char val;
    printf("Enter the number : ");
    scanf("%d",&value);
    if(FUNCTION == 1)       printf(" %d\n", reverseBits(value));
    else if(FUNCTION == 2)  printf(" %lld\n", changeBits(value));
    else if(FUNCTION == 3)  printf(" %d\n", setBits(value));
    else if(FUNCTION == 4){
        getchar();
        printf("Enter the characeter : ");
        scanf("%c",&val);
        printf("Reverse of character is : %d\n", swapNibble(val));
    }
    else ;;
    return 0;
}