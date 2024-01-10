#include "../inc/uls.h"

void mx_get_flags(int argc, char *argv[], char **flags) {
    for(int i = 1; i < argc; i++) {
        flags[i - 1] = argv[i];
    }
}
