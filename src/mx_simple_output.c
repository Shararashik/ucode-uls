#include "../inc/uls.h"

void mx_simple_output(t_list *files, flags_t *flags, t_list *path) {
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
    char *paths[rows][columns];
    t_list *elem = files;
    t_list *path_list = path;
    for(int i = 0; i < columns; i++) {
        for(int j = 0; j < rows; j++) {
            if(elem) {
                paths[j][i] = path_list->data;
                matrix[j][i] = elem->data;
                elem = elem->next;
                path_list = path_list->next;
            } else {
                matrix[j][i] = NULL;
                paths[j][i] = NULL;
            }
        }
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(!matrix[i][j]){
                continue;
            }
            mx_print_filename(matrix[i][j], paths[i][j], flags);
            //mx_printint(columns);
            if(j != columns - 1 && matrix[i][j + 1]) {
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
}
