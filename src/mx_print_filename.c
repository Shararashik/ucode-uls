#include "../inc/uls.h"

void mx_print_filename(const char *name, const char *full_path, flags_t *flags) {
    struct stat file_stat;
    if (lstat(full_path, &file_stat) == -1) {
        mx_file_error(full_path);
    }

    if (flags->G) {
        const char *color_code = COLOR_RESET;

        if (S_ISDIR(file_stat.st_mode)) {
            color_code = COLOR_DIR;
        }
        else if (file_stat.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
            color_code = COLOR_EXEC;
        } 

        write(STDOUT_FILENO, color_code, mx_strlen(color_code));

        write(STDOUT_FILENO, name, mx_strlen(name));

        write(STDOUT_FILENO, COLOR_RESET, mx_strlen(COLOR_RESET));
    }
    else {
        write(STDOUT_FILENO, name, mx_strlen(name));
    }
}

