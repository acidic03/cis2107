/*
 * Name:	Matthew Cohen
 * Section:	02
 * Date:	03/11/2019
 * Lab:  	CIS2107_Lab07_Manual
 * Goal: 	To design and implement functions to process characters and strings.
 */

#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions
void *upperLower(const char *s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr(char *line, char *sub);
int countChar(char *line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[], int size);
void endsWithed(char *string[], int size);

int main()
{

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    // //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series, 5);

    //test for endsWithed
    endsWithed(series, 5);

    return 0;
}

// 1.(Displaying Strings in Uppercase and Lowercase)
void *upperLower(const char *s)
{
    // don't run when EOF is the current character
    int len = 0;

    // print string in uppercase
    while (*s)
    {
        printf("%c", toupper(*s));
        // increment the pointer to the next character
        s++;
        // keep track of string length to point pointer back to the beginning
        len++;
    }
    s -= len;
    printf(" ");

    // print string in lowercase
    while (*s != '\0')
    {
        printf("%c", tolower(*s));
        // increment the pointer to the next character
        s++;
    }
    return NULL;
}

// 2.(Converting Strings to Integers for Calculations)
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4)
{
    char *ptr = NULL;
    long num1 = strtol(s1, &ptr, 0);
    long num2 = strtol(s2, &ptr, 0);
    long num3 = strtol(s3, &ptr, 0);
    long num4 = strtol(s4, &ptr, 0);
    int total = num1 + num2 + num3 + num4;

    return total;
}

// //3.(Converting Strings to Floating Point for Calculations)
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4)
{
    char *ptr = NULL;
    double num1 = strtod(s1, &ptr);
    double num2 = strtod(s2, &ptr);
    double num3 = strtod(s3, &ptr);
    double num4 = strtod(s4, &ptr);

    double total = num1 + num2 + num3 + num4;

    return total;
}

// //4.(Comparing Strings)
void compareStr(const char *s1, const char *s2)
{
	printf("\n");
    int result = strcmp(s1, s2);

    // strings are equal
    if (result == 0)
        printf("%s = %s\n", s1, s2);
        // s2 is greater
    else if (result < 0)
        printf("%s < %s\n", s1, s2);
        // s1 is greater
    else
        printf("%s > %s\n", s1, s2);
    
}

// //5.(Comparing Portions of Strings)
void comparePartialStr(const char *s1, const char *s2, int n)
{
    int result = strncmp(s1, s2, n);
    printf("Comparison of first %d chars: ", n);

    // strings are equal
    if (result == 0)
        printf("%s = %s\n", s1, s2);
        // s2 is greater
    else if (result < 0)
        printf("%s < %s\n", s1, s2);
        // s1 is greater
    else
        printf("%s > %s\n", s1, s2);
    puts("");
}

//6.(Random Sentences)
void randomize(void)
{
    char *article[6] = {"the", "a", "one", "some", "any"};
    char *noun[6] = {"boy", "girl", "dog", "town", "car"};
    char *verb[6] = {"drove", "jumped", "ran", "walked", "skipped"};
    char *preposition[6] = {"to", "from", "over", "under", "on"};
    char sentence[40] = "";

    //puts("");

    // create 20 sentences
    for (int i = 0; i < 20; i++)
    {
        // number between 0 and 4
        int n = rand() % 5;

        strcat(sentence, article[n]);
        
        // beginning of sentence so capitalize it
        sentence[0] = toupper(sentence[0]);
        strcat(sentence, " ");

        n = rand() % 5;
        strcat(sentence, noun[n]);
        strcat(sentence, " ");

        n = rand() % 5;
        strcat(sentence, verb[n]);
        strcat(sentence, " ");

        n = rand() % 5;
        strcat(sentence, preposition[n]);
        strcat(sentence, " ");

        n = rand() % 5;
        strcat(sentence, article[n]);
        strcat(sentence, " ");

        n = rand() % 5;
        strcat(sentence, noun[n]);

        strcat(sentence, ".");

        // terminate string
        sentence[39] = '\0';
        printf("%s ", sentence);
        // clear the char array
        sentence[0] = '\0';
    }
    printf("\n\n");
}

