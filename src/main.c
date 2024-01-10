#include "uls.h"

int main(int argc, char *argv[]) {
    //test
    char *flags_str[argc - 1];
    mx_get_flags(argc, argv, flags_str);
    flags_t *flags = mx_init_flags(flags_str, argc - 1);
    //code mx_get_output that returns function
    mx_uls(flags, ".", mx_get_output(flags), false, flags->files_and_flags);
 
    return 0;
}

