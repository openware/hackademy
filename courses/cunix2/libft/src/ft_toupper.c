

int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
    {
        return ('A' + c - 'a');
    }
    else
    {
        return c;
    }
}