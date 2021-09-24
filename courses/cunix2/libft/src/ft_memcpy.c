void *ft_memcpy(void *dst, const void *src, int length)
{
    // Typecast src and dest addresses to (char *)
    char *csrc = (char *)src;
    char *cdest = (char *)dst;
  
    // Copy contents of src[] to dest[]
    for (int i = 0; i < length; i++)
    {
        cdest[i] = csrc[i];
    }
    return 0;
}