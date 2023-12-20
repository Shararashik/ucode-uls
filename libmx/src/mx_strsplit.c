#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (s == NULL) {
        return NULL;
    }
    const char *start = s;
    bool dellerr = false;
    char **arr = (char **)malloc((mx_count_words(s, c) + 1) * sizeof(char *));
    if (arr == NULL) {
        return NULL;
    }
    s = start;
    int i = 0;
    while (*s) {
        if (*s == c) {
            if (dellerr) {
                dellerr = false;
                arr[i] = (char *)malloc((s - start + 1) * sizeof(char));
                if (arr[i] == NULL) {
                    return NULL;
                }
                mx_strncpy(arr[i], start, s - start);
                arr[i][s - start] = '\0';
                i++;
            }
        } 
        else {
            if (!dellerr) {
                dellerr = true;
                start = s;
            }
        }
        s++;
    }
    if (dellerr) {
        arr[i] = (char *)malloc((s - start + 1) * sizeof(char));
        if (arr[i] == NULL) {
            return NULL;
        }
        mx_strncpy(arr[i], start, s - start);
        arr[i][s - start] = '\0';
        i++;
    }
    arr[i] = NULL;
    return arr;
}







