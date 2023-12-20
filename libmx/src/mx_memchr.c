#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const unsigned char* us = s;
    unsigned char uc = c;
    for (size_t i = 0; i < n; i++) {
        if (us[i] == uc) {
            return (void*)(us + i);
        }
    }
    return NULL;
}


