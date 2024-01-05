#include "uls.h"

OutputFunction mx_get_output(flags_t *flags) {
    if(flags->longf) {
        return mx_output_long;
    } else if (flags->one) {
        return mx_output_with_flag_one;
    } else {
        return mx_simple_output;
   }
}
