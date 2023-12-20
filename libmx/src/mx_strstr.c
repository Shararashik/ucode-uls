#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int needle_len = mx_strlen(needle);

    if (!mx_strlen(needle)) {
        return (char *)haystack;
    }

    while (*haystack) {
        if (mx_strncmp(haystack, needle, needle_len) == 0) {
            return (char *)haystack;
        }
        haystack++;
    }

    return NULL;
}

