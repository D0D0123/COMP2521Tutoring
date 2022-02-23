#include "List.h"

int listSum(List l) {
    int sum = 0;
    Node *curr = l;
    while (curr != NULL) {
        sum += curr->value;
        curr = curr->next;
    }
    return sum;
}

int listCountOdds(List l) {
    int count = 0;
    Node *curr = l;
    while (curr != NULL) {
        if (curr->value % 2 == 1)
            count += 1;
        curr = curr->next;
    }
    return count;
}

bool listIsSorted(List l) {
    Node *curr = l;
    while (curr->next != NULL) {
        if (curr->value > curr->next->value)
            return false;
        curr = curr->next;
    }
    return true;
}


List listDelete(List l, int value) {
    if (l == NULL) {
        return NULL;
    }

    if (l->value == value) {
        Node *temp = l;
        l = l->next;
        free(temp);
        return l;
    }

    Node *curr = l;
    while (curr->next != NULL) {
        if (curr->next->value == value) {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
            return l;
        }
        curr = curr->next;
    }

    return l;
    
}