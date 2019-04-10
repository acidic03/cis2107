#include "string.h"
void shorten(char *s, int new_len)
{
    int s_len = str_length(s);

    if (!(s_len <= new_len))
    {

    }
    s[new_len] = '\0';
}