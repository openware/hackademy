int ft_memcmp(const void *ptr1, const void *ptr2, unsigned long int num) {
    const char *str1 = ptr1, *str2 = ptr2;
    while (*str1 == *str2 && num--) {
        str1++, str2++;
    }
    return num ? *str2 - *str1 : 0;
}