#include "uls.h"

bool mx_check_file(char *path, flags_t *flags) {
    char *filename = mx_get_filename(path);
    if(flags->A) {
        if(((filename[0] == '.' && filename[1] == '\0') || (filename[0] == '.' && filename[1] == '.' && filename[2] == '\0'))) {
            return false;
        }
    }
    else if(!flags->a && filename[0] == '.') {
        return false;
    }
    mx_strdel(&filename);
    return true;
}
