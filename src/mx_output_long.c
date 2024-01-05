#include "uls.h"

void mx_output_long(t_list *files, flags_t *flags) {
    struct stat file_stat;
    struct passwd *pw;
    struct group *gr;
    //char time_buffer[80];
    for (t_list *i = files; i; i = i->next) {
        if (lstat(i->data, &file_stat) == -1) {
            perror("Error getting file information");
            exit(EXIT_FAILURE);
        }
        mx_print_permissions(file_stat.st_mode);
        ssize_t size = listxattr(mx_get_filename(i->data), NULL, 0, 0);
        if(size > 0) {
            mx_printchar('@');
        }
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
        //char *date = 
        time_t lastModificationTime = file_stat.st_mtime;
        mx_printstr(" ");
        char *date = ctime(&lastModificationTime);
        //mx_printstr(date);
        date += 4; 
        mx_printstr(mx_strndup(date, (size_t)(mx_strlen(date) - 9)));
        mx_printstr(" ");
        //strftime(time_buffer, sizeof(time_buffer), "%b %d %H:%M", localtime(&file_stat.st_mtime));
        //mx_printstr(time_buffer);
        mx_printstr(mx_get_filename(i->data));
        // strftime(time_buffer, sizeof(time_buffer), "%b %d %H:%M", localtime(&file_stat.st_mtime));
        // mx_printstr(time_buffer);
        // Display ACL information if available
        // acl_t acl = acl_get_file(i->data, ACL_TYPE_ACCESS);
        // if (acl != NULL) {
        //     char *acl_text = acl_to_text(acl, NULL);
        //     mx_printstr(" ACL: ");
        //     mx_printstr(acl_text);
        //     acl_free(acl);
        //     free(acl_text);
        // }

        mx_printstr("\n");
    }

}
