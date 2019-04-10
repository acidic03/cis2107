#include <stdio.h>
char *ptr_to(char *h, char *n)
{
    while (*h)
    {
        if (*h == *n)
            return h;
        h++;
    }

    return NULL;
}