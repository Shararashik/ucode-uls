#include "../inc/uls.h"

void mx_output_with_flag_one(t_list *files, flags_t *flags, t_list *path) {
    for(;files && path; path = path->next, files = files->next) {
        mx_print_filename(files->data, path->data, flags);
        mx_printstr("\n");
    }
}


