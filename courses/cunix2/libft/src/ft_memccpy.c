/*
 * =====================================================================================
 *
 *       Filename:  ft_memcpy.c
 *
 *    Description:  Copies bytes from one memory area to another until has reached given
 *                  number or character
 *
 *        Version:  1.0
 *        Created:  08/10/2021 01:41:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stddef.h>

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    unsigned char *dest_bytes = (unsigned char *) dest;
    unsigned char *src_bytes = (unsigned char *) src;

    while (n-- != 0)
    { 
        *dest_bytes = *src_bytes;
        if (*dest_bytes == c)
        {
            return dest_bytes + 1;
        }
        dest_bytes++;
        src_bytes++;
    }

    return 0;
}
/*
int main(void)
{
    char dest[100];
    dest[1] = 'A';
    ft_memccpy(dest, "coucou", 'A', 1);
    ft_memccpy(dest, "coucou", 'c', 10);
    char *s = (char *) ft_memccpy(dest, "B", 0, 10);
    s--; s++;
}
*/
