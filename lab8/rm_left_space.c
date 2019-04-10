#include "string.h"
void rm_left_space(char *s)
{
    int s_len = str_length(s);
    int first_char_index = -1;
    for (int i = 0; i < s_len; i++)
    {
        if (s[i] != ' ' && first_char_index == -1)
        {
            // found index of first character so restart to shift characters
            first_char_index = i;
            i = 0;
        }

        if (first_char_index != -1)
        {
            s[i] = s[first_char_index + i];
        }
    }

    s[s_len - first_char_index] = '\0';
}