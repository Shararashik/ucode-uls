#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *bufer = malloc(len);
    bufer = mx_memcpy(bufer, src, len);
    dst = mx_memcpy(dst, bufer, len);
    free(bufer);
    return dst;
}



