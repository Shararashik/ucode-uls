#include "uls.h"

void mx_simple_output(t_list *files, flags_t *flags) {
    int max_len = 0, count = 0;
    for(t_list *i = files; i; i = i->next) {
        char *filename = mx_get_filename(i->data);
        if(max_len < mx_strlen(filename)) {
            max_len = mx_strlen(filename);
        }
        count++;
    }
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int width = w.ws_col;
    int columns = width / max_len;
    if(!columns) {
        columns++;
    }
    int rows = count / columns + ((count % columns) ? 1 : 0);
    char *matrix[rows][columns];
    t_list *elem = files;
    for(int i = 0; i < columns; i++) {
        for(int j = 0; j < rows; j++) {
            if(elem) {
                matrix[j][i] = elem->data;
                elem = elem->next;
            } else {
                matrix[j][i] = NULL;
            }
        }
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(!matrix[i][j]){
                continue;
            }
            mx_print_filename(mx_get_filename(matrix[i][j]), matrix[i][j], flags);
            if(j != columns - 1) {
                for(int k = 0; k <= max_len - mx_strlen(mx_get_filename(matrix[i][j])); k++) {
                    mx_printstr(" ");
                }
            }
        }
        mx_printstr("\n");
    }
    // for(;files; files = files->next) {
    //     char *filename = mx_get_filename(files->data);
    //     mx_print_filename(filename, files->data, flags);
    //     mx_printstr("\n");
    // }
}
