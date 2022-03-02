#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int find_length(const char *s)
{
    int length = 0;
    while (*s++)
        length++;
    return length;
}

char *to_string(long int nmb, int *len)
{
    int sign;
    if ((sign = nmb) < 0)
        nmb = -nmb;
    *len = 0;
    long num = nmb;
    do
    {
        *len = *len + 1;
    } while ((num /= 10) > 0);

    char *result = (char *)malloc(*len + 1);

    for (int i = 0; i < *len; i++)
    {
        result[*len - 1 - i] = nmb % 10 + '0';
        nmb /= 10;
    }
    result[*len] = '\0';
    return result;
}

void fill_buffer(char *c, int number)
{
    while (number > 0)
    {
        write(1, c, 1);
        number--;
    }
}

void print_out(const char *str)
{
    for (; *str; str++)
    {
        write(1, str, 1);
    }
}
void print_begin(char show_sign, char print_space)
{
    if (show_sign == '\0')
    {
        if (print_space)
        {
            char *s = &print_space;
            write(1, s, 1);
        }
    }
    else
    {
        char *s = &show_sign;
        write(1, s, 1);
    }
}

void print(const char *str, char left, char fill, char show_sign, char print_space, int num)
{
    int first_char = (show_sign || print_space) ? 1 : 0;
    if (left)
    {
        print_begin(show_sign, print_space);
        print_out(str);
        fill_buffer(&fill, num - first_char);
    }
    else
    {

        if (fill == '0')
        {
            print_begin(show_sign, print_space);
            fill_buffer(&fill, num - first_char);
        }
        else
        {
            fill_buffer(&fill, num - first_char);
            print_begin(show_sign, print_space);
        }
        _print_out(str);
    }
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    const char *p;

    for (p = format; *p; p++)
    {
        if (*p != '%')
        {
            write(1, p, 1);
            continue;
        }

        char _print_space = *++p == ' ' ? ' ' : '\0';

        while (*p == ' ')
            p++;

        char show_sign = *p == '+' ? *p++ : '\0';
        char left = *p == '-' ? *p++ : '\0';
        char fill = *p == '0' ? '0' : ' ';

        int order = 0;
        for (; *p >= '0' && *p <= '9'; p++)
            order = order * 10 + *p - '0';

        switch (*p)
        {
        case 'i':
        case 'd': {
            int len;
            int num = va_arg(ap, int);
            char *value = to_string(num, &len);
            show_sign = num < 0 ? '-' : show_sign;
            print(value, left, fill, show_sign, _print_space, order - len);
            free(value);
        }
        break;
        case 'c': {
            char value = va_arg(ap, int);
            char *s = &value;
            print(s, left, fill, show_sign, _print_space, order - 1);
        }
        break;
        case 's': {
            char *value = va_arg(ap, char *);
            if (value == NULL)
                value = "(null)";
            print(value, left, fill, show_sign, _print_space, order - find_length(value));
        }
        break;
        default:
            write(1, p, 1);
            break;
        }
    }
    va_end(ap);
    return p - format;
}
