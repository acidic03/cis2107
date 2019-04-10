#include "string.h"
int find(char *h, char *n)
{
    
    for (int i = 0, h_len = str_length(h); i < h_len; i++)
    {
        if (h[i] == *n)
            return i;
    }
    

    return -1;
}