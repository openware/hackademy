#include <stdio.h>
int atoi(const char *nptr);

int main()
{
    return 0;
}

int atoi(const char *nptr)
{
    int index = 0;
    int final = 0;
    int sign = 1;
    if(nptr[0] == '-')
    {
        sign = -1;
        index++;
    }

    for (; nptr[index] != '\0'; ++index)
    {
        final = nptr[index] - '0' + final*10;
    }
    return final*sign;
}
