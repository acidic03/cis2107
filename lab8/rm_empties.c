// void rm_empties(char **words)
// {
//     int found_blank = 0;
//     int blank_index = -1;
    
//     while (*words)
//     {
//         if (found_blank)
//         {
//             *words = *(words+1);
//             found_blank = 0;
//         }
      
//         if (**words == ' ')
//         {
//              printf("space: \"%s\"\n", *words);
//             if (**(words+1) != '\0' || **(words+1) != 32)
//             {
//                 printf("first: %s  | second: %s\n", *words, *(words+1));
//                 *words = *(words+1);
//                 found_blank = 1;
//             }
//         }
        
//         words++;
//     }
//     words -= 6;
    
// }