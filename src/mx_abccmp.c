#include "uls.h"

bool mx_abccmp(void *s1, void *s2) {
    int res = mx_strcmp(s1, s2);
    return res > 0;
}
