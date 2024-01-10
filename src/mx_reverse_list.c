#include "uls.h"

void mx_reverse_list(t_list **head) {
    t_list *new_list = NULL;
    for(t_list *i = *head; i; i = i->next) {
        mx_push_front(&new_list, i->data);
    }
    mx_list_clear(head);
    *head = new_list;
}

