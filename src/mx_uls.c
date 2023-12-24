#include "uls.h"

void mx_uls(flags_t *flags, char *path, OutputFunction output) {
    void sort = mx_choose_sort(flags);
    t_list *files = mx_get_files(path, &flags);
    if(flags->R) {

    } else {
        
    }
}
