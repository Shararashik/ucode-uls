#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    if (file == NULL) {
        return NULL; 
    }
    int fd = open(file, O_RDONLY);
    if (fd == -1) {
        return NULL;
    }

    int file_size = mx_file_len(file);
    if (file_size < 0) {
        close(fd);
        return NULL; 
    }

    char *str = mx_strnew(file_size);
    if (str == NULL) {
        close(fd);
        return NULL; 
    }

    int bytes_read = read(fd, str, file_size);
    if (bytes_read != file_size) {
        close(fd);
        free(str);
        return NULL; 
    }
    close(fd); 
    return str;
}



