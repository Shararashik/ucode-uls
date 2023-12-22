#include "uls.h"

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/acl.h>
#include <errno.h>

void print_error(const char *msg) {
    write(STDERR_FILENO, msg, strlen(msg));
    exit(EXIT_FAILURE);
}

void print_entry(const char *name, const struct stat *statbuf) {
    // Write the file/directory name
    write(STDOUT_FILENO, name, strlen(name));

    // Write a newline character
    char newline = '\n';
    write(STDOUT_FILENO, &newline, 1);
}

void mx_output_with_flag_one(const char *path) {
    DIR *dir = opendir(".");
    if (dir == NULL) {
        print_error("opendir");
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.' || entry->d_name[1] == '\0') {  // Exclude hidden files
            print_entry(entry->d_name, &statbuf);
        }
    }

    if (closedir(dir) == -1) {
        print_error("closedir");
    }
}


