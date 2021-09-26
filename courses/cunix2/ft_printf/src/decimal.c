#include "head2.h"


char *_itos(int div, int length, int n)
{
	char *str;
	int i = 0;

	str = malloc(sizeof(char) * length + 2);
	if (str == NULL)
	{
		return (NULL);
	}
		

	if (n < 0) 
	{
		str[0] = '-';
		i++;
	}
	while (n < 0) 
	{
		str[i] = ((n / div) * -1 + '0'); 
		n = n % div;
		div /= 10;
		i++;
	}
	while (div >= 1) 
	{
		str[i] = ((n / div) + '0');
		n = n % div;
		div /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}


char *print_d(va_list list)
{
	int length, div, n, temp;

	n = va_arg(list, int);
	temp = n;
	length = 0;
	div = 1;

	if (n == 0) /* account for 0 having length 1 */
	{
		length++;
		return (_itos(div, length, n));
	}

	while (temp != 0) /* find multiple of ten to divide */
	{
		length += 1;
		if (length > 1)
			div *= 10;
		temp /= 10;
	}

	return (_itos(div, length, n));
}
