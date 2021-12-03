/*
Title  : Single_linked_list remove duplicates
Author : Vaageesh
Date   : Friday 04 December 2020 01:43:49 AM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "single_linkedlist.h"

int main()
{
	int menu, data;
	char cont;
	sll* head = malloc(sizeof(sll));
	head = NULL;

	do
	{
		printf("1. Insert_node_last\n2. Reverse_linkedlist\n");
		printf("Choose the option :");
		scanf("%d", &menu);

		switch(menu)
		{

			case 1 :	/* insert node at last of list  */
				{
					printf("Enter the element :");
					scanf("%d", &data);
					insert_node_last(&head, data);
					break;
				}	
			case 2 :	/* remove duplicates from list */
				{
					int option;
					printf("1. Reverse list using iterative\n2. Reverse list using recursive\nChoose option :");
					scanf("%d", &option);
					if (option == 1)
					{
						if (reverse_list_iterative(&head) != e_success)
						{
							printf("List is empty");
						}
					}
					else
					{
						//sll* prev = head;
						sll* new_head = head; 
						head = reverse_list_recursive(&head);
					}				
					break;
				}
		}
		print_list(&head);
		printf("\nDo you want to continue (yY/nN) :");		// asking user to continue or not
		scanf(" %c", &cont);

	} while (cont == 'y' | cont == 'Y');				// continue if entered y/Y

	return 0;
}
