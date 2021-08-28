// returns result of 2 strings comparing
unsigned int my_strcmp(char *str1, char *str2)
{
    // get first unequal char
    while(*str1)
    {
        if(*str1 != *str2)
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
        return 1; //str1 string is bigger
    }
    else if(asciiDiff < 0)
    {
        return -1; //str2 is bigger
    }
    else
    {
        return 0; //equal
    }
}
