#include <stdio.h>
#include <stdlib.h>
#include "string.h"
char *repeat(char *s, int x, char sep)
{
    if (s == NULL)
        return NULL;
    
    int s_len = str_length(s);
    int sep_len = str_length(&sep);
    char *new_s = (char *)malloc(s_len*x + (sep_len*x)+1);
    int index = 0;

    for (int i = 0; i < x; i++)
    {
        while (*s)
        {
            new_s[index] = *s;
            s++;
            index++;
        }
        if (i != x-1)
        {
            new_s[index] = sep;
            index++;
        }
        s -= s_len;
    }
    new_s[s_len*x + (sep_len*x)+1] = '\0';
    return new_s;
}