/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




/*=========================================================================
  Constants and definitions:
==========================================================================*/




/*-------------------------------------------------------------------------
  The main program.
 -------------------------------------------------------------------------*/

 /* starts the search and
 asks for a number of strings
 thats he wants to search
 */
void start_dictionary(int *num_of_strings, int *no_strings);

/* calculates ascii sum of a string */
int ascii_sum(char *str);

// sets an array in the same size of the dictionary
//to be the ascii sum of each string in dictionary
void create_ascii_sum_dictionary(char *dictionary[], int ascii_sum_dictionary[19]);

// returns how many words match the string
int search_matching_words(char *str, int *ascii_sum_dictionary);

// prints the number of matching words and the words themselves
void print_matching_words(int matching, char *str, char *dictionary[], int ascii_sum_dictionary[]);

// returns if a char is a letter
bool is_letter(char c);
int main()
{
    char curr[10] = {'\0'}, *dictionary[19] = {"AVOCADO", "BANNANA", "WATER", "CAT", "DOG", "HELLO",
"ISRAEL", "ITALY", "GARMISH", "USA", "BRAZIL", "KING", "ABCDy",
"INT", "CHAR", "DOUBLE", "hardcheese", "realize", "farther"};
    int num_of_strings = 0, no_strings = 0, ascii_sum_dictionary[19] = {0}, matching_words=0;
    start_dictionary(&num_of_strings, &no_strings);
    create_ascii_sum_dictionary(dictionary, ascii_sum_dictionary);
    if (no_strings)
    {
        printf("no strings");
        return 1;
    }
    printf("Please enter %d strings:\n", num_of_strings);
    for (int i=0;i<num_of_strings;i++)
    {
        scanf("%s",curr);
        matching_words=search_matching_words(curr, ascii_sum_dictionary);
        print_matching_words(matching_words,curr, dictionary, ascii_sum_dictionary);
        printf("\n\n");
    }

    return 0;
}




void start_dictionary(int *num_of_strings, int *no_strings)
{
    *num_of_strings = 0;
    printf("Please enter a non-negative number:\n");
    scanf("%d", num_of_strings);
    while (*num_of_strings < 0)
    {
        printf("Please enter a NON-NEGATIVE number:\n");
        scanf("%d", num_of_strings);
    }
     // if num_of_strings is 0 than search is over because theres no strings
     *no_strings = !(*num_of_strings);
}

int ascii_sum(char *str)
{
    int sum = 0;
    for(int i = 0;str[i] != '\0'; i++)
    {
        if (is_letter(str[i]))
        {
            sum += str[i];
        }

    }
    return sum;
}

void create_ascii_sum_dictionary(char *dictionary[], int ascii_sum_dictionary[19])
{
    int i;
    for (i=0;i<19;i++)
    {
        ascii_sum_dictionary[i] = ascii_sum(dictionary[i]);
    }
}
int search_matching_words(char *str, int ascii_sum_dictionary[])
{
    int sum = ascii_sum(str), matching = 0;
    for (int i=0;i<19;i++)
    {
        matching += (sum == ascii_sum_dictionary[i]);
    }
    return matching;
}


void print_matching_words(int matching, char *str, char *dictionary[], int ascii_sum_dictionary[])
{
    if (!matching)
    {
        printf("the string %s has no matches in the dictionary\n", str);
        return;
    }
    int i, sum = ascii_sum(str);
    printf("the string %s has %d matches in the dictionary:\n", str, matching);
    for (i=0;i<19;i++)
    {
        if (sum == ascii_sum_dictionary[i])
        {
            printf("%s", dictionary[i]);
            putchar('\n');
        }
    }
}

bool is_letter(char c)
{
    return (('a'<= c && c <= 'z') || ('A'<= c && c <= 'Z'));
}
