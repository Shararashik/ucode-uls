#include "../inc/uls.h"

void mx_sys_error(const char* str) {
    write(2, str, mx_strlen(str));
}


