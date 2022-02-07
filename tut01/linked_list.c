#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

typedef struct node *Node;
typedef struct list *List;

int sumList(List l);
void listDelete(List l, int value);
void listInsert(List l, int value);
Node newNode(int value);
List newList();
void printList(List l);

int main() {
    List l = newList();
    for (int i = 0; i < 5; i++) {
        listInsert(l, i);
    }
    printList(l);
}

int sumList(List l) {
    return 0;
}

void listDelete(List l, int value) {
    
}

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