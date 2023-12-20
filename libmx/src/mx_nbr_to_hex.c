#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char *hex_string = NULL;
    unsigned long num = nbr;
    int length = mx_int_len(nbr, 16);

    hex_string = malloc(length);
    if (nbr == 0) {
        return mx_strcpy(hex_string, "0");
    }
    int j;
    for (int i = 0; num; i++) {
        j = num % 16;
        if (j < 10)
            hex_string[--length] = 48 + j;
        if (j >= 10)
            hex_string[--length] = 87 + j;
        num /= 16;
    }
    return hex_string;
}


