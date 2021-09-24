void* ft_memccpy(void *dest, const void *src, int c, int n)
{
    if (n) {
		register unsigned char *tp = dest;
		register const unsigned char *fp = src;
		do {
			if ((*tp++ = *fp++) == c)
				return (dest);
		} while (--n != 0);
	}
	return (0);
}