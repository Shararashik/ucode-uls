#include "../inc/uls.h"

void mx_uls(flags_t *flags, char *path, OutputFunction output, bool title) {
    SortComparator sort = mx_choose_sort(flags);
    t_list *files;
    files = mx_get_files(path, flags);
    // for(t_list *i = flags->files ;i; i = i->next) {
    //     mx_printstr(i->data);
    //     mx_printstr("\n");
    // }
    mx_sort_list(files, sort);
    if (flags->r) {
        mx_reverse_list(&files);
    }
    if(title) {
        mx_printstr(path);
        mx_printstr(":\n");
    }
    t_list *names = NULL;
    for(t_list *i = files ;i; i = i->next) {
        mx_push_back(&names, mx_get_filename(i->data));
    }
    output(names, flags, files);
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

