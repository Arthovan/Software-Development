#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>

/* reverse_hw() function code */
#define REG_VALUE (*(volatile uint32_t *)0x40000000)
/***************************************************/

/*this function simple answer where we can expect a follow up questions like below functions*/
int reverseNumber(int value) {
    int reverse = 0;
    int sign = (value < 0)? -1 : 1;
    value *= sign;

    while(value != 0) {
        reverse = reverse * 10 + (value % 10);
        value /= 10;
    }
    return reverse * sign;
}
 /* reverse a number and also detect if overflow occurs */
int reverseNumber_overflowCheck(int value) {
    int reverse = 0;
    int sign = (value < 0)? -1 : 1;
    value *= sign;
    
    while(value != 0) {
        /* we are chceking with /10 becuase after this overflow occurs in line : 29 during *10 operation, so we are ensuring overlfow will occur after this "if" conditional statement */
        if(reverse > INT_MAX/10 || reverse <= INT_MIN/10) {
            return 0; // Overflow occured
        }
        reverse = reverse * 10 + (value % 10);
        value /= 10;
    }
    return reverse * sign;
}

/* reverse without using modulo operator */
int reverse(int value)
{
    int reverse = 0;
    int sign = (value < 0) ? -1 : 1;
    value *= sign;

    while (value) {
        int digit = value - (value / 10) * 10; // simulate %
        reverse = reverse * 10 + digit;
        value = value / 10;
    }
    return reverse * sign;
}

int reverse_hw(void)
{
 /******* Reverse integer stored in memory-mapped register ********** 
    *** Question
        *   Reverse a number read from a hardware register.

    *** What they expect you to mention
        *   volatile
        *   No optimization
        *   Read once, store locally  */

    int n = REG_VALUE;  // read once
    int rev = 0;

    while (n) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;

    /*💡 Mention: “Reading the register repeatedly is unsafe.”*/
}

void reverse_String(char* num) {
    int i = 0;
    int j = strlen(num) - 1 ;

    /* Handle negative sign */
    if(num[0] == '-'){
        i = 1;
    }

    while( i < j) {
        char temp = num[i];
        num[i] = num[j];
        num[j] = temp;
        i++;
        j--;
    }
}
int main(int argc, char*argv[]) {
    int value = 0;
    printf("Enter the integer to reverse: ");
    scanf("%d",&value);
    printf("Reversed value of integer is %d\n",reverseNumber(value));
    printf("Reversed value of integer with overflow check is %d\n",reverseNumber_overflowCheck(value));
    printf("Reversed value without using modulo operator is %d\n", reverse(value));
    //printf("Reversed value of integer stored in memory mapped register is %d\n",reverse_hw()); // this will throw segmentaion fault bcs we are running on windows machine rather then running for Embedded board. As we are trying to access some random address of CPU so it throws segmentaion fault
    char str[50];
    printf("Enter the string to be reversed : ");
    getchar(); // to consume the leftover '\n' from previous scanf in stdin
    //scanf("%49[^\n]",str);
    fgets(str,sizeof(str),stdin); // fgets is safer, prevents oveflow, reads spaces.
    reverse_String(str);
    printf("Reversed value of big interger using string is %s\n",str);

    /* Reverse integer using bitwise operations only
    **** Question
        Can you reverse an integer using bit manipulation?

    **** What they’re testing
        * Whether you realize the trick:
            * Decimal reverse ≠ bit reverse

        * Correct response (INTERVIEW GOLD)
            * “Bitwise operations reverse bits, not decimal digits. Reversing an integer’s digits requires arithmetic operations.” */
    return 0;
}