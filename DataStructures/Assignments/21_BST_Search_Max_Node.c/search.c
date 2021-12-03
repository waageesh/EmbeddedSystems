#include "tree.h"

int search(tree *root, int key)
{
	if(root == NULL)
		return FAILURE;
	
	tree *temp = root;
	while(temp)
	{
		if(key < (temp->data))
			temp = temp->LC;
		else if(key > (temp->data))
			temp = temp->RC;
		else
			return SUCCESS;
	}		
		return FAILURE;			
}
