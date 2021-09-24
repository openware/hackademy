int unsigned my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        ++i;
    }
    return i; 
}

void ft_striter(char *s, void(*f)(char *))
{
    int size = my_strlen(s);
    for (int i = 0; i < size; i++)
    {
        f(s);
        s++;
    }

}

