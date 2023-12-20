#include "uls.h"

int main(int argc, char *argv[])
{
    char *flags[argc - 1];
    mx_get_flags(argc, argv, flags);
    for(int i = 0; i < argc - 1; i++) {
        mx_printstr(flags[i]);
    }
    return 0;
}

