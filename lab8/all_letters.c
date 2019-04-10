int all_letters(char *s)
{
    // first character is uppercase
    while (*s)
    {
        if ( ((*s >= 65) && (*s <= 90)) || ((*s >= 97) && (*s <= 122)) )
        {
            s++;
            continue;
        }

        return 0;
    }

    return 1;

}