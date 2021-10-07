#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int my_puts(const char *s)
{
	if(write(1, s, strlen(s)) == EOF || write(1, "\n", 1) == EOF)
	{
		return EOF;
	} else return 0;
}