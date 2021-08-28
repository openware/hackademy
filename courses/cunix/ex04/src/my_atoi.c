// converts string to int
int my_atoi(const char *nptr)
{
    if (*nptr == '\0')
    {
        return 0;
    }
    int sign = 1;
    if (*nptr == '-')
    {
        sign = -1;
        nptr++;
    }
    int res = 0;
    while (*nptr)
    {
        if (*nptr >= '0' && *nptr <= '9')
        {
            res = res * 10 + (*nptr++ - '0');
        }
        else
        {
            break;
        }
    } 
    return res * sign;
}
