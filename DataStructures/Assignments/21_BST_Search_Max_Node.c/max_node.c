#include "tree.h"

int max_node(tree *root)
{
	if(root == NULL)
		return NO_BST;
	// Traverse from the root till right most node
	tree *temp = root;
	while(temp->RC != NULL)
	{
		temp = temp->RC;
	}
	
	return temp->data;	
}
