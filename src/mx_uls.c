#include "uls.h"

void mx_uls(flags_t *flags, char *path, OutputFunction output, bool title) {
    SortComparator sort = mx_choose_sort(flags);
    t_list *files;
    if(flags->files_and_flags) {
        files = flags->folders;
        mx_sort_list(flags->files, sort);
    } else {
        files = mx_get_files(path, flags);
    }
    if(flags->files) {
        output(flags->files, flags);
    }
    // for(t_list *i = flags->files ;i; i = i->next) {
    //     mx_printstr(i->data);
    //     mx_printstr("\n");
    // }
    mx_sort_list(files, mx_abccmp);
    mx_sort_list(files, sort);
    if (flags->r) {
        mx_reverse_list(&files);
    }
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

