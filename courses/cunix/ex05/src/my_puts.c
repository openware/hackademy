#include <stdio.h>
#include <unistd.h>

int count_chars (const char *s)
{
    int chars_count = 0;
    for (int i = 0; *(s + i) != '\0'; i++)
    {
        chars_count++;
    }
    return chars_count;
}

int my_puts (const char *s) 
{
    int bytes_towrite = count_chars(s);
    const int stdout_fd = 1;

    ssize_t written = write(stdout_fd, s, bytes_towrite);
    if (written != bytes_towrite)
    {
        return EOF;
    }

    write(stdout_fd, "\n", 1);
    return '\n';
}
