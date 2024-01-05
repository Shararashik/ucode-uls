#include "uls.h"

SortComparator mx_choose_sort(flags_t *flags) {
    //code various sorts of lists of file paths
    if(flags->S) {
        return mx_sizecmp;
    }
    else if(flags->t) {
        return mx_timecmp;
    }  
    else {
        return mx_abccmp;
    }

    /* else if(flags-> */
}
