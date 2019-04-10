#include "string.h"
void take_last(char *s, int n)
{
	int s_len = str_length(s);

	if (!(n >= s_len))
	{
		for (int i = 0; i < n; i++)
		{
			s[i] = s[s_len - n + i];
		}
	}

	s[n] = '\0';
}