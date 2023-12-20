#include "../inc/libmx.h"

int mx_int_len(unsigned long num, int d) {
    int length = 0;

    while (num) {
        num /= d;
        length++;
    }
    return length;
}

