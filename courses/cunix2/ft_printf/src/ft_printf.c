#include "holberton.h"



int my_atoi(const char *nptr){
  
    int i = 0;
    int minus = 1;
    int val = 0;
    while (nptr[i] == '-') {
        minus = -minus;
        i++;
    }
    while(nptr[i]=='0')
    {
        ++i;
    }
    while(nptr[i] > '0' && nptr[i] <= '9')
    {
        int nbr = (int) (nptr[i] - '0');

        val = (val * 10) + nbr;
        i++;
    }
    return val*minus;
   
}

int check_digit1 (char c) {
    if ((c>'0') && (c<='9')) return 1;
    return 0;
}
int check_digit2 (char c) {
    if ((c>='0') && (c<='9')) return 1;
    return 0;
}
int check_buffer_overflow(char *buffer, int len)
{
	if (len > 1020)
	{
		write(1, buffer, len);
		len = 0;
	}
	return (len);
}
int concat(int x, int y) {
    int temp = y;
    while (y != 0) {
        x *= 10;
        y /= 10;
    }
    return x + temp;
}


int ft_printf(const char *format, ...)
{
	int len = 0, total_len = 0, i = 0, j = 0;
	va_list list;
	char *buffer, *str;
	char* (*f)(va_list);
	int c=0;
	int s=0;
	int m=0;
	int nmbr=0;
	int plus=0;

	if (format == NULL)
		return (-1);

	buffer = create_buffer();
	if (buffer == NULL)
		return (-1);

	va_start(list, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%') /* copy format into buffer until '%' */
		{
			len = check_buffer_overflow(buffer, len);
			buffer[len++] = format[i++];
			total_len++;
		}
		else /* if %, find function */
		{
			
			i++;
			if (format[i] == ' ')
			{
				i++;
			}

			if(format[i] == '+')
			{
				plus = 1;
				i++;
			}
			if (check_digit1(format[i])) 
			{
				int j=i+1;
				++nmbr;
				while(check_digit2(format[j]))
				{
				    ++nmbr;
					++j;
				}
				
				s = my_atoi(format);
				for(int k=0;k<nmbr-1;k++)
				{
					++i;
				}
				
				
			}

			if (check_digit2(format[i]) == 1 )
			{
				++i;
			}
			if (check_digit2(format[i]) == 1 )
			{
				++i;
			}
			
			
			

			
			

			/*
			if (format[i] == '0') 
			{
				int j=i+1;
				++i;
				while(check_digit2(format[j]) == 1)
				{
				    ++m;
					++j;
				}
				
				s = my_atoi(format);
				for(int k=0;k<m-1;k++)
				{
					++i;
				}
				
			}*/

			if (format[i] == '\0') /* handle single ending % */
			{
				va_end(list);
				free(buffer);
				return (-1);
			}
			if (format[i] == '%') /* handle double %'s */
			{
				len = check_buffer_overflow(buffer, len);
				buffer[len++] = format[i];
				total_len++;
			}
			else
			{


				f = get_func(format[i]); /* grab function */
				if (f == NULL)  /* handle fake id */
				{
					len = check_buffer_overflow(buffer, len);
					buffer[len++] = '%'; total_len++;
					buffer[len++] = format[i]; total_len++;
				}
				else /* return string, copy to buffer */
				{
					str = f(list);
					if (str == NULL)
					{
						va_end(list);
						free(buffer);
						return (-1);
					}
					if (format[i] == 'c' && str[0] == '\0')
					{
						len = check_buffer_overflow(buffer, len);
						buffer[len++] = '\0';
						total_len++;
					}
					j = 0;
					//int y = _strlen(str);
					if(plus)
						{
							if(str[j] != '-')
							{
							len = check_buffer_overflow(buffer, len);
							buffer[len++] = '+';
							total_len++;
							}
							plus=0;
						}
					if(nmbr)
						{
							nmbr = s - _strlen(str);
							if (nmbr > 0)
							{
								for(int l=0;l<nmbr;l++)
								{
									len = check_buffer_overflow(buffer, len);
									buffer[len++] = ' ';
									total_len++; 
								}
							}
							s = 0;
						}
					if(c)
					{
						m = c - _strlen(str);
						if (m > 0)
						{
							for(int l=0;l<m;l++)
							{
								len = check_buffer_overflow(buffer, len);
								buffer[len++] = '0';
								total_len++; 
							}
						}
						c = 0;
					}
					while (str[j] != '\0')
					{
						
						len = check_buffer_overflow(buffer, len);
						buffer[len++] = str[j];
						total_len++; j++;
						
					}
					free(str);
				}
			} i++;
		}
	}
	write_buffer(buffer, len, list);
	return (total_len);
}

