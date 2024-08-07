#include <stdio.h>
size_t my_strlen(const char *str) {
    const char *s = str;
    while (*s != '\0') {
        s++;
    }
    return s - str;
}

int main() {
    const char *my_string = "Hello, World!";
    size_t length = my_strlen(my_string);
    printf("Length of the string is %zu\n", length);
    return 0;
}
