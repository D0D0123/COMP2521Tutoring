#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

typedef struct node *Node; // writing 'Node' is the same as writing 'struct node *'
typedef struct list *List; // writing 'List' is the same as writing 'struct list *'

int sumList(List l);
void listDelete(List l, int value);
void listInsert(List l, int value);
Node newNode(int value);
List newList();
void printList(List l);

int main() {
    Node n;
    printf("size of struct node: %lu\n", sizeof(struct node));
    printf("size of Node *: %lu\n", sizeof(Node *));
    printf("size of Node: %lu\n", sizeof(Node));
    printf("size of *n: %lu\n", sizeof(*n));

    List l = newList();
    for (int i = 0; i < 5; i++) {
        listInsert(l, i);
    }
    printList(l);

    // printf("sum of list l: %d\n", sumList(l));

    listDelete(l, 0);
    printList(l);
    listDelete(l, 3);
    printList(l);

    List empty = newList();
    listDelete(empty, 7);
    printList(empty);
}





int sumList(List l) {
    return 0;
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
    // a)
    Node n = malloc(sizeof(struct node));
    // // b)
    // Node n = malloc(sizeof(Node *));
    // // c)
    // Node n = malloc(sizeof(Node));
    // // d)
    // Node n = malloc(sizeof(*n));

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







// int sumList(List l) {
//     int sum = 0;
//     Node curr = l->head;
//     while (curr != NULL) {
//         sum += curr->value;
//         curr = curr->next;
//     }
//     return sum;
// }

// void listDelete(List l, int value) {
//     if (l == NULL) return;
//     Node curr = l->head;

//     if (curr == NULL) return;

//     if (curr->value == value) {
//         l->head = curr->next;
//         free(curr);
//         return;
//     }

//     while (curr->next != NULL) {
//         if (curr->next->value == value) {
//             Node temp = curr->next;
//             curr->next = curr->next->next;
//             free(temp);
//             return;
//         }
//         curr = curr->next;
//     }
// }










