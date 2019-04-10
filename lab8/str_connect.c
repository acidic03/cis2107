#include "string.h"
#include <stdlib.h>
char *str_connect(char **strs, int n, char c)
{
    // find the total length needed
    int length_needed = 0;
    for (int i = 0; i < n; i++)
    {
        length_needed += str_length(strs[i]);
        // add one for character seperator
        length_needed++;
    }
    
    char *new_s = (char *)malloc((length_needed + 1) * sizeof(char));
    int new_s_index = 0;
    int word_length = 0;

    for (int i = 0; i < n; i++)
    {
        word_length = str_length(strs[i]);

        for (int j = 0; j < word_length; j++)
        {
            
            new_s[new_s_index] = strs[i][j];
            new_s_index++;
        }

        if (i != n-1)
        {
            new_s[new_s_index] = c;
            new_s_index++;
        }
    }
    new_s[length_needed + 1] = '\0';
    
    return new_s;
}