int str_length(char *s)
{
    unsigned int len = 0;

    while (*s)
    {
        len++;
        s++;
    }

    return len;
}