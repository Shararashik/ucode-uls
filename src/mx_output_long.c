#include "../inc/uls.h"

void mx_output_long(t_list *files, flags_t *flags, t_list *path) {
    struct stat file_stat;
    struct passwd *pw;
    struct group *gr;
    int perm_max = 0;
    long link_max = 0;
    long size_max = 0;
    acl_t acl;
    long total_blocks = 0;
    for (t_list *i = files, *x = path; i && x; x = x->next, i = i->next) {
        char *permissions = mx_strdup(mx_get_permissions(file_stat.st_mode));
        ssize_t size = listxattr(x->data, NULL, 0, 0);
        if(size > 0) {
            permissions = mx_strjoin(permissions, "@");
        }
        if(mx_strlen(permissions) > perm_max) {
            perm_max = mx_strlen(permissions);
        }
        if (lstat(x->data, &file_stat) == -1) {
            mx_file_error(i->data);
            exit(EXIT_FAILURE);
        }
        total_blocks += file_stat.st_blocks;
        if(link_max < (long)file_stat.st_nlink) {
            link_max = (long)file_stat.st_nlink;
        }
        if(flags->h) {
            const char *units[] = {"B", "K", "M", "G", "T"};
            int j = 0;
            double size_in_units = (double)file_stat.st_size;
            while (size_in_units >= 1024 && (unsigned long)j < sizeof(units) / sizeof(units[0]) - 1) {
                size_in_units /= 1024;
                j++;
            }
            if(size_max < (long)mx_strlen(mx_strjoin(mx_itoa((int)size_in_units), units[j]))) {
                size_max = (long)mx_strlen(mx_strjoin(mx_itoa((int)size_in_units), units[j]));
            }
        } else {
            if(size_max < (long)file_stat.st_size) {
                size_max = (long)file_stat.st_size;
            }
        }
        
    }
    mx_printstr("total ");
    mx_printlong(total_blocks);
    mx_printstr("\n");
    int l_len;
    for(l_len = 0; link_max != 0; l_len++) {
        link_max /= 10;
    }
    int s_len;
    if(!flags->h) {
        for(s_len = 0; size_max != 0; s_len++) {
            size_max /= 10;;
        }
    }
    for(t_list *i = files, *x = path; i && x;x = x->next, i = i->next) {
        if (lstat(x->data, &file_stat) == -1) {
            mx_file_error(x->data);
            exit(EXIT_FAILURE);
        }
        char *permissions = mx_strdup(mx_get_permissions(file_stat.st_mode));
        size_t size = listxattr(x->data, NULL, 0, 0);
        acl = acl_get_file(x->data, ACL_TYPE_ACCESS);
        if(size > 0) {
            permissions = mx_strjoin(permissions, "@");
        }
        mx_printstr(permissions);
        if(mx_strlen(permissions) != perm_max) {
            mx_printstr("  ");
        } else {
            mx_printstr(" ");
        }
        int len = 0;
        long link_len = (long)file_stat.st_nlink;
        for (int i = 0; link_len != 0; i++) {
            link_len /= 10;
            len = i;
        }
        for (int i = 0; i < l_len - len - 1; i++) {
            mx_printstr(" ");
        }
        mx_printlong((long)file_stat.st_nlink);
        mx_printstr(" ");
        pw = getpwuid(file_stat.st_uid);      
        gr = getgrgid(file_stat.st_gid);
        mx_printstr((pw != NULL) ? pw->pw_name : "unknown");
        mx_printstr("  ");
        mx_printstr((gr != NULL) ? gr->gr_name : "unknown");
        mx_printstr("  ");
        //kilobytes, bytes
        if(flags->h) {
            const char *units[] = {"B", "K", "M", "G", "T"};
            int j = 0;
            double size_in_units = (double)file_stat.st_size;
            while (size_in_units >= 1024 && (unsigned long)j < sizeof(units) / sizeof(units[0]) - 1) {
                size_in_units /= 1024;
                j++;
            }
            for(long i = 0; i <= size_max - (long)mx_strlen(mx_strjoin(mx_itoa((int)size_in_units), units[j])); i++) {
                mx_printstr(" ");
            }
            mx_printstr(mx_strjoin(mx_itoa((int)size_in_units), units[j]));
        } else {
            long size_len = (long)file_stat.st_size;
            int count;
            for(count = 0; size_len != 0; count++) {
                size_len /= 10;
            }
            for(long i = 0; i < s_len - count; i++) {
                mx_printstr(" ");
            }
            mx_printlong((long)file_stat.st_size); 
        }
        time_t t_date;
        if(flags->u) {
            t_date = file_stat.st_atime;
        }
        else if(flags->c) {
            t_date = file_stat.st_ctime;
        }
        else {
            t_date = file_stat.st_mtime;
        }
        mx_printstr(" ");
        char *date = ctime(&t_date);
        date += 4; 
        int flag_T = 9;
        if(flags->T) {
            flag_T = 1;
        }
        mx_printstr(mx_strndup(date, (size_t)(mx_strlen(date) - flag_T)));
        mx_printstr(" ");
        mx_print_filename(i->data, x->data, flags);
        acl_free(acl);
        mx_printstr("\n");
        if(flags->dog && size > 0) {
            char value[256];
            char *attrBuffer = (char *)malloc((long)size);
            // long attrCount = 0;
            listxattr(x->data, attrBuffer, (long)size, 0);
            // for (long j = 0; j < long; j += mx_strlen(&attrBuffer[j]) + 1) {
            //     mx_printchar(attrBuffer[j]);
            // }
            while(*attrBuffer != '\0') {
                ssize_t value_size = getxattr(i->data, attrBuffer, value, sizeof(value), 0, 0);
                if(value_size != -1) {
                    mx_printstr(value);
                }
                attrBuffer++;
            }
            
            mx_printstr("\n");
        }
        if(flags->e) {
            acl = acl_get_file(x->data, ACL_TYPE_ACCESS);
            if(acl) {
                char *acl_text = acl_to_text(acl, NULL);
                mx_printstr(acl_text);
                acl_free(acl);
                free(acl_text);
                mx_printstr("\n");
            }
        }

    }

}
