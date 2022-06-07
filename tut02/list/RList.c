#include "List.h"

int listSum(List l) {
    return 0;
}

int listCountOdds(List l) {
    return 0;
}

bool listIsSorted(List l) {
    return false;
}

List listDelete(List l, int value) {
    if (l == NULL) return NULL;

    if (l->value == value) {
        List rest_of_list = l->next;
        free(l);
        return rest_of_list;
    } else {
        List rest_of_list = l->next;
        l->next = listDelete(rest_of_list, value);
        return l;
    }
}