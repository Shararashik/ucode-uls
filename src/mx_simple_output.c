#include "uls.h"

void print_permissions(mode_t mode) {
    char permissions[10];
    permissions[0] = (mode & S_IRUSR) ? 'r' : '-';
    permissions[1] = (mode & S_IWUSR) ? 'w' : '-';
    permissions[2] = (mode & S_IXUSR) ? 'x' : '-';
    permissions[3] = (mode & S_IRGRP) ? 'r' : '-';
    permissions[4] = (mode & S_IWGRP) ? 'w' : '-';
    permissions[5] = (mode & S_IXGRP) ? 'x' : '-';
    permissions[6] = (mode & S_IROTH) ? 'r' : '-';
    permissions[7] = (mode & S_IWOTH) ? 'w' : '-';
    permissions[8] = (mode & S_IXOTH) ? 'x' : '-';
    permissions[9] = '\0';

    mx_printstr(permissions);
}

void mx_simple_output(void) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    struct passwd *pw;
    struct group *gr;
    //char time_buffer[80];

    dir = opendir(".");
    if (dir == NULL) {
        //err
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }
    while ((entry = readdir(dir)) != NULL) {
        char full_path[1024] = ".";
        write(STDOUT_FILENO, entry->d_name, strlen(entry->d_name));
        mx_printint(4);
        if (lstat(full_path, &file_stat) == -1) {
            perror("Error getting file information");
            exit(EXIT_FAILURE);
        }

        print_permissions(file_stat.st_mode);
        mx_printstr(" ");
        mx_printlong((long)file_stat.st_nlink);
        mx_printstr(" ");
        pw = getpwuid(file_stat.st_uid);      
        gr = getgrgid(file_stat.st_gid);
        mx_printstr((pw != NULL) ? pw->pw_name : "unknown");
        mx_printstr(" ");
        mx_printstr((gr != NULL) ? gr->gr_name : "unknown");
        mx_printstr(" ");

        mx_printlong((long long)file_stat.st_size);
        mx_printstr(" ");

        // strftime(time_buffer, sizeof(time_buffer), "%b %d %H:%M", localtime(&file_stat.st_mtime));
        // mx_printstr(time_buffer);
        // Display ACL information if available
        acl_t acl = acl_get_file(full_path, ACL_TYPE_ACCESS);
        if (acl != NULL) {
            char *acl_text = acl_to_text(acl, NULL);
            mx_printstr(" ACL: ");
            mx_printstr(acl_text);
            acl_free(acl);
            free(acl_text);
        }

        mx_printstr("\n");
    }

    closedir(dir);
}

