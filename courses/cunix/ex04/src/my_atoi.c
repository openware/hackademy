int my_atoi(const char *nptr)
{

    const char *s = nptr;
    int n = 0;
    int sign = 0;

    if (*s == '-')
    {
        sign = -1;
    }

    else
    {
        sign = 1;
    }

    if (*s == '+' || *s == '-')
    {
        s++;
    }

    for (n = 0; *s <= '9' && *s >= '0'; s++)
    {
        n = 10 * n + (*s - '0');
    }

    return sign * n;

}


