// Binary Search BSTree ADT implementation
// COMP2521 Assignment 2

// !!! DO NOT MODIFY THIS FILE !!!

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BSTree.h"

#define data(tree)  ((tree)->data)
#define left(tree)  ((tree)->left)
#define right(tree) ((tree)->right)

int max(int a, int b);

typedef struct BSTNode {
	int  data;
	BSTree left;
	BSTree right;
} BSTNode;

// make a new node containing data
static BSTree newNode(Item it) {
	BSTree new = malloc(sizeof(BSTNode));
	assert(new != NULL);
	data(new) = it;
	left(new) = right(new) = NULL;
	return new;
}

BSTree TreeNew(void) {
	return NULL;
}

void TreeFree(BSTree t) {
	if (t != NULL) {
		TreeFree(left(t));
		TreeFree(right(t));
		free(t);
	}
}

BSTree TreeGetLeft(BSTree t) {
	if (t == NULL) {
		return NULL;
	}
	return left(t);
}

BSTree TreeGetRight(BSTree t) {
	if (t == NULL) {
		return NULL;
	}
	return right(t);
}

BSTree TreeInsert(BSTree t, Item it) {
	if (t == NULL) {
		t = newNode(it);
	} else if (it < data(t)) {
		left(t) = TreeInsert(left(t), it);
	} else if (it > data(t)) {
		right(t) = TreeInsert(right(t), it);
	}
	return t;
}

void TreePrintInfix(BSTree t) {
	if (t == NULL) {
		return;
	}

	TreePrintInfix(t->left);

	printf("%d ", data(t));

	TreePrintInfix(t->right);
}

void TreePrintPrefix(BSTree t) {
	if (t == NULL) {
		return;
	}

	printf("%d ", data(t));

	TreePrintPrefix(t->left);

	TreePrintPrefix(t->right);
}

void TreePrintPostfix(BSTree t) {
	if (t == NULL) {
		return;
	}

	TreePrintPostfix(t->left);

	TreePrintPostfix(t->right);

	printf("%d ", data(t));
}

BSTree TreeAdd(BSTree t1, BSTree t2) {
	if (t2 == NULL) {
		return t1;
	}

	BSTree t = TreeInsert(t1, data(t2));
	t = TreeAdd(t, left(t2));
	t = TreeAdd(t, right(t2));
	return t;
}

// counts #nodes in a tree
int BSTreeNumNodes(BSTree t) {
	return 0; //TODO
}

/*
int BSTreeNumNodes(BSTree t) {

	if (t == NULL) {
		return 0;
	}

	return 1 + BSTreeNumNodes(t->left) + BSTreeNumNodes(t->right);

}*/

int BSTreeCountOdds(BSTree t) {
	return 0; //TODO
}

/*
int BSTreeCountOdds(BSTree t) {
	
	if (t == NULL) return 0;

	if (t->data % 2 == 1) {
		return 1 + BSTreeCountOdds(t->left) + BSTreeCountOdds(t->right);
	} else {
		return 0 + BSTreeCountOdds(t->left) + BSTreeCountOdds(t->right);
	}
}*/

// computes the height of a tree
int BSTreeHeight(BSTree t) {
	return 0; //TODO
}

/*
int BSTreeHeight(BSTree t) {
	if (t == NULL) return -1;

	int lheight = BSTreeHeight(t->left);
	int rheight = BSTreeHeight(t->right);

	return 1 + max(lheight, rheight);

}*/

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

// counts number of internal nodes
int BSTreeCountInternal(BSTree t) {
	return 0; //TODO
}

/*
int BSTreeCountInternal(BSTree t) {
	if (t == NULL) return 0;
	if (t->left == NULL && t->right == NULL) return 0;

	return 1 + BSTreeCountInternal(t->left) + BSTreeCountInternal(t->right);
}*/

int BSTreeNodeLevel(BSTree t, int key) {
	if (t == NULL) 
		return -1;
	else if (t->data == key) 
		return 0;
	else if (key < t->data) {
		int ndl = BSTreeNodeLevel(t->left, key);
		if (ndl == -1) return -1;
		return ndl + 1;
	} else {
		int ndr = BSTreeNodeLevel(t->right, key);
		if (ndr == -1) return -1;
		return ndr + 1;
	}
}

