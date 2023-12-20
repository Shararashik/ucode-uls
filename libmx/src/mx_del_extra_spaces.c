#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    while (*str && mx_isspace(*str)) {
        str++;
    }
    int newLen = 0;
    int delimerr = 0;
    for (int i = 0; str[i]; i++) {
        if (mx_isspace(str[i])) {
            if (delimerr == 0) {
                delimerr = 1;
                newLen++;
            }
        } else {
            delimerr = 0;
            newLen++;
        }
    }
    char *newStr = (char *)malloc(newLen + 1);
    if (newStr == NULL) {
        return NULL;
    }
    delimerr = 0;
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (mx_isspace(str[i])) {
            if (delimerr == 0) {
                delimerr = 1;
                newStr[j++] = ' ';
            }
        } 
        else {
            delimerr = 0;
            newStr[j++] = str[i];
        }
    }
    newStr[j - 1] = '\0';
    return newStr;
}



