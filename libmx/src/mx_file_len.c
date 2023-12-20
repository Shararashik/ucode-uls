#include "../inc/libmx.h"

int mx_file_len(const char *file) {
    int fd = open(file, O_RDONLY);
    int len = 0;
    char buf;
    if (fd == -1) {
        return -1; 
    }
    int sz;
    for (sz = read(fd, &buf, 1); sz > 0; sz = read(fd, &buf, 1)) {
        len++;
    }
    close(fd);
    return len;
}


