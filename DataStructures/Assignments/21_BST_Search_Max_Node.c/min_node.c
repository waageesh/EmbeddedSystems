#include "tree.h"

int min_node(tree *root)
{
	if(root == NULL)
		return NO_BST;
	// Traverse from the root till left most node
	tree *temp = root;
	while(temp->LC != NULL)
	{
		temp = temp->LC;
	}
	
	return temp->data;
}
