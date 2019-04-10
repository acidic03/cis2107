#include "string.h"
#include <stdlib.h>
char *dedup(char *s)
{
	int occurences[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int s_len = str_length(s);
	char *new_s = (char *)malloc(s_len + 1);

	int index = 0;
	while (*s)
	{
		if ((*s >= 65) && (*s <= 90))
		{
			// uppercase characters
			if (occurences[*s-65] == 0)
			{
				new_s[index] = *s;
                occurences[*s-65] += 1;
				index++;
			}
		}
		if ((*s >= 97) && (*s <= 122))
		{
			// lowercase characters
			if (occurences[*s-97] == 0)
			{
				new_s[index] = *s;
                occurences[*s-97] += 1;
				index++;
			}
		}
		s++;
	}
    
    new_s[s_len + 1] = '\0';
    return new_s;
}