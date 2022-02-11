/* Function : my_strcmp
*
* *str1, *str2: parameters of type string
*
* return 0
*/


int my_strcmp(char *str1, char *str2)
{
    for (; *str1 != '\0'; str1++, str2++)
    {
        if (*str1 != *str2)
        {
            if (*str1 < *str2)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}

