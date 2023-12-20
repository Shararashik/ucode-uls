#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    new_node->data = data;
    new_node->next = NULL;

    if (*list == NULL) {
        *list = new_node;  
    } 
    else {
        t_list *current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;  
    }
}

