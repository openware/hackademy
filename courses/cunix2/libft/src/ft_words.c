/*
 * =====================================================================================
 *
 *       Filename:  ft_words.c
 *
 *    Description:  Calculates and returns the number of words in s divided with delimeter c. 
 *
 *        Version:  1.0
 *        Created:  08/27/2021 02:20:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

unsigned int ft_words(const char *s, char c)
{
    unsigned int num_words = 0;

    while (*s != '\0')
    {
        while (*s == c && *s != '\0')
        {
            s++;
        }

        if (*s != '\0')
        {
            num_words++;

            while (*s != c && *s != '\0')
            {
                s++;
            }
        }
    }

    return num_words;
}
