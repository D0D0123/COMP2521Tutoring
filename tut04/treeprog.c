#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "BSTree.h"

int main() {

    BSTree t0 = TreeNew();
    int to_insert0[7] = {5, 3, 8, 1, 4, 7, 9};
    for (int i = 0; i < 7; i++) {
        t0 = TreeInsert(t0, to_insert0[i]);
    }

    TreePrintInfix(t0);
    printf("\n");
    TreePrintPrefix(t0);
    printf("\n");
    TreePrintPostfix(t0);
    printf("\n");   

    BSTree t = TreeNew();
    int to_insert[13] = {7, 5, 12, 3, 6, 9, 15, 1, 4, 8, 10, 13, 17};
    for (int i = 0; i < 13; i++) {
        t = TreeInsert(t, to_insert[i]);
    }

    printf("\n");
    BSTreePrint(t);
    printf("\n");

    printf("Num Nodes: %d\n", BSTreeNumNodes(t));
    printf("Num Odds: %d\n", BSTreeCountOdds(t));

    BSTree t2 = TreeNew();
    int to_insert2[13] = {76, 42, 114, 21, 67, 200, 120};
    for (int i = 0; i < 7; i++) {
        t2 = TreeInsert(t2, to_insert2[i]);
    }

    printf("\n");
    BSTreePrint(t2);
    printf("\n");

    printf("Height of t2: %d\n", BSTreeHeight(t2));

    printf("\n");
    BSTreePrint(t);
    printf("\n");

    printf("Num Internal Nodes: %d\n",  BSTreeCountInternal(t));

    printf("Node level of key 4: %d\n", BSTreeNodeLevel(t, 4));

    printf("Num nodes greater than 9: %d\n", BSTreeCountGreater(t, 9));

    TreeFree(t0);
    TreeFree(t);
    TreeFree(t2);
    
}