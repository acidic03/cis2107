// Matthew Cohen
// 04-08-17
// Lab 8 - String Library
// The purpose of this lab is to gain practice manipulating strings and managing memory.

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main()
{
    puts("Test for all letters");
    char *s = "hello";
    char *s1 = "sir";
    int all_letters_ = all_letters(s);
    if (all_letters_)
    {
        printf("String: %s\n", s);
        puts("All character in string were letters\n");
    }
    else
    {
        puts("All character in string were not letters\n");
    }

    puts("Test for num_in_range");
    int num_in_range_ = num_in_range(s, 'a', 'h');
    printf("The String: %s\n", s);
    printf("The range %c-%c ", 'a', 'h');
    printf("%s %d %s\n\n", "There are", num_in_range_, "letters in the range");

    puts("Test for diff");
    int diff_ = diff(s, s1);
    printf("The Strings: %s, %s\n", s, s1);
    printf("%s %d %s\n\n", "The strings differ in", diff_, "ways");

    puts("Test for shorted");
    puts("Before");
	char word[] = "Hello World";
    printf("%s\n", word);
    puts("After");
    shorten(word, 5);
    printf("%s\n\n", word);

    puts("Test for len_diff");
    int len_diff_ = len_diff(s, s1);
    printf("The Strings: %s, %s\n", s, s1);
    printf("%s %d\n\n", "The string differ in length by", len_diff_);

	puts("Test for rm_left_space");
	char left_space[] = "  Hello";
	rm_left_space(left_space);
	printf("\"%s\"\n\n", left_space);

	puts("Test for rm_right_space");
	char right_space[] = "Hello  ";
	rm_right_space(right_space);
	printf("\"%s\"\n\n", right_space);

	puts("Test for rm_space");
	char all_space[] = " Hello ";
	rm_space(all_space);
	printf("\"%s\"\n\n", all_space);

	puts("Test for find");
	char *s2 = "Hello";
	char *looking_for = "l";
	int find_ = find(s2, looking_for);
	if (find_ != -1)
		printf("Found \"%s\" in the string \"%s\" at index %d\n\n", looking_for, s2, find_);
	else
		printf("Did not find \"%s\" in the string \"%s\"\n\n", looking_for, s2);

	puts("Test for ptr_to");
	char *ptr_to_word = "Hello";
	char *ptr_to_find = "l";
	char *ptr_to_ = ptr_to(ptr_to_word, ptr_to_find);
	printf("%s\n\n", ptr_to_);

    puts("Test for is_empty");
    char *s3 = "";
    int is_empty_ = is_empty(s3);
    if (is_empty_)
        puts("The string is empty\n\n");
    else
        printf("The string %s is not empty\n\n", s);


    puts("Test for str_zip");
    char *s4 = "Temple";
    char *s5 = "Hello";
    char *str_zip_ = str_zip(s4, s5);
    printf("Results after str_zip on string %s, %s are %s\n\n", s4, s5, str_zip_);
    // free up resources
    free(str_zip_);
    str_zip_ = NULL;

    puts("Test for capitalize");
    char s6[] = "hello world";
    capitalize(s6);
    printf("%s\n\n", s6);

	puts("Test for strcmp_ign_case");
	char *s7 = "hello";
	char *s8 = "goodbye";
	int strcmp_ign_case_ = strcmp_ign_case(s7, s8);

	if (strcmp_ign_case_ == 0)
		printf("Both strings are equal\n\n");
	else if (strcmp_ign_case_ > 0)
		printf("%s appears after %s\n\n", s7, s8);
	else
		printf("%s appears before %s\n\n", s7, s8);
	
	puts("Test for take_last");
	char s9[] = "hello";
	printf("last %d characters of %s are ", 3, s9);
	take_last(s9, 3);
	printf("%s\n\n", s9);

	puts("Test for dedup");
	char *dedup_ = dedup(s);
	printf("%s\n\n", dedup_);
	free(dedup_);
	dedup_ = NULL;

	puts("Test for pad");
	char *pad_ = pad(s, 6);
	printf("Padded string is \"%s\"\n\n", pad_);
	 free(pad_);
	pad_ = NULL;

	puts("Test for ends_with_ignore_case");
	char *s11 = "Coding";
	char *s12 = "ing";
	int ends_with_ignore_case_ = ends_with_ignore_case(s11, s12);
	if (ends_with_ignore_case_)
		printf("The string %s ends with %s\n\n", s11, s12);
	else
		printf("The string %s does not end with %s\n\n", s11, s12);

	puts("Test for repeat");
	char *repeat_ = repeat(s, 3, '-');
	printf("%s\n\n", repeat_);
	free(repeat_);
	repeat_ = NULL;
	
	puts("Test for replace");
	char *x = "Dogs are X the";
	char *y = "X";
	char *z = "best";
	char *replace_ = replace(x, y, z);
	printf("After replace: \"%s\"\n\n", replace_);
	free(replace_);
	replace_ = NULL;

	puts("Test for str_connect");
	char **list_of_words = (char**)malloc(sizeof(*list_of_words) * 4);
	list_of_words[0] = "Hello";
	list_of_words[1] = "world";
	list_of_words[2] = "Hello";
	list_of_words[3] = "world";
	char *str_connect_ = str_connect(list_of_words, 4, '-');
	printf("\"%s\"\n", str_connect_);

	free(list_of_words);
	list_of_words = NULL;


    return 0;
}