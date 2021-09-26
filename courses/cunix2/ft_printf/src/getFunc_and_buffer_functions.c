#include "head2.h"

char* (*get_func(char i))(va_list)
{
	int k = 0;
	print keys[] = {
		{'c', print_c},
		{'s', print_s},
		{'d', print_d},
		{'i', print_d},
		{'\0', NULL}
	};

	while (keys[k].id != '\0')
	{
		if (keys[k].id == i)
		{
			return (keys[k].func);
		}
		k++;
	}
	return (NULL);
}


char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		return (NULL);
	}
	return (buffer);
}


void write_buffer(char *buffer, int len, va_list list)
{
	char *buff;
	buff = realloc(buffer, len);
	write(1, buff, len); 
	free(buff); va_end(list);
}