int BSTreeCountGreater(BSTree t, int val) {
	return 0; //TODO
}

/*
int BSTreeCountGreater(BSTree t, int val) {
	if (t == NULL) return 0;

	if (t->data > val) {
		return 1 + BSTreeCountGreater(t->left, val) + BSTreeCountGreater(t->right, val);
	} else {
		return 0 + BSTreeCountGreater(t->right, val);
	}
}*/




////////////////////////////////////////////////////////////////////////

// ASCII tree printer
// Courtesy: ponnada
// Via: http://www.openasthra.com/c-tidbits/printing-binary-trees-in-ascii/

static void doShowBSTree(BSTree t);

// Displays the given BSTree on stdout
void BSTreePrint(BSTree t) {
	doShowBSTree(t);
}

// data structures
typedef struct asciinode_struct asciinode;
struct asciinode_struct {
	asciinode *left, *right;
	// length of the edge from this node to its children
	int edge_length;
	int height;
	int lablen;
	//-1=I am left, 0=I am root, 1=I am right
	int parent_dir;
	// max supported unit32 in dec, 10 digits max
	char label[11];
};

// functions
static void print_level(asciinode *node, int x, int level);
static void compute_edge_lengths(asciinode *node);
static void compute_lprofile(asciinode *node, int x, int y);
static void compute_rprofile(asciinode *node, int x, int y);
static asciinode *build_ascii_tree(BSTree t);
static void free_ascii_tree(asciinode *node);

#define MAX_HEIGHT 1000
static int lprofile[MAX_HEIGHT];
static int rprofile[MAX_HEIGHT];
#define INFINITY (1 << 20)

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

static int gap = 3; // gap between left and right nodes

// used for printing next node in the same level,
// this is the x coordinate of the next char printed
static int print_next;

// prints ascii tree for given Tree structure
static void doShowBSTree(BSTree t)
{
	asciinode *proot;
	int xmin, i;
	if (t == NULL)
		return;
	proot = build_ascii_tree(t);
	compute_edge_lengths(proot);
	for (i = 0; i < proot->height && i < MAX_HEIGHT; i++)
		lprofile[i] = INFINITY;
	compute_lprofile(proot, 0, 0);
	xmin = 0;
	for (i = 0; i < proot->height && i < MAX_HEIGHT; i++)
		xmin = MIN(xmin, lprofile[i]);
	for (i = 0; i < proot->height; i++) {
		print_next = 0;
		print_level(proot, -xmin, i);
		printf("\n");
	}
	if (proot->height >= MAX_HEIGHT) {
		printf(
			"(Tree is taller than %d; may be drawn incorrectly.)\n",
			MAX_HEIGHT);
	}
	free_ascii_tree(proot);
}

// This function prints the given level of the given tree, assuming
// that the node has the given x cordinate.
static void print_level(asciinode *node, int x, int level)
{
	int i, isleft;
	if (node == NULL)
		return;
	isleft = (node->parent_dir == -1);
	if (level == 0) {
		for (i = 0;
			 i < (x - print_next - ((node->lablen - isleft) / 2));
			 i++)
			printf(" ");
		print_next += i;
		printf("%s", node->label);
		print_next += node->lablen;
	} else if (node->edge_length >= level) {
		if (node->left != NULL) {
			for (i = 0; i < (x - print_next - (level)); i++) {
				printf(" ");
			}
			print_next += i;
			printf("/");
			print_next++;
		}
		if (node->right != NULL) {
			for (i = 0; i < (x - print_next + (level)); i++) {
				printf(" ");
			}
			print_next += i;
			printf("\\");
			print_next++;
		}
	} else {
		print_level(
			node->left,
			x - node->edge_length - 1,
			level - node->edge_length - 1);
		print_level(
			node->right,
			x + node->edge_length + 1,
			level - node->edge_length - 1);
	}
}

