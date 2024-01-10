#include "uls.h"

int main(int argc, char *argv[]) {
    //test
    char *flags_str[argc - 1];
    mx_printint(1);
    mx_get_flags(argc, argv, flags_str);
    mx_printint(2);
    flags_t *flags = mx_init_flags(flags_str, argc - 1);
    mx_printint(3);
    //code mx_get_output that returns function
    OutputFunction output = mx_get_output(flags);
    mx_printint(4);
    if(flags->files_and_flags) {
        mx_printint(5);
        if(flags->files) {
            mx_printint(6);
            if (flags->r) {
                mx_reverse_list(&flags->files);
            }
            mx_printint(7);
            SortComparator sort = mx_choose_sort(flags);
            mx_printint(8);
            mx_sort_list(flags->files, sort);
            mx_printint(9);
            output(flags->files, flags);
        }
        mx_printint(10);
        for(t_list *i = flags->folders ;i; i = i->next) {
            mx_uls(flags, i->data, output, true);
        }
    } else {
        mx_uls(flags, ".", output, false);
    }
    free(flags);
    return 0;
}

