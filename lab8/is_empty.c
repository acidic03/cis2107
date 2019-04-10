int is_empty(char *s)
{
    while (*s)
    {
        if (*s != 0 || *s != 32)
        {
            return 0;
        }
    }
    // s is NULL
    return 1;
}