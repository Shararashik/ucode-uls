#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (!str || !sub) {
        return -1;
    }
    int i = 0;
    char *words = mx_strstr(str, sub);
    for (i = 0; words != NULL; i++) {
        words++;
        words = mx_strstr(words, sub);
    }
    return i;    
}


