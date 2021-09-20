


int ft_isalpha(int c)
{
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                      "abcdefghijklmnopqrstuvwxyz";
    char *letter = alphabet;

    while (*letter != '\0' && *letter != c)
    {
        ++letter;
    }


    if (*letter)
    {
        return 1;
    }

    return 0;
}




