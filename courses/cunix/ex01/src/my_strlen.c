unsigned int my_strlen(char *str)
{
  char *array = str;
  while (*str != 0)
  {
    str = str + 1; 
  }
  return str - array;
}