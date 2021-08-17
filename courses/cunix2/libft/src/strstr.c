char *ft_strstr(char *haystack, char *needle) {
    if (*needle == '\0')
        return haystack;

    for (; *haystack != '\0'; haystack++) {
        if (*haystack == *needle) {
            int found = 1;
            for (char *cur_n = needle, *cur_h = haystack; *cur_n != '\0';) {
                if (*cur_n++ != *cur_h++) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                return haystack;
            }
        }
    }
    return 0;
}
