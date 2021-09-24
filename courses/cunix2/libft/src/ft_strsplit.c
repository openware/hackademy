#include <stdlib.h>
#define DICT_LEN 256
#include <string.h>




int unsigned my_strlen(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        ++i;
    }
    return i; 
}


char *ft_strdup(const char *src)
{
    char *dest = malloc(my_strlen(src) + 1);  
    if (dest == NULL)
    {
        return NULL;
    }         
    strcpy(dest, src);                     
    return dest;                            
}

char *sp = NULL;
char *ft_strtok(const char *str, char *delimiters)
{
 
    int i = 0;
    int len = my_strlen(delimiters);
    if (!str && !sp)
    {
        return NULL;
    }

    if (str && !sp)
    {
        sp = (char *)str;
    }
    
    char *p_start = sp;
    while (1)
    {
        for (i = 0; i < len; i ++)
        {
            if (*p_start == delimiters[i])
            {
                p_start ++;
                break;
            }
        }
 
        if (i == len)
        {
            sp = p_start;
            break;
        }
    }
 
    if (*sp == '\0')
    {
        sp = NULL;
        return sp;
    }

    while (*sp != '\0')
    {
        for (i = 0; i < len; i ++)
        {
            if (*sp == delimiters[i])
            {
                *sp = '\0';
                break;
            }
        }
 
        sp ++;
        if (i < len)
        {
            break;
        }
    }
    //free(sp);
 
    return p_start;
}


int wspace(char c) 
{
    return (c == ' ' || c == '\t' || c == '\n');
}
size_t strspn(const char *s, const char *accept);

//here deleted (char const *s)
int get_first_position(char const *s)
{
    int i = 0;
    while (wspace(s[i])) 
    {
        i += 1;
    }
    return (i);
}
//here deleted (char const *s)
int get_last_position(char const *s)
{
    int i = my_strlen(s) - 1;
    while (wspace(s[i])) 
    {
        i -= 1;
    }
    return (i);
}
//here deleted (char const *s)
int get_trim_len(char const *s)
{
    return (get_last_position(s) - get_first_position(s));
}
//here deleted (char const *s)
char *ft_strtrim(char const *s)
{
    char *trim = NULL;
    int i, len, start;
    if (my_strlen(s) == strspn(s, " "))
    {
        char *l = "";
        l  = (char *)malloc(my_strlen(l));
        return l;
    }
    if (s != NULL) 
    {
        i = 0;
        len = get_trim_len(s) + 1;
        trim = (char *)malloc(len);
        start = get_first_position(s);
        while (i < len) 
        {
            trim[i] = s[start];
            i += 1;
            start += 1;
        }
        trim[i] = '\0';
    }
    return (trim);
}

char **ft_strsplit(const char *s, char c)
{
    char *s2 = strdup(s);
    s2 = ft_strtrim(s);
    char **result    = 0;
    size_t count     = 0;
    char *tmp        = s2;
    char *last_comma = 0;
    char delim[2];
    delim[0] = c;
    delim[1] = 0;

    if (!tmp)
    {
        result = (char **) malloc(sizeof(char *) * 1);
        result = NULL;
        free(s2);
       
        return result;
    }
    if (c == 0)
    {
        result = (char **) malloc(my_strlen(s));
        result[0] = s2;
        result[1] = NULL;
        return result;

    }
    while (*tmp)
    {
        if (c == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }
    count++;
    count++;
    result = (char **) malloc(sizeof(char *) * count);
    

    if (result)
    {
        size_t idx  = 0;
        char *token = ft_strtok(s2, delim);

        while (token)
        {
            //assert(idx < count);
            *(result + idx++) = ft_strdup(token);
            token = ft_strtok(0, delim);
        }
        // assert(idx == count - 1);
        *(result + idx) = 0;
    }
    free(s2);

    return result;
}
