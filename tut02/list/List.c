#include "List.h"

void listInsert(List l, int value) {
    if (l->head == NULL) {
        l->head = newNode(value);
    } else {
        Node n = newNode(value);
        Node curr = l->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = n;
    }
}

Node newNode(int value) {
    Node n = malloc(sizeof(struct node));

    n->value = value;
    n->next = NULL;
    return n;
}

List newList() {
    List l = malloc(sizeof(struct list));
    l->head = NULL;
    return l;
}

void printList(List l) {
    Node curr = l->head;
    while (curr != NULL) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("X\n");
}

void freeList(List l) {
    Node curr = l->head;
    while (curr != NULL) {
        Node next = curr->next;
        free(curr);
        curr = next;
    }
    free(l);
}








