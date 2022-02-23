#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef Node *List; // writing 'List' is the same as writing 'struct node *'

int listSum(List l);
List listDelete(List l, int value);
List listInsert(List l, int value);
int listCountOdds(List l);
bool listIsSorted(List l);
Node *newNode(int value);
List newList();
void printList(List l);
void freeList(List l);

#endif