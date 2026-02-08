/* Explain the errors in this code and if so what is the error*/

#include <stdio.h>
char *str = "Hello"; // Hello is in text section and pointer pointing to is in stack section.  
str[0] = 'h'; // So we cant change the text section 

printf("%s", str);

