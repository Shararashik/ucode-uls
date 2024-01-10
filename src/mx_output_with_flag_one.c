#include "uls.h"

void mx_output_with_flag_one(t_list *files, flags_t *flags) {
    for(;files; files = files->next) {
        char *filename = files->data;
        mx_print_filename(filename, files->data, flags);
        mx_printstr("\n");
    }
}


