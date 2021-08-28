// returns a char array length
unsigned int my_strlen(char *str)
{
    unsigned int length = 0;
    while (*str++)
    {
        length++;
    }
    return length;
}
