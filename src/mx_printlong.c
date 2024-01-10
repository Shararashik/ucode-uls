#include "../inc/uls.h"

void mx_printlong(long num) {
    char buffer[1024];
    int len = 0;
    if (num == 0) {
        buffer[len++] = '0';
    } else {
        if (num < 0) {
            write(STDOUT_FILENO, "-", 1);
            num = -num;
        }
        while (num > 0) {
            buffer[len++] = '0' + num % 10;
            num /= 10;
        }
        for (int i = 0; i < len / 2; ++i) {
            char temp = buffer[i];
            buffer[i] = buffer[len - i - 1];
            buffer[len - i - 1] = temp;
        }
    }
    write(STDOUT_FILENO, buffer, len);
}
