#include "tree.h"

void print(tree *root)
{
	//print data while inorder Traversing
	if(root)
	{
		//move to left sub tree
		print(root->LC);
		printf("%d ", root->data);
		//move to right sub tree
		print(root->RC);
	}
}

