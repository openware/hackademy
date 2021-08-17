
#include <stdlib.h>
void *ft_memmove(void *dest, const char *src, unsigned long int n) {
    void* d = dest;
    char buffer[n];
    for (unsigned i = 0; i < n; i++) {
        buffer[i] = *(char *)src++;
    }
    for (unsigned i = 0; i < n; i++) {
        *(char *)dest++ = buffer[i];
    }
    return d;
}