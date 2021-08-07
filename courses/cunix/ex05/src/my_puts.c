#include "test.h"
#include <unistd.h>

/* output string to file descriptor 1 (stdout) */
int my_puts(const char *s)
{
    const char newline = '\n';

    if (s)  // check if buffer is a null pointer
    {
        int index = 0;
        while (s[index] != '\0')
        {
            write(1, &s[index++], sizeof(char));
        }
        write(1, &newline, sizeof(char));
        return 0;
    }
    else
    {
        return 1;
    }
}
