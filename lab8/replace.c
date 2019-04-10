#include "string.h"
#include <stdlib.h>
char *replace(char *s, char *pat, char *rep)
{
    int s_len = str_length(s);
    int pat_len = str_length(pat);
    int rep_len = str_length(rep);
    char *new_s = (char *)malloc((s_len + rep_len + pat_len + 1) * sizeof(char));
    
    int index = 0;
    while (*s)
    {
        if (*s == *pat)
        {
            while (*rep)
            {
                new_s[index] = *rep;
                rep++;
                index++;
            }
            rep -= rep_len;
        }
        else
        {
            new_s[index] = *s;
            index++;
        }
        s++;
    }
    new_s[s_len + rep_len + pat_len + 1] = '\0';
    return new_s;
}