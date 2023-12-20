#include "../inc/libmx.h"

char *mx_strnew(const int size) {
    char *memo = malloc(size + 1);
    for (int i = 0; i <= size; i++) {
        memo[i] = '\0';
    }
    return memo;
}



