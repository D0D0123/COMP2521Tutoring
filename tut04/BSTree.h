// Binary Search BSTree ADT interface
// COMP2521 Assignment 2

// !!! DO NOT MODIFY THIS FILE !!!

#ifndef BSTREE_H
#define BSTREE_H

typedef int Item;

typedef struct BSTNode *BSTree;

BSTree TreeNew(void);

void TreeFree(BSTree);

BSTree TreeGetLeft(BSTree t);

BSTree TreeGetRight(BSTree t);

BSTree TreeInsert(BSTree, Item);

void TreePrint(BSTree t);

BSTree TreeAdd(BSTree t1, BSTree t2);

void BSTreePrint(BSTree t);

////////////////////////////////////

// counts #nodes in a tree
int BSTreeNumNodes(BSTree t);

int BSTreeCountOdds(BSTree t);

// computes the height of a tree
int BSTreeHeight(BSTree t);

// counts number of internal nodes
int BSTreeCountInternal(BSTree t);

int BSTreeNodeLevel(BSTree t, int key);

int BSTreeCountGreater(BSTree t, int val);

#endif

