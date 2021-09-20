#include <stdlib.h>
char *ft_strdup(char *src)
{
    char *str;
    char *p;
    int len = 0;

    while (src[len])
    {
        len++;
    }
    str = malloc(len + 1);
    p = str;
    while (*src)
    {
        *p++ = *src++;
    }
    *p = '\0';
    return str;


    /*
    int len = strlen(src) + 1;
    char* output = (char*) malloc ((len + 1) * sizeof(char));
    if (output == NULL) return NULL;
    output = (char*) memcpy(output, src, len);
    return output;

    */
}