void *ft_memccpy(void *dest, const void *src, int c, unsigned long int count) {

    const char* c_src = src; 
    for (char *s = dest; count--;c_src++, s++) {
        *s = *c_src;
        if (*s == c) {
            return s + 1;
        }
    }
    return 0;
}