#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL) {
        return -1;
    }
    int wordCount = 0;
    int delimerr = 0;
    while (*str) {
        if (*str == c) {
            delimerr = 0;
        } 
        else {
            if (delimerr == 0) {
                wordCount++;
                delimerr = 1;
            }
        }
        str++;
    }
    return wordCount;
}







