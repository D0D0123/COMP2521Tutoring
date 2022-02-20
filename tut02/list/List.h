#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

typedef struct node *Node; // writing 'Node' is the same as writing 'struct node *'
typedef struct list *List; // writing 'List' is the same as writing 'struct list *'

int listSum(List l);
void listDelete(List l, int value);
void listInsert(List l, int value);
int listCountOdds(List l);
bool listIsSorted(List l);
Node newNode(int value);
List newList();
void printList(List l);
void freeList(List l);

#endif