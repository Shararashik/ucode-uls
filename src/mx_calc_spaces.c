#include "uls.h"

int mx_calc_spaces(int max_len) {
    int decimal = (max_len % 8);
    int spaces_sum = max_len + 8;
    int spaces = spaces_sum - decimal;
    return spaces;
}

