#include "uls.h"

bool mx_sizecmp(void *f1, void *f2) {
    struct stat entry, entry2;
    lstat(f1, &entry);
    long size1, size2;
    size1 = entry.st_size;
    lstat(f2, &entry2);
    size2 = entry2.st_size;
    int res = mx_strcmp(f1, f2);
    return size1 == size2 ? res > 0 : size1 < size2;
}

