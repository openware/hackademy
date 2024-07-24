#include <stdio.h>

size_t my_strlen(const char *str);

int main() {
    const char *test_str = "Hello, World!";
    size_t length = my_strlen(test_str);
    
    printf( test_str, length);
    return 0;
}
