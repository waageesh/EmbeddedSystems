/* 
Title  : Single linked list (insert sorted, find loop)
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
		printf("1. Insert at last\n2. Sort the List\n");
		printf("Choose the option :");
		scanf("%d", &menu);

		switch(menu)
		{
			case 1 :							// insert node at first
				{	
					printf("Enter the element :");			// reading data to inserted
					scanf("%d", &data);
					insert_node_last(&head, data);
					break;
				}
			case 2 :							// insert node at last
				{
					if (sort_list_nodes(&head) != e_success )	// if sorting done successfully
					{
					    printf("sorting not possible for empty list\n");
					}
					
					break;
				}
			
		}
		print_list(&head);
		printf("\nDo you want to continue (yY/nN) :");				// asking user if he want to to continue or not
		scanf(" %c", &cont);
	} while (cont == 'y' | cont == 'Y');						// continue if entered y/Y
	
	return 0;
}
