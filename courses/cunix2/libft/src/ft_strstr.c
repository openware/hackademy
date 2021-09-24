//#include <stdio.h>
//#include "libft.h"
char *ft_strstr(char *str, char *substr)
{
    const char *a;
    const char *b;

    b = substr;

    if (*b == 0)
    {
        return (char *) str;
    }

    for (; *str != 0; str += 1)
    {
        if (*str != *b) 
        {
            continue;
        }

        a = str;
        while (1) 
        {
            if (*b == 0) 
            {
                return (char *) str;
            }
            if (*a++ != *b++) 
            {
                break;
            }
        }
        b = substr;
    }

    return 0;
}
  
  
