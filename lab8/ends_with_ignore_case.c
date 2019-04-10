#include "string.h"
int ends_with_ignore_case(char *s, char *suff)
{

    int suff_len = str_length(suff);
    int s_len = str_length(s);

    for (int i = s_len - 1; i > (s_len - suff_len - 1); i--)
    {
        if (is_upper(s[i]))
        {
            if (is_upper(suff[i-suff_len]))
            {
                if (s[i] != suff[i-suff_len])
                    return 0;
            } 
            else
            {
                if (s[i] != (suff[i-suff_len])-32 )
                    return 0;
            }
        }
        else{
            if (is_lower(suff[i-suff_len]))
            {
                if (s[i] != suff[i-suff_len])
                    return 0;
            } 
            else
            {
                if (s[i] != (suff[i-suff_len])+32 )
                    return 0;
            }
        }
        
    }

    return 1;
}