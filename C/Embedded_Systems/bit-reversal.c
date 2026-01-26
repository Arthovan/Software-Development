#include <stdio.h>
#include <stdint.h>

int reverseBits(int value) {
    uint32_t reverse = 0;
    for(int i = 0; i < 32; ++i) {
        reverse = (reverse << 1) | (value & 1);
        value >>= 1;
    }
    return reverse;
}

int main(int argc, char* argv[]) {
    int value = 0;
    printf("Enter the number to be reversed its bits : ");
    scanf("%d",&value);
    printf("After reversing the bits, the value is : %d\n", reverseBits(value));
    return 0;
}