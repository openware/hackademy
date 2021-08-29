int my_atoi(const char *nptr)
{
    int num = 0;
    int sign = 1;
    int i = 0;
    while (nptr[i] == ' ')
    {
        i = i + 1;
    }
    if (nptr[i] == '-' || nptr[i] == '+')
    {
        if (nptr[i] == '-')
        {
            sign = -1;
        }
        i = i + 1;
    }
    while ('0' <= nptr[i] && nptr[i] <= '9')
    {
        num = num * 10 + (nptr[i] - '0');
        i = i + 1;
    }
    num *= sign;
    return num;
}