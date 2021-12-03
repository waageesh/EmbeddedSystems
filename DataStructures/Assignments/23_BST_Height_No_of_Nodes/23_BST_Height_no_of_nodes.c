/* 
Title  : BST_height_No_of_Nodes
Author : Vaageesh
Date   : Monday 14 December 2020 11:40:49 PM IST
*/
 
#include<stdio.h> 
#include<stdlib.h> 

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
 
int main() 
{ 
    int count = 0;
    struct node *root = NULL;  	//initialising root with null 
	root = insert(root, 45);  	// inserting nodes into bst
	root = insert(root, 50);
	root = insert(root, 15);
	root = insert(root, 185); 
    root = insert(root, 190);
    printf("Height of tree is %d", maxheight(root)); 
    count = countnodes(root); 
    printf("\nTotal no of nodes in tree are %d", count);
    return 0; 
} 

 
//creating bst by inserting nodes at their right place
struct node *insert(struct node *root, int val)
{
    if(root == NULL)
	  	return newNode(val);
	if(root->data < val)
	    root->right = insert(root->right, val);
	else if(root->data > val)
	    root->left = insert(root->left, val);
	return root;	
}   

 
//maximum heght of the tree
int maxheight(struct node* node)  
{ 
   	if (node==NULL)  
       	return 0; 
   	else 
   	{ 
       	//height of each subtree 
       	int lheight = maxheight(node->left); 
       	int rheight = maxheight(node->right); 
       	//checking which subtree has max height... left or right?
       	if (lheight > rheight)  
           	return(lheight+1); 
       	else return(rheight+1); 
   	} 
}  
  
// creating nodes 
struct node* newNode(int data)  
{ 
    struct node* node = (struct node*) malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    
    return(node); 
} 

static int count = 0;
int countnodes(struct node *root)
{
    if(root != NULL)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}
    


