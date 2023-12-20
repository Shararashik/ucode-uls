#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    const char *start = str;
    const char *end = str + mx_strlen(str) - 1;
    while (*start && mx_isspace(*start)) {
        start++;
    }
    while (end > start && mx_isspace(*end)) {
        end--;
    }
    int trimmedLen = end - start + 1;
    char *trimmedStr = (char *)malloc(trimmedLen + 1);
    if (trimmedStr == NULL) {
        return NULL; // Memory allocation failed.
    }
    mx_strncpy(trimmedStr, start, trimmedLen);
    return trimmedStr;
}




