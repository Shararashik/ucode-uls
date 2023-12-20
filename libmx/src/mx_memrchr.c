#include "../inc/libmx.h"

void* mx_memrchr(const void* s, int c, size_t n) {
    const unsigned char* us = s;
    unsigned char uc = c;
    for (size_t i = n; i > 0; i--) {
        if (us[i - 1] == uc) {
            return (void*)(us + i - 1);
        }
    }
    return NULL;  
}




