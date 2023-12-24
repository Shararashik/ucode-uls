#include "uls.h"

void mx_output_with_flag_one(t_list *files, flags_t *flags) {
    for(;files; files = files->next) {
        mx_printstr(mx_get_filename(files->data));
        mx_printstr("\n");
    }
}


