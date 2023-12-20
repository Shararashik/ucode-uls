#include "../inc/libmx.h"

char *mx_strncat(char *restrict s1, const char *restrict s2, size_t n) {
    char *dst = s1;
    while (*dst)
        dst++;

    while (*s2 && n > 0) {
        *dst++ = *s2++;
        n--;
    }
    *dst = '\0';
    return s1;
}

