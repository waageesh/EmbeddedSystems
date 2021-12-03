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
		printf("1.Insert_in_sorted_place\n2. FindLoop\n3. Create Loop at kth node\n4. Print list\n");
		printf("Choose the option :");
		scanf("%d", &menu);

		switch(menu)
		{
			case 1 :							// insert node at first
				{	
					printf("Enter the element :");			// reading data to inserted
					scanf("%d", &data);
					insert_sorted(&head, data);
					break;
				}
			case 2 :							// insert node at last
				{
					status loop_exist =  find_loop(&head) ;	// if node added successfully
					if (loop_exist == LOOP_FOUND )
					{
					    printf("Loop exist in List\n");
					}
					else if (loop_exist == EMPTY_LIST)						// if adding failed since 
					{
						printf("List is empty\n");
					}
					else
					{
					    printf("Loop doesn't exist in List\n");
					}
					break;
				}
			case 3:
				{
					int k;
					printf("Enter the k value to create loop from node to kth node : ");		// reading data to inserted
					scanf("%d", &k);
					status loop_status = create_loop(&head, k);
					if (loop_status == EMPTY_LIST)
					{
						printf("Empty list , can't create loop\n");
					}
					else if (loop_status == SINGLE_NODE_LIST)
					{
						printf("Can't create loop for single node\n");
					}
					else
					{
						printf("LOOP created at node %d\n", k);
					}
					break;
				}
			case 4:
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
