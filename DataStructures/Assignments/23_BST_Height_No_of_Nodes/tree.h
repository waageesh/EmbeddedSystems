#ifndef TREE
#define TREE

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define DUPLICATE 4
#define NO_BST 5

//structure of bst
struct node  
{ 
    int data; 
    struct node* left; 
    struct node* right; 
};


//function declarations 
struct node *insert(struct node *root, int val);  
int maxheight(struct node* node);  
struct node* newNode(int data);
int countnodes(struct node *root);
 

#endif
