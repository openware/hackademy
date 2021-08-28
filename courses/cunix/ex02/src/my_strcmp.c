// returns result of 2 strings comparing
unsigned int my_strcmp(char *str1, char *str2)
{
    while (*str1)
    {
        if (*str1 != *str2)
        {
            break;
        }
        else
        {
            str1++;
            str2++;
        }
    }
    
    int asciiDiff = *str1 - *str2;
    
    if (asciiDiff > 0)
    {
        return 1;
    }
    else if (asciiDiff < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
