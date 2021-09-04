char *my_strcpy(char *dest, const char *src)
{
    
    char *str = dest;

    while ((*dest++ = *src++)); 
        
    return str;

}
