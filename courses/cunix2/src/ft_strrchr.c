char *ft_strrchr(const char *s, int c)
{
  if (*s == '\0')
  {
    return (*s == c) ? (char *) s : 0;
  }
  char *pos = ft_strrchr(s + 1, c);
  if (pos == 0 && *s == c % 256)
  {
    return (char *) s;
  }
  return pos;
}
