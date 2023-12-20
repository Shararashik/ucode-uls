#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    if (s != NULL) {
        int size = mx_strlen(s);
        char *temp = s; 
        for(int i = 0; i < size / 2; i++) {
            mx_swap_char(&temp[i], &s[size - 1 - i]);
        }
    }
}


