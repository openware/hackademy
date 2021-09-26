#include "head2.h"

int _strlen(char *s)
{
	int a = 0;

	while (*(s + a))
	{
		a++;
	}
	return (a);
}