// This function fills in the edge_length and
// height fields of the specified tree
static void compute_edge_lengths(asciinode *node)
{
	int h, hmin, i, delta;
	if (node == NULL)
		return;
	compute_edge_lengths(node->left);
	compute_edge_lengths(node->right);

	/* first fill in the edge_length of node */
	if (node->right == NULL && node->left == NULL)
		node->edge_length = 0;
	else {
		if (node->left == NULL)
			hmin = 0;
		else {
			for (i = 0; i < node->left->height && i < MAX_HEIGHT; i++)
				rprofile[i] = -INFINITY;
			compute_rprofile(node->left, 0, 0);
			hmin = node->left->height;
		}
		if (node->right == NULL)
			hmin = 0;
		else {
			for (i = 0; i < node->right->height && i < MAX_HEIGHT; i++)
				lprofile[i] = INFINITY;
			compute_lprofile(node->right, 0, 0);
			hmin = MIN(node->right->height, hmin);
		}
		delta = 4;
		for (i = 0; i < hmin; i++) {
			int w = gap + 1 + rprofile[i] - lprofile[i];
			delta = (delta > w) ? delta : w;
		}

		// If the node has two children of height 1, then we allow the
		// two leaves to be within 1, instead of 2
		if (((node->left != NULL && node->left->height == 1) ||
			(node->right != NULL && node->right->height == 1)) &&
			delta > 4)
			delta--;
		node->edge_length = ((delta + 1) / 2) - 1;
	}

	// now fill in the height of node
	h = 1;
	if (node->left != NULL)
		h = MAX(node->left->height + node->edge_length + 1, h);
	if (node->right != NULL)
		h = MAX(node->right->height + node->edge_length + 1, h);
	node->height = h;
}

static asciinode *build_ascii_tree_recursive(BSTree t)
{
	asciinode *node;

	if (t == NULL)
		return NULL;
	node = malloc(sizeof(asciinode));
	node->left = build_ascii_tree_recursive(t->left);
	node->right = build_ascii_tree_recursive(t->right);
	if (node->left != NULL)
		node->left->parent_dir = -1;
	if (node->right != NULL)
		node->right->parent_dir = 1;
	sprintf(node->label, "%d", t->data);
	node->lablen = (int) strlen(node->label);

	return node;
}

// Copy the tree into the ascii node structre
static asciinode *build_ascii_tree(BSTree t)
{
	asciinode *node;
	if (t == NULL)
		return NULL;
	node = build_ascii_tree_recursive(t);
	node->parent_dir = 0;
	return node;
}

// Free all the nodes of the given tree
static void free_ascii_tree(asciinode *node)
{
	if (node == NULL)
		return;
	free_ascii_tree(node->left);
	free_ascii_tree(node->right);
	free(node);
}

// The following function fills in the lprofile array for the given
// tree. It assumes that the center of the label of the root of this tree
// is located at a position(x,y).  It assumes that the edge_length
// fields have been computed for this tree.
static void compute_lprofile(asciinode *node, int x, int y)
{
	int i, isleft;
	if (node == NULL)
		return;
	isleft = (node->parent_dir == -1);
	lprofile[y] = MIN(lprofile[y], x - ((node->lablen - isleft) / 2));
	if (node->left != NULL) {
		for (i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++)
			lprofile[y + i] = MIN(lprofile[y + i], x - i);
	}
	compute_lprofile(
		node->left,
		x - node->edge_length - 1,
		y + node->edge_length + 1);
	compute_lprofile(
		node->right,
		x + node->edge_length + 1,
		y + node->edge_length + 1);
}

static void compute_rprofile(asciinode *node, int x, int y)
{
	int i, notleft;
	if (node == NULL)
		return;
	notleft = (node->parent_dir != -1);
	rprofile[y] = MAX(rprofile[y], x + ((node->lablen - notleft) / 2));
	if (node->right != NULL) {
		for (i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++)
			rprofile[y + i] = MAX(rprofile[y + i], x + i);
	}
	compute_rprofile(
		node->left,
		x - node->edge_length - 1,
		y + node->edge_length + 1);
	compute_rprofile(
		node->right,
		x + node->edge_length + 1,
		y + node->edge_length + 1);
}