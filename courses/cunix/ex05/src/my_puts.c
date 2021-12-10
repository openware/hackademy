#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <io.h>

int my_puts(const char *s)
{
	int len = 0;
	for(int i = 0; s[i] != '\0'; i++)
		len++;

	if(write(1, s, len) == EOF || write(1, "\n", 1) == EOF)
	{
		return EOF;
	} else return 0;
}