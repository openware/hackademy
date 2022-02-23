int ft_tolower(int ch)
{
    if (ch >= 65 && ch <= 90)
    {
        ch += 32;
    }

    return ch;
}
