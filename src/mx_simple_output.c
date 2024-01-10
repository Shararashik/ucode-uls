#include "uls.h"

void mx_simple_output(t_list *files, flags_t *flags) {
    int max_len = 0, count = 0;
    for(t_list *i = files; i; i = i->next) {
        char *filename = i->data;
        if(max_len < mx_strlen(filename)) {
            max_len = mx_strlen(filename);
        }
        count++;
    }
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int width = w.ws_col;
    
    int columns = width / max_len;
    if(!flags->G) {
        columns = width / mx_calc_spaces(max_len);
    }
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
            mx_print_filename(matrix[i][j], matrix[i][j], flags);
            if(j != columns - 1) {
                int len = mx_strlen(matrix[i][j]);
                if (flags->G) {
                    for(int k = 0; k <= max_len - mx_strlen(matrix[i][j]); k++) {
                        mx_printstr(" ");
                    }                    
                }
                else {
                    //mx_printstr("\t");
                    int tabs = mx_calc_spaces(max_len) - len;
                    int tabs_count = tabs / 8;
                    if (tabs % 8 != 0) {
                        tabs_count++;
                    }
                    for(int k = 0; k < tabs_count; k++) {
                        mx_printstr("\t");
                    }                      
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
