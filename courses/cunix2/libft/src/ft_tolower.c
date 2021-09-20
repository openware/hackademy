int ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return ('a' + c - 'A');
    }
    else
    {
        return c;
    }
                
}