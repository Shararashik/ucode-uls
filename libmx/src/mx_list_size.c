#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    int count = 0;
    t_list *current = list;

    if (list == NULL) {
        return 0;
    }

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

