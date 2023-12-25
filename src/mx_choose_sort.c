#include "uls.h"

SortComparator mx_choose_sort(flags_t *flags) {
    //code various sorts of lists of file paths
    if(flags->S) {
        return mx_sizecmp;
    }
    else {
        return mx_abccmp;
    }
     //t) {
    //     return mx_sort_by_mod;
    // }
    // else if(flags->u) {
    //     return mx_sort_by_la;
    // }
    /* else if(flags-> */
}
