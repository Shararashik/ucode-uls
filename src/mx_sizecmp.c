#include "uls.h"

bool mx_sizecmp(void *f1, void *f2) {
    struct stat entry;
    struct stat entry2;
    lstat(f1, &entry);
    long size1, size2;
    size1 = entry.st_size;
    lstat(f2, &entry2);
    size2 = entry2.st_size;
    // mx_printstr(f1);
    // mx_printlong(size1);
    // mx_printstr(" ");
    // mx_printstr(f2);
    // mx_printlong(size2);
    // mx_printstr("\n");
    return size1 > size2;
}
