#include "../inc/uls.h"

bool mx_lastmodcmp(void *f1, void *f2) {
    struct stat entry, entry2;
    lstat(f1, &entry);
    long size_sec1, size_sec2, size_nano1, size_nano2;
    size_sec1 = entry.st_atimespec.tv_sec;
    size_nano1 = entry2.st_atimespec.tv_nsec;
    lstat(f2, &entry2);
    size_sec2 = entry2.st_atimespec.tv_sec;
    size_nano2 = entry2.st_atimespec.tv_nsec;
    int res = mx_strcmp(f1, f2);
    if(size_sec1 == size_sec2) {
        if(size_nano1 == size_nano2) {
            return res < 0;
        } else {
            return size_nano1 < size_nano2;
        }
    } else {
        return size_sec1 < size_sec2;
    }
}

