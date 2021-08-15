/*
 * =====================================================================================
 *
 *       Filename:  const_chunks.c
 *
 *    Description:  Functions for operating constant chunk of format string 
 *
 *        Version:  1.0
 *        Created:  08/15/2021 01:06:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stdlib.h>

unsigned int get_chunk_length(char *chunk)
{
    unsigned int length = 0;
    while (*chunk != '\0')
    {
        chunk++;
        length++;
    }
    return length;
}

char *get_const_chunk(const char *format)
{
    unsigned int chunk_len = 0;
    while (*format != '%' && *format != '\0')
    {
        format++;
        chunk_len++;
    }
    format -= chunk_len;

    char *const_chunk = (char *) malloc(sizeof(char) * (chunk_len + 1));
    while (*format != '%' && *format != '\0')
    {
        *const_chunk++ = *format++;
    }
    *const_chunk = '\0';
    return (const_chunk - chunk_len);
}

const char *get_next_param(const char *format)
{
    while (*format != '%' && *format != '\0')
        format++;
    return format;
}
