#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    char *memo = (char*) b;
    for (size_t i = 0; i < len; i++)
    {
        memo[i] = c;
    }
    return b;
}



