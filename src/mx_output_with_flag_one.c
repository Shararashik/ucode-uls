#include "uls.h"

static void print_colored_name(const char *name, const char *full_path) {
    struct stat file_stat;
    if (lstat(full_path, &file_stat) == -1) {
        mx_printstr("lstat");
    }

    const char *color_code = COLOR_RESET;

    if (S_ISDIR(file_stat.st_mode)) {
        color_code = COLOR_DIR;
    } else if (S_ISLNK(file_stat.st_mode)) {
        color_code = COLOR_LINK;
    } else if (file_stat.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
        color_code = COLOR_EXEC;
    } else {
        color_code = COLOR_OTHER;
    }

    // Write the color code
    write(STDOUT_FILENO, color_code, strlen(color_code));

    // Write the file name
    write(STDOUT_FILENO, name, strlen(name));

    // Write the reset color code
    write(STDOUT_FILENO, COLOR_RESET, strlen(COLOR_RESET));
}

void mx_output_with_flag_one(t_list *files, flags_t *flags) {
    for(;files; files = files->next) {
        char *filename = mx_get_filename(files->data);

        print_colored_name(filename, files->data);

        mx_printstr("\n");
    }
}


