#include "uls.h"

SortComparator mx_choose_sort(flags_t *flags) {
    //code various sorts of lists of file paths
    // if(flags->t) {
    //     return mx_sort_by_mod;
    // }
    // else if(flags->u) {
    //     return mx_sort_by_la;
    // }
    // else if(flags->S) {
    //     return mx_sort_by_size;
    // }
    // else {
        return mx_abccmp;
    // }
}
