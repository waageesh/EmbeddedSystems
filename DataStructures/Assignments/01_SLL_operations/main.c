/* 
Title  : Single linked list (insert at first and last, delete at first &last, delete entire list, find given node, print list)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "single_linkedlist.h"

int main()
{
	int menu, data;
	char cont;
	sll* head = malloc(sizeof(sll));		// creating head node and assigning NULL to head
	head = NULL;

	do
	{
		printf("1.Insert_first\n2. Insert_last\n3. Delete_first\n4. Delete_last\n5. Delete list\n6.Find_node\n7. Print_List\n");
		printf("Choose the option :");
		scanf("%d", &menu);

		switch(menu)
		{
			case 1 :							// insert node at first
				{	
					printf("Enter the element :");			// reading data to inserted
					scanf("%d", &data);
					insert_node_first(&head, data);
					break;
				}
			case 2 :							// insert node at last
				{
				    	printf("Enter the element :");			// reading node to be inserted
					scanf("%d", &data);
					if (insert_node_last(&head, data) == e_success )	// if node added successfully
					{
					    printf("%d Added\n", data);
					}
					else						// if adding failed since 

					{
					    printf("%d Adding failed\n", data);
					}
					break;
				}
			case 3 :							// delete node at first of list
				{
					delete_node_first(&head);
					break;
				}
			case 4 :							// delete node at last of list
				{
					delete_node_last(&head);
					break;
				}
			case 5 :							// delete entire list
				{
					delete_list(&head);
					break;
				}
			case 6 :							// find given node in the list
				{
					printf("Enter the element :");
					scanf("%d", &data);
					if ( find_node(&head, data) == DATA_FOUND)	// if node found
					{
					    printf("DATA_FOUND\n");   
					}
					else						// if node not found in list
					{
					    printf("DATA_NOT_FOUND\n");
					}
					break;
				}	
			case 7 :							// print list to check what all elements are there in list
				{
					print_list(&head);
					break;
				}
			
		}
		printf("\nDo you want to continue (yY/nN) :");				// asking user if he want to to continue or not
		scanf(" %c", &cont);
	} while (cont == 'y' | cont == 'Y');						// continue if entered y/Y
	
	return 0;
}
