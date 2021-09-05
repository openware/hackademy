int ft_toupper(int c)
{
  if ('a' <= c && c <= 'z')
  {
    c = c - 32;
  }
  return c;
}
