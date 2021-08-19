#define EXP 10

int my_atoi(const char *nptr)
{
    int num = 0;
    int sign = 1;

    if (*nptr == '-')
    {
        sign = -1;
        nptr++;
    }

    while (*nptr >= '0' && *nptr <= '9' && *nptr != '\0')
    {
        num = *nptr++ - '0' + num * EXP;
    }

    return num * sign;
}
