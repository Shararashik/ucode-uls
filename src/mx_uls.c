#include "uls.h"

void mx_uls(flags_t *flags, char *path, OutputFunction output) {
    SortComparator sort = mx_choose_sort(flags);
    t_list *files = mx_get_files(path, flags);
    // for(;files; files = files->next) {
    //     mx_printstr(files->data);
    //     mx_printstr("\n");
    // }
    //mx_sort_list(files, mx_abccmp);
    mx_sort_list(files, sort);
    mx_printstr(path);
    mx_printstr(":\n");
    output(files, flags);
    if(flags->R) {
        for(; files; files = files->next) {
            // mx_printint(1);
            struct stat entry;
            if(!lstat(files->data, &entry)) {
                // mx_printint(2);
                bool isA = flags->A;
                flags->A = true;
                // mx_printint(3);
                bool wrong_dir = !mx_check_file(files->data, flags);
                flags->A = isA;
                // mx_printint(4);
                // mx_printint(S_ISDIR(entry.st_mode));
                if(S_ISDIR(entry.st_mode) && !wrong_dir) {
                    // mx_printint(5);
                    mx_printstr("\n");
                    mx_uls(flags, files->data, output);
                }
            }
        }
    }
}
