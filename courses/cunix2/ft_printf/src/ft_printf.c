/*
 * =====================================================================================
 *
 *       Filename:  ft_printf.c
 *
 *    Description:  Produces output according to a format. 
 *
 *        Version:  1.0
 *        Created:  08/27/2021 03:45:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com 
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define STDOUT  1

#include "format_param_t.h"
#include "chunks.h"
#include "resolvers.h"
#include "buffer.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    unsigned int num_of_chunks = chunk_count(format);
    char **chunks = (char **) malloc(sizeof(char *) * (num_of_chunks + 1));

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format_param_t *format_param = format_resolver(format);

            switch (format_param->type)
            {
                case 'd':
                case 'i':
                    int num = va_arg(args, int);
                    *chunks = num_resolver(format_param, num);
                    break;
                case 'c':
                    char ch = va_arg(args, int);
                    *chunks = char_resolver(format_param, ch);
                    break;
                case 's':
                    const char *str = va_arg(args, const char *);
                    *chunks = str_resolver(format_param, str);
                    break;
                case '%':
                    *chunks = escseq_resolver(format_param);
                    break;
                default:
                    NULL;
                    break;
            }

            format = format_param->end;
            free(format_param);
        }
        else
        {
            *chunks = create_buff(format);
            format = next_param(format);
        }

        chunks++;
    }
    *chunks = NULL;
    chunks -= num_of_chunks;

    unsigned int res_str_len = 0;
    while (*chunks != NULL)
    {
        res_str_len += buff_len(*chunks);
        chunks++;
    }
    chunks -= num_of_chunks;

    char *res_str = (char *) malloc(sizeof(char) * (res_str_len + 1));
    unsigned int chunk_len;
    while (*chunks != NULL)
    {
        chunk_len = buff_len(*chunks);
        while ((**chunks != '\0'))
        {
            *res_str++ = *(*chunks)++;
        }
        *chunks -= chunk_len;
        free(*chunks);
        chunks++;
    }
    chunks -= num_of_chunks;
    free(chunks);

    *res_str = '\0';
    res_str -= res_str_len;

    write(STDOUT, res_str, res_str_len);
    return res_str_len;
}

int ft_sprintf(char *s, const char *format, ...)
{
    va_list args;
    va_start(args, format);

    unsigned int num_of_chunks = chunk_count(format);
    char **chunks = (char **) malloc(sizeof(char *) * (num_of_chunks + 1));

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format_param_t *format_param = format_resolver(format);

            switch (format_param->type)
            {
                case 'd':
                case 'i':
                    int num = va_arg(args, int);
                    *chunks = num_resolver(format_param, num);
                    break;
                case 'c':
                    char chr = va_arg(args, int);
                    *chunks = char_resolver(format_param, chr);
                    break;
                case 's':
                    const char *str = va_arg(args, const char *);
                    *chunks = str_resolver(format_param, str);
                    break;
                case '%':
                    *chunks = escseq_resolver(format_param);
                    break;
                default:
                    NULL;
                    break;
            }

            format = format_param->end;
            free(format_param);
        }
        else
        {
            *chunks = create_buff(format);
            format = next_param(format);
        }

        chunks++;
    }
    *chunks = NULL;
    chunks -= num_of_chunks;

    unsigned int res_str_len = 0;
    while (*chunks != NULL)
    {
        res_str_len += buff_len(*chunks);
        chunks++;
    }
    chunks -= num_of_chunks;

    unsigned int chunk_len;
    while (*chunks != NULL)
    {
        chunk_len = buff_len(*chunks);
        while ((**chunks != '\0'))
        {
            *s++ = *(*chunks)++;
        }
        *chunks -= chunk_len;
        free(*chunks);
        chunks++;
    }
    chunks -= num_of_chunks;
    free(chunks);

    *s = '\0';
    s -= res_str_len;

    return res_str_len;
}
