/* 
Title  : delete the given data node from the BST
Author : Vaageesh
Date   : Monday 14 December 2020 11:40:49 PM IST
*/

#include "tree.h"

int main()
{
	tree *root = NULL, *temp;
	int choice, status, data, flag = 0;
	char ch;
	
	do{
		printf("\n\nEnter the choice from the below:-\n1. Insert the value in BST\n2. Delete the value\nChoose your option from above : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: printf("\nEnter the value to insert : ");
				scanf("%d", &data);
				status = bst_ins(&root, data);
				if(status == SUCCESS)
				{
					printf("\n%d inserted successfully", data);
				}
				else if(status == DUPLICATE)
				{
					printf("\n%d is already present in the BST, please enter a different value", data);
				}
				else
				printf("\nInsertion failed");
				printf("\nInorder traversal of the BST : ");
				print(root);
				break;
				
			case 2: {
				if(root == NULL)
					printf("\nNo BST created");
				
				printf("\nEnter the value to be deleted : ");
				scanf("%d", &data);
				temp = root;
				while(temp)
				{
					if((temp->data) > data)
						temp = temp->LC;
					else if((temp->data) < data)
						temp = temp->RC;
					else if ((temp->data) == data)
					{
						flag = 1;
						if(((temp->LC) == NULL) && ((temp->RC) == NULL))
						{
							status = del_leaf(root, data);
							if(status == SUCCESS)
								printf("\nLeaf node of %d deleted from the BST successfully", data);
							else
								printf("\nValue not found !");
							printf("\nInorder traversal of the BST : ");
							print(root);
							break;	
						}
						else if((temp->LC == NULL) || (temp->RC == NULL))
						{
							status = del_singlechild(root, data);
							if(status == SUCCESS)
								printf("\nSingle Child node having value %d deleted from the BST successfully", data);
							else
								printf("\nValue not found !");
							printf("\nInorder traversal of the BST : ");
							print(root);
							break;	
						}
						else if (((temp->RC) != NULL) && ((temp->LC) != NULL))
						{
							status = del_two_children(root, data);
							if(status == SUCCESS)
								printf("\nTwo Children node having value %d deleted from the BST successfully", data);
							else
								printf("\nValue not found !");
							printf("\nInorder traversal of the BST : ");
							print(root);
							break;	
						}	
					}		
				}// Since return function could not be called yet, it means data could not be found	
				if(!flag)
				printf("\nValue not found !");
				break;
				
			default : printf("Invalid choice");
				break;		
		}
		}
		
		__fpurge(stdin);
		printf("\nDo you want to continue (yY/nN): ");
		scanf("%c", &ch);
	} while( ch == 'y' || ch == 'Y');
	return 0;
}
