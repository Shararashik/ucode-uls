#include "../inc/libmx.h"

int mx_strlen(const char *s) {
    char c = s[0];
    int i;
    for(i = 0; c != '\0'; i++){
        c = s[i];
    }

    return i-1;
}



