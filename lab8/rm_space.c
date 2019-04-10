#include "string.h"
void rm_space(char *s)
{
    int spaces_so_far_index = 0;

    for (int i = 0; i < str_length(s); i++)
    {
        if (s[i] != ' ')
        {
            s[spaces_so_far_index] = s[i];
            spaces_so_far_index++;
        }
    }   
    s[spaces_so_far_index] = '\0';
}