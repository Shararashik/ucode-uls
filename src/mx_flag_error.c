#include "../inc/uls.h"

void mx_flag_error(flags_t **flags, char flag_symbol) {
    mx_sys_error("uls: illegal option -- ");
    mx_printchar(flag_symbol);
    mx_sys_error("\n");
    mx_sys_error("usage: uls [-l] [file ...]\n");
    free(*flags);
    *flags = NULL;
    exit(1);  
}


