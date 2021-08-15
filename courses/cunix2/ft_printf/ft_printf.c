#include <stdio.h>
#include <stdarg.h>
void ft_printf (const char * format, ...);
void ft_printf (const char * format, ...)
{
     va_list arg;
     char ch;
     va_start(arg, format);
     while (ch = * format ++)
     {
         switch(ch)
         {
             case '1':
             {
                     char ch1 = va_arg (arg, int);
                     putchar (ch1);
                     break;
             }
             case '2':
             {
                 char * p = va_arg (arg, char *);
                 fputs (p, stdout);
                 break;
             }
             default:
                putchar (ch);
         }
     }
 
}
