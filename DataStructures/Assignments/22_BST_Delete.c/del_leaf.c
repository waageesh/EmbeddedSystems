#include "tree.h"

int del_leaf(tree *root, int key)
{
	// flag to signify if key bigger or lesser than parent node
	int flag;
	// Traversing till NULL encountered, parent keepig track of previous node
	tree *parent, *temp = root;
	while(temp != NULL)
	{
		// Break the loop if key found, else update the temp ptr and flag accoringly and traverse further
		if(temp->data == key)
		{
			break;
		}	
		else if((temp->data) < key)
		{
			parent = temp;
			temp = temp->RC;
			flag = 1;
		}
		else
		{
			parent = temp;
			temp =  temp ->LC;
			flag = 0;
		}
	}
	if(flag)
		parent->RC = NULL;
	else
		parent->LC = NULL;
	return SUCCESS;
}
