int num_in_range(char *s1, char b, char t)
{
    unsigned int c = 0;

    while (*s1)
    {
        if (*s1 >= b && *s1 <= t)
            c++;
        s1++;
    }

    return c;
}