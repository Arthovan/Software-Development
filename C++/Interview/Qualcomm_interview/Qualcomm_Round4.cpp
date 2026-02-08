/* Questions asked :    1.  Software Interrup vs Hardware Interrupt
                        2.  ISR and its explanation 
						3. 	What happens if exeception occurs in ARM ?
                        4.  Program questions 1
                        5.  Can I add the log API in ISR? If not then what is the reason?
                        6.  How to provide mutal execulsion to access shared data between ISR and thread
                            (For this we need to create a ISR in the IST method - Interrupt Service Thread)

input is arbitary string, which is expected to consist of multiple substring seperated by coma
input example:
acf,sfg,sfgc,efgv

the substring can be translated to a integer number based on the given dictionary, like


typedef struct {
 char* str,
 uint  code,
} DICE_TYPE;

DICE_TYPE Dice[DICE_LEN];

write function to translate the input to a binary which consists of the mapped number, use 0x0 for invalid substring.
example output:
acf,sfg,sfgc,efgv ->
0x1 0x0 0x2 0x0
*/
/* int* input is arbitary string, which is expected to consist of multiple substring seperated by coma
input example:
acf,sfg,sfgc,efgv

the substring can be translated to a integer number based on the given dictionary, like

acf ->0x1
sfgc->0x2
dfge->0x3
cfg ->0x6
....

typedef {
 char* str,
 uint  code,
} DICE_TYPE;

DICE_TYPE Dice[DICE_LEN];

write function to translate the input to a binary which consists of the mapped number, use 0x0 for invalid substring.
example output:
acf,sfg,sfgc,efgv ->
0x1 0x0 0x2 0x0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void translate(const char* input, unsigned int** output, unsigned int* outputsize)
{
    char* copy = strdup(input);   // make modifiable copy
    char* token;
    unsigned int count = 0;

    /* Count substrings */
    for (int i = 0; input[i]; i++)
        if (input[i] == ',') count++;
    count++;  

    *outputsize = count;
    *output = (unsigned int*)calloc(count, sizeof(unsigned int));

    token = strtok(copy, ",");

    unsigned int index = 0;

    while (token) {
        unsigned int code = 0x0;

        for (int i = 0; i < DICE_LEN; i++) {
            if (strcmp(Dice[i].str, token) == 0) {
                code = Dice[i].code;
                break;
            }
        }

        (*output)[index++] = code;
        token = strtok(NULL, ",");
    }

    free(copy);
}
