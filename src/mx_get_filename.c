#include "../inc/uls.h"

char *mx_get_filename(char *str) {
    char *filename = str;
    for(; *str; str++){
        if(*str == '/') {
            filename = str + 1;
        }
    }
    return mx_strdup(filename);
}
