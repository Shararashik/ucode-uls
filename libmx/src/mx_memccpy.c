#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    for (size_t i = 0; i < n; i++)
    {
        if (((const char *)src)[i] == c) {
            ((char *)dst)[i] = ((const char *)src)[i];
            return (void *)&(((char *)dst)[i + 1]);
        }
        ((char *)dst)[i] = ((char *)src)[i];    
    }
    return NULL;
}



