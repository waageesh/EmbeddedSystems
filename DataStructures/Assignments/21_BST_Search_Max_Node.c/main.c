/* 
Title  : WAF to search given data, find max and min data node from the BST
Author : Vaageesh
Date   : Monday 20 December 2020 11:40:49 PM IST
*/

#include "tree.h"

int main()
{
	tree *root = NULL;
	int choice, data, status, key;
	char option, ch;
	
	do
	{

		printf("\n\nSelect from the below the options:-\n");
		printf("1. Insert an element\n2. Search if your element is present\n3. Find Maximum element\n4. Find Minimum element\n5. Print the BST");

		printf("\n\nMy Choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: printf("\nEnter the value to insert : ");
				scanf("%d", &data);
				status = bst_ins(&root, data);
				if(status == SUCCESS)
				{
					printf("\n%d inserted successfully\n", data);
				}
				else if(status == DUPLICATE)
				{
					printf("\n%d is already present in the BST, please enter a different value\n", data);
				}
				else
				printf("\nInsertion failed");
				break;
			case 2:
				printf("\nEnter the element you want to search : ");
				scanf("%d", &data);
				status = search(root, data);
				(status == SUCCESS) ? printf("%d is present in the BST\n", data): printf("%d is NOT present in the BST\n", data) ;
				break;
			
			case 3: status = max_node(root);
				(status == NO_BST)? printf("\nBST is empty\n"): printf("\nMax value found is : %d\n", status) ;
				break;
			
			case 4: status = min_node(root);
				(status == NO_BST)? printf("\nBST is empty\n"): printf("\nMin value found is : %d\n", status) ;
				break;
			
			case 5: print(root);
				break;
				
			default:
				printf("Invalid option\n");
				break;
		}

		__fpurge(stdin);
		printf("\nDo you want to continue (y/Y||n/N):");
      	scanf("%c", &ch);
   	} while(ch == 'y' || ch == 'Y');
 	return 0;
}
