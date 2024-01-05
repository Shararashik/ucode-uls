#include "uls.h"

void mx_reverse_list(t_list **head) {
    t_list *prev = NULL;
    t_list *current = *head;
    t_list *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

