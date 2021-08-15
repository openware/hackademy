/*
 * =====================================================================================
 *
 *       Filename:  resolvers.c
 *
 *    Description:  Here are format resolvers 
 *
 *        Version:  1.0
 *        Created:  08/15/2021 01:02:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
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

char *itoa(int num);
char *recursive_conv(unsigned int nmb, char *nptr);
unsigned int get_chunk_length(const char *chunk);

char *num_resolver(format_param_t *format_param, int num)
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

    unsigned int num_of_pad = result_s_len - num_s_len - is_signed;
    char *result_s = (char *) malloc(sizeof(char) * (result_s_len + 1));
    
    if (is_signed && num >= 0)
    {
        *result_s++ = '+';
    }
    if (num < 0)
    {
        *result_s++ = *num_s++;
    }

    if (!is_left_aligned)
    {
        while (num_of_pad-- != 0)
        {
            *result_s++ = pad;
        }
        while (*num_s != '\0')
        {
            *result_s++ = *num_s++;
        }
    }
    else
    {
        while (*num_s != '\0')
        {
            *result_s++ = *num_s++;
        }
        while (num_of_pad-- != 0)
        {
            *result_s++ = pad;
        }
    }
    *result_s = '\0';
    return (result_s - result_s_len);
}

char *itoa(int num)
{
    if (num == 0)
    {
        char *num_s = (char *) malloc(sizeof(char) * 2);
        *num_s = '0';
        *(num_s + 1) = '\0';
        return num_s;
    }

    unsigned int is_negative = (num < 0);
    num *= 1 - 2 * is_negative;

    unsigned int length = 1 + is_negative;
    int num_r = num;
    while (num > 9)
    {
        num /= 10;
        length++;
    }
    num = num_r;

    char *num_s = (char *) malloc(sizeof(char) * (length + 1));
    if (is_negative)
    {
        *num_s++ = '-';
    }
    
    num_s = (char *) recursive_conv(num, num_s);
    *num_s = '\0';
    return (num_s - length);
}

char *recursive_conv(unsigned int nmb, char *nptr)
{
    if (nmb != 0)
    {
        nptr = (char *) recursive_conv(nmb / 10, nptr);
        *nptr++ = '0' + (nmb % 10);
    }
    return nptr;
}

char *char_resolver(format_param_t *format_param, char chr)
{
    unsigned int is_left_aligned = (format_param->flags & 2) ? 1 : 0;
    char pad = (format_param->flags & 1) ? '0' : ' ';

    unsigned int result_s_len;
    if (format_param->min_field_width < 1)
    {
        result_s_len = 1;
    }
    else
    {
        result_s_len = format_param->min_field_width;
    }

    unsigned int num_of_pad = result_s_len - 1;
    char *result_s = (char *) malloc(sizeof(char) * (result_s_len + 1));
    if (!is_left_aligned)
    {
        while (num_of_pad-- != 0)
        {
            *result_s++ = pad;
        }
        *result_s++ = chr;
    }
    else
    {
        *result_s++ = chr;
        while (num_of_pad-- != 0)
        {
            *result_s++ = pad;
        }
    }
    *result_s = '\0';
    return (result_s - result_s_len);
}

char *str_resolver(format_param_t *format_param, const char *str)
{
    if (str == NULL)
    {
        str = "(null)";
    }

    unsigned int str_len = get_chunk_length(str);

    unsigned int is_left_aligned = (format_param->flags & 2) ? 1 : 0;
    char pad = (format_param->flags & 1) ? '0' : ' ';

    unsigned int result_s_len;
    if (str_len > format_param->min_field_width)
    {
        result_s_len = str_len;
    }
    else
    {
        result_s_len = format_param->min_field_width;
    }

    unsigned int num_of_pad = result_s_len - str_len;
    char *result_s = (char *) malloc(sizeof(char) * (result_s_len + 1));
    if (!is_left_aligned)
    {
        while (num_of_pad-- != 0)
        {
            *result_s++ = pad;
        }
        while (*str != '\0')
        {
            *result_s++ = *str++;
        }
    }
    else
    {
        while (*str != '\0')
        {
            *result_s++ = *str++;
        }
        while (num_of_pad-- != 0)
        {
            *result_s++ = pad;
        }
    }
    *result_s = '\0';
    return (result_s - result_s_len);
}

char *escseq_resolver(format_param_t *format_param)
{
    /*
    if (format_param->flags + format_param->min_field_width > 0)
    {
        exit(1);
    }
    */
    
    char *escseq = (char *) malloc(sizeof(char) * 2);
    *escseq = format_param->type;
    *(escseq + 1) = '\0';
    return escseq;
}
