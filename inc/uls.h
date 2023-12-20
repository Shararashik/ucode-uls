#include "../libmx/inc/libmx.h"

#include <dirent.h>
#include <errno.h>

void mx_get_flags(int argc, char *argv[], char **flags);

typedef struct flags {
    bool R, a, A, G, h, dog, e, T, l, one, C, r, t, u, c, S;
}   flags_t;


flags_t* mx_init_flags(char **flags_str, int argc);


