/*
 * =====================================================================================
 *
 *       Filename:  ft_strsplit.c
 *
 *    Description:  Divides string with given delimiter and returns array of
 *                  substrings
 *
 *        Version:  1.0
 *        Created:  08/11/2021 12:22:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stdlib.h>

unsigned int check_num_of_words(const char *s, char c);
unsigned int check_len_of_word(const char *s, char c);

char **ft_strsplit(const char *s, char c)
{
    unsigned int num_of_words = check_num_of_words(s, c);
    char **words = (char **) malloc(sizeof(char *) * (num_of_words + 1));

    unsigned int len_of_word;
    char *word = NULL;
    while (*s != '\0')
    {
        while (*s == c && *s != '\0')
        {
            s++;
        }
        if (*s != '\0')
        {
            len_of_word = check_len_of_word(s, c);
            word = (char *) malloc(sizeof(char) * (len_of_word + 1));
            while (*s != c && *s != '\0')
            {
                *word++ = *s++;
            }
            *word = '\0';
            *words++ = word - len_of_word;
        }
    }
    *words = NULL;

    return words - num_of_words;
}

unsigned int check_num_of_words(const char *s, char c)
{
    unsigned int num_of_words = 0;

    while (*s != '\0')
    {
        while (*s == c && *s != '\0')
        {
            s++;
        }
        if (*s != '\0')
        {
            num_of_words++;
            while (*s != c && *s != '\0')
            {
                s++;
            }
        }
    }

    return num_of_words;
}

unsigned int check_len_of_word(const char *s, char c)
{
    unsigned int len_of_word = 0;

    while (*s != c && *s != '\0')
    {
        len_of_word++;
        s++;
    }

    return len_of_word;
}
/*
int main(void)
{
    char **words = ft_strsplit("  some glasses   are broken  ", ' ');
    words++;
}
*/
