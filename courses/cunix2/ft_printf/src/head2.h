#ifndef HEAD2_H
#define HEAD2_H

#include <stdarg.h> // va_list 
#include <stdlib.h> 
#include <unistd.h> // write 


char* (*get_func(char i))(va_list);
char *create_buffer(void);
void write_buffer(char *buffer, int len, va_list list);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

//printf functions 
int ft_printf(const char *format, ...);
char *print_s(va_list list);
char *print_c(va_list list);
char *print_d(va_list list);



typedef struct types
{
	char id;
	char* (*func)(va_list);
} print;

#endif
