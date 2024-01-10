#include "uls.h"

void mx_list_clear(t_list **list) {
    for(; *list; ) {
        mx_pop_front(list);
    }
}
