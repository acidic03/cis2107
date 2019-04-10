#include "string.h"
void rm_right_space(char *s)
{
    int s_len = str_length(s);
    int last_char_index = -1;
    for (int i = s_len-1; i > 0; i--)
    {
        if (s[i] != ' ' && last_char_index == -1)
        {
            // found index of last character
            last_char_index = i;
            break;
        }
    }

    s[last_char_index+1] = '\0';
}