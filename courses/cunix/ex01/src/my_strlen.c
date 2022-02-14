/*
* Function my_strlen
* *str: string
*
* return s: length
*/

unsigned int my_strlen(char *str)
{
    int length = 0; 

    while (*str != '\0')
    {
        length++;
        str++;
    }

    return length;
}
