#include "../inc/uls.h"

void mx_file_error(const char *wrong_directory) {
    mx_sys_error("uls: ");
    mx_printstr(wrong_directory);
    mx_sys_error(": ");
    mx_sys_error("No such file or directory\n");
    exit(1);  
}



