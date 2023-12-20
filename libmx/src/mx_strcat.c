#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    for (int i = mx_strlen(s1); i < mx_strlen(s1) + mx_strlen(s2); i++) {
        s1[i] = *s2;
        s2++;
    }
    s1[mx_strlen(s1) + mx_strlen(s2)+1] = '\0';
    return s1;    
}


