#include "uls.h"

static void struct_bubble_sort(struct dirent **arr, int n) {
    int swapped;
    struct dirent *temp;

    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j]->d_name, arr[j + 1]->d_name) > 0) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

void mx_output_with_flag_one(flags_t **flags_init) {
    flags_t *flags = *flags_init;
    DIR *dir = opendir(".");
    if (dir == NULL) {
        mx_printstr("opendir");
    }

    struct dirent **namelist;
    int n = 0;
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (flags->A == true && flags->a == false) {
            if ((mx_strcmp(entry->d_name, ".")) && (mx_strcmp(entry->d_name, "..")) && (entry->d_name[1] != '.')) {
                n++;
            }
        }
        else if (flags->a == true) {
            n++;
        }
        else if (entry->d_name[0] != '.') {
            n++;
        }
    }

    closedir(dir);

    namelist = malloc(n * sizeof(struct dirent *));

    dir = opendir(".");
    n = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (flags->A == true && flags->a == false) {
            if ((mx_strcmp(entry->d_name, ".")) && (mx_strcmp(entry->d_name, "..")) && (entry->d_name[1] != '.')) {
                namelist[n++] = entry;
            }
        }
        else if (flags->a == true) {
            namelist[n++] = entry;
        }
        else if (entry->d_name[0] != '.') {
            namelist[n++] = entry;
        }
    }

    closedir(dir);
    struct_bubble_sort(namelist, n);//alpabet order
    for (int i = 0; i < n; ++i) {
        // Write the file/directory name
        write(STDOUT_FILENO, namelist[i]->d_name, strlen(namelist[i]->d_name));

        // Write a newline character
        char newline = '\n';
        write(STDOUT_FILENO, &newline, 1);
    }

    free(namelist);
}


