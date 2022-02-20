#include "List.h"

int listSum(List l) {
    int sum = 0;
    Node curr = l->head;
    while (curr != NULL) {
        sum += curr->value;
        curr = curr->next;
    }
    return sum;
}

int listCountOdds(List l) {
    int count = 0;
    Node curr = l->head;
    while (curr != NULL) {
        if (curr->value % 2 == 1)
            count += 1;
        curr = curr->next;
    }
    return count;
}

bool listIsSorted(List l) {
    Node curr = l->head;
    while (curr->next != NULL) {
        if (curr->value > curr->next->value)
            return false;
        curr = curr->next;
    }
    return true;
}


void listDelete(List l, int value) {
    if (l->head == NULL) {
        return;
    }

    if (l->head->value == value) {
        Node temp = l->head;
        l->head = l->head->next;
        free(temp);
        return;
    }

    Node curr = l->head;
    while (curr->next != NULL) {
        if (curr->next->value == value) {
            Node temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
            return;
        }
        curr = curr->next;
    }
    
}