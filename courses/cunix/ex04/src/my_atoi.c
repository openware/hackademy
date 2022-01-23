int my_atoi(const char *nptr)
{
    int result = 0;
    int i;
    if (*nptr == '-')
    {
        i = -1;
        nptr++;
    }
    else
    {
        i = 1;
    }

    while (*nptr && *nptr >= '0' && *nptr <= '9')
    {
        int current = *nptr++ - '0';
        result = result * 10 + current;
    }
    return result * i;
}