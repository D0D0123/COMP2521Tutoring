#include "List.h"

List listInsert(List l, int value) {
    if (l == NULL) {
        return newNode(value);
    } else {
        struct node *curr = l;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode(value);
        return l;
    }
}

Node *newNode(int value) {
    Node *n = malloc(sizeof(struct node));

    n->value = value;
    n->next = NULL;
    return n;
}

void printList(List l) {
    Node *curr = l;
    while (curr != NULL) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("X\n");
}

void freeList(List l) {
    Node *curr = l;
    while (curr != NULL) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
}








