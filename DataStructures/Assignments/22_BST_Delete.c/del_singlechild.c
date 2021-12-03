#include "tree.h"

int del_singlechild(tree *root, int key)
{
	// Traversing from root to NULL
	tree *temp = root;
	while(temp != NULL)
	{
		// If key found then check if its child a RC or a LC
		if(temp->data == key)
		{
			// If its a RC, update the current ptr with its childs value, free the child ptr and update curr temp RC with NULL
			if(temp->RC != NULL)
			{
				temp->data = temp->RC->data;
				tree *temp1 = temp->RC;
				free(temp1);
				temp->RC = NULL;
				return SUCCESS;
			}
			else
			{
				// If its a LC, update the current ptr with its childs value, free the child ptr and update curr temp LC with NULL
				temp->data = temp->LC->data;
				tree *temp1 = temp->LC;
				free(temp1);
				temp->LC = NULL;
				return SUCCESS;
			}
		}
		// If not equal and key smaller then traverse towards LSA else towards RSA
		else if((temp->data) > key)
			temp = temp->LC;
		else
			temp = temp->RC;	
	}
	// If not returned so far then key doesnt seem to be existing in the BST
	//return DATA_NOT_FOUND;
}
