#include "uls.h"

int main(int argc, char *argv[]) {
    //test
    char *flags_str[argc - 1];
    mx_get_flags(argc, argv, flags_str);
    flags_t *flags = mx_init_flags(flags_str, argc - 1);
    //code mx_get_output that returns function
    OutputFunction output = mx_get_output(flags);
    if(flags->files_and_flags) {
        if(flags->files) {
             if (flags->r) {
                mx_reverse_list(&flags->files);
            }
            SortComparator sort = mx_choose_sort(flags);
            mx_sort_list(flags->files, sort);
            output(flags->files, flags);
        }
        for(t_list *i = flags->folders ;i; i = i->next) {
            mx_uls(flags, i->data, output, true, flags->files_and_flags);
        }
    } else {
        mx_uls(flags, ".", output, false, flags->files_and_flags);
    }
    free(flags);
    return 0;
}

