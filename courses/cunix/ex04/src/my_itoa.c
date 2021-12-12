#include <stdlib.h>

char *my_itoa(int nmb)
{
    int length = 0;
    char *buffer = malloc(sizeof(char) * 12);
    int i = nmb >= 0 ? 1 : -1;
    nmb *= i;
    do
    {
        buffer[length++] = nmb % 10 + '0';
        nmb = nmb / 10;
    } while (nmb > 0);

    if (i == -1)
    {
        buffer[length++] = '-';
    }
    buffer[length] = '\0';

    for (int i = 0; i < length / 2; i++)
    {
        int current = buffer[i];
        buffer[i] = buffer[length - i - 1];
        buffer[length - i - 1] = current;
    }
    return buffer;
}