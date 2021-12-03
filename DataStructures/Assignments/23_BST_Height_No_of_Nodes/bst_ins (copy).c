#include "tree.h"

int bst_ins(tree **root, int key)
{
	// Flag to signify if the node is greater or lesser than its parent node
		int flag;
		tree *parent, *temp;
	// Creating a node of the key value passed, doing error check and updating the node
	tree *new = malloc(sizeof(tree));
	if(new == NULL)
	return FAILURE;
	
	new->LC = NULL;
	new->data = key;
	new->RC = NULL;
	
	// Checking if root is null, if so then make the key value as the new root.
	if(*root == NULL)
	{
		*root = new;
		return SUCCESS;
	}
	else	// If multiple nodes present
	{
		// Traversing till NULL encountered
		temp = *root;
		while(temp != NULL)
		{
			// Keeping track of the parent node, traverse in LSA if key < parent and towards RSA if key > parent
			parent = temp;
			if(key < (temp->data))
			{
				temp = temp->LC;
				flag = 1;
			}
			else if(key > (temp->data))
			{
				temp = temp->RC;
				flag = 0;
			}
			else // If value is equal to its parent node then return DUPLICATE
			return DUPLICATE;
		}
	}
	// Updating parent node according to the flag value
	if(flag == 1)
		parent->LC = new;
	else
		parent->RC = new;
	return SUCCESS;	
	
}
