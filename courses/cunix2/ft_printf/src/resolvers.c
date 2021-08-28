/*
 * =====================================================================================
 *
 *       Filename:  resolvers.c
 *
 *    Description:  printf format resolvers
 *
 *        Version:  1.0
 *        Created:  08/28/2021 01:56:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "format_param_t.h"
#include "helpers.h"
#include "buffer.h"

format_param_t *format_resolver(const char *format)
{
    format_param_t *format_param = (format_param_t *) malloc(sizeof(format_param_t));
    format_param->start = format;

    format_param->flags = 0;
    unsigned int is_flag = 1;

    while (is_flag)
    {
        switch(*++format)
        {
            case '0':
                format_param->flags |= 1;
                break;
            case '-':
                format_param->flags |= 2;
                break;
            case '+':
                format_param->flags |= 4;
                break;
            case '\0':
                free(format_param);
                exit(1);
            default:
                is_flag = 0;
                break;
        }
    }

    format_param->min_field_width = 0;

    while ('0' <= *format && *format <= '9')
    {
        format_param->min_field_width *= 10;
        format_param->min_field_width += *format - '0';
        format++;
    }

    format_param->type = *format++;
    format_param->end = format;

    return format_param;
}

char *num_resolver(format_param_t *format_param, int num)
{
    char *num_str = itoa(num);
    unsigned int num_str_len = buff_len(num_str);

    unsigned int is_signed = (format_param->flags & 4) ? 1 : 0;
    unsigned int is_left_aligned = (format_param->flags & 2) ? 1 : 0;
    char pad = (format_param->flags & 1) ? '0' : ' ';

    unsigned int res_str_len;
    if (num_str_len + is_signed > format_param->min_field_width)
    {
        res_str_len = num_str_len + is_signed;
    }
    else
    {
        res_str_len = format_param->min_field_width;
    }

    unsigned int num_of_pad = res_str_len - num_str_len - is_signed;
    char *res_str = (char *) malloc(sizeof(char) * (res_str_len + 1));
    
    if (is_signed && num >= 0)
    {
        *res_str++ = '+';
    }
    if (num < 0)
    {
        *res_str++ = *num_str++;
    }

    if (!is_left_aligned)
    {
        while (num_of_pad-- != 0)
        {
            *res_str++ = pad;
        }
        while (*num_str != '\0')
        {
            *res_str++ = *num_str++;
        }
    }
    else
    {
        while (*num_str != '\0')
        {
            *res_str++ = *num_str++;
        }
        while (num_of_pad-- != 0)
        {
            *res_str++ = pad;
        }
    }
    *res_str = '\0';
    return (res_str - res_str_len);
}

char *char_resolver(format_param_t *format_param, char ch)
{
    unsigned int is_left_aligned = (format_param->flags & 2) ? 1 : 0;
    char pad = (format_param->flags & 1) ? '0' : ' ';

    unsigned int res_str_len;
    if (format_param->min_field_width < 1)
    {
        res_str_len = 1;
    }
    else
    {
        res_str_len = format_param->min_field_width;
    }

    unsigned int num_of_pad = res_str_len - 1;
    char *res_str = (char *) malloc(sizeof(char) * (res_str_len + 1));
    if (!is_left_aligned)
    {
        while (num_of_pad-- != 0)
        {
            *res_str++ = pad;
        }
        *res_str++ = ch;
    }
    else
    {
        *res_str++ = ch;
        while (num_of_pad-- != 0)
        {
            *res_str++ = pad;
        }
    }
    *res_str = '\0';
    return (res_str - res_str_len);
}

char *str_resolver(format_param_t *format_param, const char *str)
{
    if (str == NULL)
    {
        str = "(null)";
    }

    unsigned int str_len = buff_len(str);

    unsigned int is_left_aligned = (format_param->flags & 2) ? 1 : 0;
    char pad = (format_param->flags & 1) ? '0' : ' ';

    unsigned int res_str_len;
    if (str_len > format_param->min_field_width)
    {
        res_str_len = str_len;
    }
    else
    {
        res_str_len = format_param->min_field_width;
    }

    unsigned int num_of_pad = res_str_len - str_len;
    char *res_str = (char *) malloc(sizeof(char) * (res_str_len + 1));
    if (!is_left_aligned)
    {
        while (num_of_pad-- != 0)
        {
            *res_str++ = pad;
        }
        while (*str != '\0')
        {
            *res_str++ = *str++;
        }
    }
    else
    {
        while (*str != '\0')
        {
            *res_str++ = *str++;
        }
        while (num_of_pad-- != 0)
        {
            *res_str++ = pad;
        }
    }
    *res_str = '\0';
    return (res_str - res_str_len);
}

char *escseq_resolver(format_param_t *format_param)
{
    char *escseq = (char *) malloc(sizeof(char) * 2);
    *escseq = format_param->type;
    *(escseq + 1) = '\0';
    return escseq;
}
