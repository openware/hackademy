
// it calls from memcmp ctest
void *ft_memmove(void *dst, const void *src, int length)
{
    char *csrc = (char *)src;
    char *cdest = (char *)dst;
    char temp[length];
    for (int i = 0; i < length; i++)
    {
        temp[i] = csrc[i];
    }
    for (int i = 0; i < length; i++)
    {
        cdest[i] = temp[i];
    }
  
    //delete [] temp;
    return cdest;
}
