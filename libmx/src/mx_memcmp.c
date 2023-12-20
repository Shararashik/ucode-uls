#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    char *str1 = (char*) s1;
    char *str2 = (char*) s2;
    unsigned long i = 0;
    
    if (n == 0) {
        return 0;
    }
    else {
        while (i < n) {
            if (str1[i] != str2[i]){
                break;
            }
            i++;
        }
    }
    return str1[i] - str2[i];    
}


