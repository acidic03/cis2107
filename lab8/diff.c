#include "string.h"
int diff(char *s1, char *s2)
{
    unsigned int diff_amount = 0;
    unsigned int s1_len = str_length(s1);
    unsigned int s2_len = str_length(s2);

    if (s1_len >= s2_len)
    {
        for (int i = 0; i < s2_len; i++)
        {
            if (*s1 != *s2)
                diff_amount++;
            s1++;
            s2++;
        }
        diff_amount += s1_len - s2_len;
    }
    else
    {
        for (int i = 0; i < s1_len; i++)
        {
            if (*s1 != *s2)
                diff_amount++;
            s1++;
            s2++;
        }
        diff_amount += s2_len - s1_len;
    }

    return diff_amount;
}