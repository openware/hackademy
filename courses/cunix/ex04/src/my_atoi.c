#include "test.h"

int my_atoi(const char *nptr)
{
    int i = (nptr[0] == '-') ? 1 : 0;
    int n = 0;
    for (; nptr[i] >= '0' && nptr[i] <= '9'; i++)
    {
        n = 10 * n + (nptr[i] - '0');
    }
    return (nptr[0] == '-') ? -n : n;
}
