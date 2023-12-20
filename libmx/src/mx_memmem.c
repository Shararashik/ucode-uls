#include "../inc/libmx.h"

void* mx_memmem(const void* big, size_t big_len, const void* little, size_t little_len) {
    if (big_len < little_len || little_len <= 0 || big_len <= 0) {
        return NULL;
    }
    unsigned char *start = NULL;
    unsigned char *finish = NULL;

    start = (unsigned char*)big;
    finish = (unsigned char*)little;

    for (size_t i = 0; start[i] != '\0'; i++) {
        if (mx_memcmp(start + i, finish, little_len - 1) == 0) {
            return start + i;
        }
    }
    return NULL;
}


