#include "uls.h"

bool mx_timecmp(void *f1, void *f2) {
    struct stat entry, entry2;
    lstat(f1, &entry);
    // long size_sec1, size_sec2, size_nano1, size_nano2;
    // size_sec1 = entry.st_mtimespec.tv_sec;
    // size_nano1 = entry2.st_mtimespec.tv_nsec;
    lstat(f2, &entry2);
    // size_sec2 = entry2.st_mtimespec.tv_sec;
    // size_nano2 = entry2.st_mtimespec.tv_nsec;
    // int res = mx_strcmp(f1, f2);
    // if(size_sec1 == size_sec2) {
    //     if(size_nano1 == size_nano2) {
    //         return res < 0;
    //     } else {
    //         return size_nano1 < size_nano2;
    //     }
    // } else {
    //     return size_sec1 < size_sec2;
    // }
    return true;
}

