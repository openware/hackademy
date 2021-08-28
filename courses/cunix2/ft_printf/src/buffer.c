/*
 * =====================================================================================
 *
 *       Filename:  const_chunks.c
 *
 *    Description:  buffer helping functions for resolvers 
 *
 *        Version:  1.0
 *        Created:  08/28/2021 02:34:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sazonov Nikita (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

unsigned int buff_len(char *buff)
{
    unsigned int len = 0;
    while (*buff != '\0')
    {
        buff++;
        len++;
    }
    return len;
}

char *create_buff(const char *format)
{
    unsigned int buff_len = 0;
    while (*format != '%' && *format != '\0')
    {
        format++;
        buff_len++;
    }
    format -= buff_len;

    char *buff = (char *) malloc(sizeof(char) * (buff_len + 1));
    while (*format != '%' && *format != '\0')
    {
        *buff++ = *format++;
    }
    *buff = '\0';
    return (buff - buff_len);
}

const char *next_param(const char *format)
{
    while (*format != '%' && *format != '\0')
        format++;
    return format;
}
