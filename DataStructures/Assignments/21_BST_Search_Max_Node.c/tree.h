#ifndef TREE
#define TREE

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define DUPLICATE 4
#define NO_BST 5

typedef struct NODE
{
	struct NODE *LC;
	int data;
	struct NODE *RC;
}tree;

int bst_ins(tree **root, int key);

//int del_leaf(tree *root, int key);

//int del_singlechild(tree *root, int key);

//int del_two_children(tree *root, int key); 

void print(tree *root);

int search(tree *root, int key);

int max_node(tree *root);

int min_node(tree *root);

#endif
