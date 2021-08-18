
unsigned int my_strlen(char *str) 
{
    unsigned int strlen = 0;

    while (str[strlen] != '\0')
    {
        strlen++;
    }
    
    return strlen;
}
