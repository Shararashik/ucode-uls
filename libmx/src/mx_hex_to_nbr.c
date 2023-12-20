#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long res  = 0;
    for(int i = 0; hex[i] != '\0'; i++){
        res *= 16;
        if (hex[i] <= '9' && hex[i] >= '0'){
            res += hex[i] - 48;
        }
        if (hex[i] <= 'F' && hex[i] >= 'A') {
            res += hex[i] - 55;
        }
        if (hex[i] <= 'f' && hex[i] >= 'a') {
            res += hex[i] - 87;
        }
    }
    return res;
}

