int my_strcmp(char *str1, char *str2)
{
  while ( *str1 && *str1 == *str2 ) 
  {
    str1 = str1 + 1;
    str2 = str2 + 1;
  }
  return ( ( unsigned char )*str1 > ( unsigned char )*str2 ) - 
           ( ( unsigned char )*str1 < ( unsigned char )*str2 );
}