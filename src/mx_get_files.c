#include "../inc/uls.h"

t_list *mx_get_files(char *path, flags_t *flags) {
    t_list *files = NULL;
    DIR *dir;
    struct dirent *entry;
    dir = opendir(path);
    if (dir == NULL) {
        //change
        perror("Error opening directory");
        return files;
    }
    while ((entry = readdir(dir)) != NULL) {
        char *new_path =(char *)(mx_strjoin(mx_strjoin(path, "/"), entry->d_name));
        if(mx_check_file(new_path, flags)) {
            mx_push_front(&files, new_path);            
        }
    }
    closedir(dir);
    return files;
}
