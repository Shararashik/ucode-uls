#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    size_t len = mx_strlen(s1);
    if (n < len) {
        len = n;
    }
    char *dup = mx_strnew(len);
    return mx_strncpy(dup, s1, len);    
}