// //7.(Tokenizing Telephone Numbers)
int tokenizeTelNum(char *num) {
    char *tokenPtr = strtok(num, "()");
    char *ptr = NULL;
    int areaCode;

    // get the area code
    if (tokenPtr != NULL)
    {

        //tokenPtr = strtok(NULL, "()");
        areaCode = strtol(tokenPtr, &ptr, 0);
    }

    // find the rest of the phone number
    tokenPtr = strtok(NULL, " -");

    char phoneNumberStr[8];

    while (tokenPtr != NULL)
    {

        strcat(phoneNumberStr, tokenPtr);
        tokenPtr = strtok(NULL, "-");
    }
    // terminate string
    phoneNumberStr[7] = '\0';

    long phoneNumber = strtol(phoneNumberStr, &ptr, 0);
    // display the phone number
    printf("%d %ld\n", areaCode, phoneNumber);
    return 0;
}

// //8.(Displaying a Sentence with Its Words Reversed)
void reverse(char *text) {
    printf("\n");
    // holds each individual token
    char *tokenStrings[10];
    char *tokenPtr = strtok(text, " ");
    int numOfTokens = 0;

    while (tokenPtr != NULL)
    {
        tokenStrings[numOfTokens++] = tokenPtr;
        tokenPtr = strtok(NULL, " ");
    }

    // print string in reverse
    while (numOfTokens > 0)
    {
        printf("%s ", tokenStrings[--numOfTokens]);
    }
}

//9.(Counting the Occurrences of a Substring)
int countSubstr (char * line, char * sub) {
    int numOfOcc = 0;
    char *str = strstr(line, sub);

    while (str)
    {
        numOfOcc++;
        // add the length of the sub word to search for another occurrence
        str += strlen(sub);
        str = strstr(str, sub);
    }
    return numOfOcc;
}

//10.(Counting the Occurrences of a Character)
int countChar (char *line, char c) {
    int numOfOcc = 0;
    char *str = strchr(line, c);

    while (str)
    {
        numOfOcc++;
        str++;
        str = strchr(str, c);
    }

    return numOfOcc;
}

//11.(Counting the Letters of the Alphabet in a String)
void countAlpha(char *string) {
    // holds the number of occurrences for each letter
    int letterCounts[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    printf("\n");
    for (int i = 0, len = strlen(string); i < len; i++)
    {
        // ignores anything that is a letter
        if (isalpha(string[i]))
        {
            // ignore case and assume everything is capital
            int letterIndex = toupper(string[i]);
            letterCounts[letterIndex - 65] = countChar(string, string[i]);
        }
    }

    // print the table
    for (int i = 0; i < 26; i++)
    {
        if (i == 25)
            printf("%c,%c | %d", i+65, i+97, letterCounts[i]);
        else
            printf("%c,%c | %d\n", i+65, i+97, letterCounts[i]);
    }
}

//12.(Counting the Number of Words in a String)
int countWords(char *string) {
    int numOfWords = 0;
    char *tokenPtr = strtok(string, " \n");

    while (tokenPtr)
    {
        numOfWords++;
        tokenPtr = strtok(NULL, " \n");
    }

    return numOfWords;
}

//13.(Strings Starting with "b")
void startsWithB(char *string[], int size) {

    for (int i = 0; i < size; i++)
    {
        // check if the letter is B or b
        if (string[i][0] == 66 || string[i][0] == 98)
            printf("%s ", string[i]);
    }
    printf("\n");
}

//14.(Strings Ending with "ed")
void endsWithed(char *string[], int size) {

    for (int i = 0; i < size; i++)
    {
        int strLen = strlen(string[i]);

        if (string[i][strLen - 2] == 101)
        {
            // 'e' is second to last, check if it ends in 'd'
            if (string[i][strLen - 1] == 100)
            {
                printf("%s ", string[i]);
            }
        }

    }
    printf("\n");
}
