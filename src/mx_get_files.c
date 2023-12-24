#include "uls.h"

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
    bool a_flag, A_flag;
    if(flags->A) {
        A_flag = true;
    }
    if(flags->a) {
        a_flag = true;
    }
    while ((entry = readdir(dir)) != NULL) {
        if(!files) {
            if(a_flag || A_flag && mx_strcmp(mx_strndup(entry->d_name, 1), ".") == 0) {
                files = mx_create_node((char *)(mx_strjoin(mx_strjoin(path, "/"), entry->d_name)));
            } else  if(a_flag && mx_strcmp(mx_strndup(entry->d_name, 2), "..") == 0) {
                files = mx_create_node((char *)(mx_strjoin(mx_strjoin(path, "/"), entry->d_name)));
            } else if(!a_flag && !A_flag && mx_strcmp(mx_strndup(entry->d_name, 1), ".") != 0) {
                files = mx_create_node((char *)(mx_strjoin(mx_strjoin(path, "/"), entry->d_name)));
            } else {
                continue;
            }
        } else {
            if(a_flag || A_flag && mx_strcmp(mx_strndup(entry->d_name, 1), ".") == 0) {
                mx_push_front(&files, (char *)(mx_strjoin(mx_strjoin(path, "/"), entry->d_name)));
            } else  if(a_flag && mx_strcmp(mx_strndup(entry->d_name, 2), "..") == 0) {
                mx_push_front(&files, (char *)(mx_strjoin(mx_strjoin(path, "/"), entry->d_name)));
            } else if(!a_flag && !A_flag && mx_strcmp(mx_strndup(entry->d_name, 1), ".") != 0) {
                mx_push_front(&files, (char *)(mx_strjoin(mx_strjoin(path, "/"), entry->d_name)));
            } else {
                continue;
            }
        }
    }
    closedir(dir);
    return files;
}
