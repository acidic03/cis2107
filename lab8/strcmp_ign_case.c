#include "string.h"
#include <stdlib.h>
int strcmp_ign_case(char *s1, char *s2)
{
    int value = 0;
	int s1_len = str_length(s1);
	int s2_len = str_length(s2);

	char *s1_copy = (char*)malloc(s1_len+1);
    char *s2_copy = (char*)malloc(s2_len+1);

    // convert everything to uppercase
    for (int i = 0; i < s1_len; i++)
    {
        if (is_lower(s1[i]))
        {
            s1_copy[i] = s1[i] - 32;
        }
        else
        {
            s1_copy[i] = s1[i];
        }
    }

    for (int i = 0; i < s2_len; i++)
    {
        if (is_lower(s2[i]))
        {
            s2_copy[i] = s2[i] - 32;
        }
        else
        {
            s2_copy[i] = s2[i];
        }
    }

    // compare strings now
    if (s1_len == s2_len)
    {
        for (int i = 0; i < s1_len; i++)
        {
            if (s1[i] == s2[i])
                continue;
            if ((i == s1_len-1) && s1[i] == s2[i])
                return 0;
        }
    }
    else if (s1_len >= s2_len)
    {
        for (int i = 0; i < s2_len; i++)
        {
            if (s1[i] == s2[i])
                continue;
            if (s1[i] < s2[i])
            {
                return 1;
            }
            if (s1[i] > s2[i])
            {
                return -1;
            }
        }
    }
    else
    {
        for (int i = 0; i < s1_len; i++)
        {
            if (s2[i] == s1[i])
                continue;
            if (s2[i] < s1[i])
            {
                return 1;
            }
            if (s2[i] > s1[i])
            {
                return -1;
            }
        }
    }

    free(s1_copy);
    free(s2_copy);
    s1_copy = NULL;
    s2_copy = NULL;

	return value;
}