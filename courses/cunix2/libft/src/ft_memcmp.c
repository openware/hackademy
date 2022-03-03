int ft_memcmp(const void *str1, const void *str2, int length)
{
    unsigned char *str1_pos = (unsigned char *) str1;
    unsigned char *str2_pos = (unsigned char *) str2;
    int diff;

    while (length-- != 0)
    {
        diff = *str1_pos++ - *str2_pos++;

        if (diff != 0)
        {
            return diff;
        }
    }

    return 0;
}
