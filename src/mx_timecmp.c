#include "uls.h"

bool mx_timecmp(void *f1, void *f2) {
    struct stat entry, entry2;
    stat(f1, &entry);
    stat(f2, &entry2);

    // Сравниваем даты последней модификации файлов
    if (entry.st_mtime < entry2.st_mtime) {
        return true; // Порядок сохраняется
    } else if (entry.st_mtime > entry2.st_mtime) {
        return false; // Порядок меняется
    } else if (entry.st_mtim.tv_nsec < entry2.st_mtim.tv_nsec) {
        return true; // Порядок сохраняется (учитывая миллисекунды)
    } else if (entry.st_mtim.tv_nsec > entry2.st_mtim.tv_nsec) {
        return false; // Порядок меняется (учитывая миллисекунды)
    }

    return true;
}

