#include <stdio.h>
#include <stdlib.h>
#include "string.h"
char *pad(char *s, int d)
{
    int s_len = str_length(s);

    if (s_len == d)
    {
        char *copy_s = (char *)malloc(s_len+1);
        int i = 0;
        while (*s)
        {
            copy_s[i] = *s;
            s++;
            i++;
        }
        s -= s_len;
        copy_s[s_len+1] = '\0';
        return copy_s;
    }
    if (s == NULL)
        return NULL;
    
    // allocate a new string
    char *new_s = (char *)malloc(s_len + (d - s_len) + 1);
    int index = 0;

    while (*s)
    {
        new_s[index] = *s;
        index++;
        s++;

        if (*(s+1) == '\0')
        {
            // add the padding
            for (int i = s_len; i < d; i++)
            {
                new_s[i] = 32;
            }
        }
    }
    s -= s_len;
    new_s[s_len + (d - s_len)+1] = '\0';
    return new_s;
}