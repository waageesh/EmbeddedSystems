#include "tree.h"

int del_two_children(tree *root, int key)
{
	// Traversing till NULL
	tree *parent, *temp1, *temp = root;
	while(temp != NULL)
	{
		// Checking if key is lesser, greater or equal to temp ptr data and updating temp accordingly
		if((temp->data) == key)
		{
			// If equal then finding out the lowest value in the RSA (right sub array)
			// Here the first value of RSA will be the smallest value if there is no LSA attached to it, else last value of associated LSA willl be the smallest
			temp1 = temp->RC;
			parent = temp1;
			while((temp1->LC) != NULL)
			{
				parent = temp1;
				temp1 = temp1->LC;
			}break;
		}
		else if((temp->data) > key)
			temp = temp->LC;
		else if((temp->data) < key)
			temp = temp->RC;
	}
		if((temp->data) == key)
		{
			// Updating the value to be deleted with the lowest found value
			temp->data = temp1->data;
			// Breaking the link with that lowest value and updating its links
			if((temp1->RC) != NULL)
				parent->LC = temp1->RC;
			else
				parent->LC = NULL;
			free(temp1);
			return SUCCESS;	
		}
		return DATA_NOT_FOUND;
}

