/*
 * =====================================================================================
 *
 *       Filename:  ft_printf.c
 *
 *    Description:  Produces output according to a format 
 *
 *        Version:  1.0
 *        Created:  08/13/2021 01:41:53 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stdarg.h>
#include <stdlib.h>

typedef struct
{
    char type;
    char flags;
    unsigned int min_field_width;
    const char *start;
    const char *end;
}
format_param_t;

unsigned int count_format_chunks(const char *format);
format_param_t format_resolver(const char *format);
char *num_resolver(format_param_t format_param, int num);
char *char_resolver(format_param_t format_param, char chr);
char *str_resolver(format_param_t format_param, const char *str);
char *escseq_resolver(format_param_t format_param);
char *get_const_chunk(const char *format);
const char *get_next_param(const char *format);
unsigned int get_chunk_length(char *chunk);

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    unsigned int num_of_chunks = count_format_chunks(format);
    char **chunks = (char **) malloc(sizeof(char *) * (num_of_chunks + 1));

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format_param_t format_param = format_resolver(format);

            switch (format_param->type)
            {
                case 'd':
                case 'i':
                    int num = va_arg(args, int);
                    *chunks = num_resolver(format_param, num);
                    break;
                case 'c':
                    char chr = va_arg(args, char);
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
            free(&format_param);
        }
        else
        {
            *chunks = get_const_chunk(format);
            format = get_next_param(format);
        }

        chunks++
    }
    *chunks = NULL;
    chunks -= num_of_chunks;

    unsigned int result_str_len = 0;
    while (*chunks != NULL)
    {
        result_str_len += get_chunk_length(*chunks);
        chunks++;
    }
    chunks -= num_of_chunks;

    char *result_str = (char *) malloc(sizeof(char) * (result_str_len + 1));
    unsigned int chunk_len;
    while (*chunks != NULL)
    {
        chunk_len = get_chunk_length(*chunks);
        while ((**chunks != '\0'))
        {
            *result_str++ = *(*chunks)++;
        }
        *chunks -= chunk_len;
        free(*chunks);
        chunks++;
    }
    chunks -= num_of_chunks;
    free(chunks);

    *result_str = '\0';
    result_str -= result_str_len;
    return result_str;
}

unsigned int count_format_chunks(const char *format)
{
    unsigned int num_of_chunks = 0;
    while (format != '\0')
    {
        format = (*format == '%') ? (format_resolver(format))->end : get_next_param(format);
        num_of_chunks++;
    }
    return num_of_chunks;
}

format_param_t format_resolver(const char *format)
{
    format_param_t format_param = (format_param_t) malloc(sizeof(format_param_t));
    format_param->start = format;

    format_param->flags = 0;
    unsigned int is_flag = 1;
    while (is_flag)
    {
        switch (*format++)
        {
            case '0':
                format->flags |= 1;
                break;
            case '-':
                format->flags |= 2;
                break;
            case '+':
                format->flags |= 4;
                break;
            default:
                is_flag = 0;
                break;
        }
    }

    format_param->min_field_width = 0;
    while (*format >= '0' && *format <= '9')
    {
        format_param->min_field_width *= 10;
        format_param->min_field_width += *format - '0';
        format++;
    }

    format_param->type = *format++;
    format_param->end = format;

    return format_param;
}

char *num_resolver(format_param_t format_param, int num)
{
    char *num_s = itoa(num);
    unsigned int num_s_len = get_chunk_length(num_s);

    unsigned int is_signed = (format_param->flags & 4) ? 1 : 0;
    unsigned int is_left_aligned = (format_param->flags & 2) ? 1 : 0;
    char pad = (format_param->flags & 1) ? '0' : ' ';
    unsigned int result_s_len;
    if (num_s_len + is_signed > format_param->min_field_width)
    {
        result_s_len = num_s_len + is_signed;
    }
    else
    {
        result_s_len = format_param->min_field_width;
    }
}

char *char_resolver(format_param_t format_param, char chr);
char *str_resolver(format_param_t format_param, const char *str);
char *escseq_resolver(format_param_t format_param);
char *get_const_chunk(const char *format);
const char *get_next_param(const char *format);
unsigned int get_chunk_length(char *chunk);


