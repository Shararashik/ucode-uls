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
            SortComparator sort = mx_choose_sort(flags);
            mx_sort_list(flags->files, sort);
            if (flags->r) {
                mx_reverse_list(&flags->files);
            }
            output(flags->files, flags);
        }
        bool isFirst = true;
        for(t_list *i = flags->folders ;i; i = i->next) {
            if(!isFirst || flags->files) {
                mx_printstr("\n");
            }
            SortComparator sort = mx_choose_sort(flags);
            if (flags->r) {
                mx_reverse_list(&flags->folders);
            }
            mx_sort_list(flags->folders, sort);
            mx_uls(flags, i->data, output, true);
            isFirst = false;
        }
    } else {
        mx_uls(flags, ".", output, false);
    }
    free(flags);
    return 0;
}

