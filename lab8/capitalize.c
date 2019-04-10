void capitalize(char *s)
{
    int foundSpace = 0;
    int index = 0;

    // capitalize the first character
    if ((*s >= 97) && (*s <= 122))
        *s = *s - 32;
   while (*s)
   {
       /*
        * if the current character is a space then change the next character
        * if it exists
        */
       if (*s == 32)
       {
           if (*(s+1) != '\0')
           {
               *(s+1) = *(s+1) - 32;
           }
       }
       index++;
       s++;
   }
}