#include "uls.h"

void mx_uls(flags_t *flags, char *path, OutputFunction output, bool title) {
    SortComparator sort = mx_choose_sort(flags);
    t_list *files = mx_get_files(path, flags);
    // for(;files; files = files->next) {
    //     mx_printstr(files->data);
    //     mx_printstr("\n");
    // }
    //mx_sort_list(files, mx_abccmp);
    mx_sort_list(files, sort);
    if(title) {
        mx_printstr(path);
        mx_printstr(":\n");
    }
    output(files, flags);
    if(flags->R) {
        for(; files; files = files->next) {
            struct stat entry;
            if(!lstat(files->data, &entry)) {
                bool isA = flags->A;
                flags->A = true;
                bool wrong_dir = !mx_check_file(files->data, flags);
                flags->A = isA;
                if(S_ISDIR(entry.st_mode) && !wrong_dir) {
                    mx_printstr("\n");
                    mx_uls(flags, files->data, output, true);
                }
            }
        }
    }
}

