#include "../inc/libmx.h"

void mx_printint(int n) {
    int num = n;
    int k;
    if (n == 0) {
        mx_printchar('0');
    }
    if (n < 0) {
        n *= -1;
        mx_printchar('-');
    }    
    for (k = 0; num != 0; k++) {
        num /= 10;
    }
    char r[k];
    for (int i = k - 1; i >= 0; i--) {
        int j = n % 10;
        r[i] = (j + 48);
        n /= 10;
    }
    for (int i = 0; i < k; i++) {
        mx_printchar(r[i]);
    }
}


