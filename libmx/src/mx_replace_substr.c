#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL) {
        return NULL;
    }
    int strLen = mx_strlen(str);
    int subLen = mx_strlen(sub);
    char *result = mx_strnew(strLen + 1);
    if (result == NULL) {
        return NULL;
    }

    const char *found = mx_strstr(str, sub);
    while (found != NULL) {
        mx_strncat(result, str, found - str);
        mx_strcat(result, replace);
        str = found + subLen;
        found = mx_strstr(str, sub);
    }
    mx_strcat(result, str);
    return result;
}


