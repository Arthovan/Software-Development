/* Implement the custom memcpy */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *my_memcpy(void *destination, const void *source, size_t num)
{
    unsigned char *dest = (unsigned char *)destination;
    const unsigned char *src = (const unsigned char *)source;

    for (size_t i = 0; i < num; i++)
    {
        dest[i] = src[i];
    }

    return destination;
}
