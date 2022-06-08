#include "List.h"

int listSum(List l) {
    if (l == NULL) return 0;

    return l->value + listSum(l->next);
}

int listCountOdds(List l) {
    if (l == NULL) return 0;

    return (l->value % 2) + listCountOdds(l->next);
}

bool listIsSorted(List l) {
    if (l == NULL) return true;
    if (l->next == NULL) return true;

    return (l->value <= l->next->value) && listIsSorted(l->next);
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