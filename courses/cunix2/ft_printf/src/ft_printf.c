#include <stdio.h>
#include <unistd.h>

#include <stdarg.h>
#include <stdlib.h>

#define STDOUT 1

char *my_itoa(long nmb, int *len);

void fill_buffer(char *c, int num);
void _print_out(const char *str);
void print(const char *str, char left, char fill, char, char, int num);
int my_strlen(const char *str)
{
    int len = 0;
    while (*str++)
        len++;
    return len;
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
            write(STDOUT, p, 1);
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
            char *value = my_itoa(num, &len);
            show_sign = num < 0 ? '-' : show_sign;
            print(value, left, fill, show_sign, _print_space, order - len);
        }
        break;
        case 'c': {
            char value = va_arg(ap, int);
            char *s = &value;
            print(s, left, fill, show_sign, _print_space, order - 1);
        }
        break;
        case 's': {
            const char *value = va_arg(ap, const char *);
            print(value, left, fill, show_sign, _print_space, order - my_strlen(value));
        }
        break;
        default:
            write(STDOUT, p, 1);
            break;
        }
    }
    return p - format;
}

char *my_itoa(long int nmb, int *len)
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

void fill_buffer(char *c, int num)
{
    while (num-- > 0)
    {
        write(STDOUT, c, 1);
    }
}

void _print_out(const char *str)
{
    for (; *str; str++)
    {
        write(STDOUT, str, 1);
    }
}
void _print_begin(char show_sign, char print_space)
{
    if (show_sign == '\0')
    {
        if (print_space)
        {
            char *s = &print_space;
            write(STDOUT, s, 1);
        }
    }
    else
    {
        char *s = &show_sign;
        write(STDOUT, s, 1);
    }
}

void print(const char *str, char left, char fill, char show_sign, char print_space, int num)
{
    int first_char = (show_sign || print_space) ? 1 : 0;
    if (left)
    {
        _print_begin(show_sign, print_space);
        _print_out(str);
        fill_buffer(&fill, num - first_char);
    }
    else
    {

        if (fill == '0')
        {
            _print_begin(show_sign, print_space);
            fill_buffer(&fill, num - first_char);
        }
        else
        {
            fill_buffer(&fill, num - first_char);
            _print_begin(show_sign, print_space);
        }
        _print_out(str);
    }
}

int main()
{
    ft_printf("{%3c}  ", 0);
    printf("{%3c}", 0);
}