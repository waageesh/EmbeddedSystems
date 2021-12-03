/* 
Title  : Single linked list (merge the 2 linkedlist in sorted manner)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "single_linkedlist.h"

int main()
{
	int menu, data, list_no;
	int merge_flag;
	char cont;
	sll* head1 = NULL;		// creating head1 node for LIST1 and assigning NULL to head1
	sll* head2 = NULL;		// creating head2 node for LIST1 and assigning NULL to head2
	do
	{
		printf("1. Insert at last\n2. Sort the List\n3. Merge the 2 linkedlists sorted\n");
		printf("Choose the option :");
		scanf("%d", &menu);

		switch(menu)
		{
			case 1 :							// insert node at first
				{	
					printf("1. LIST1\n2. LIST2\n");		// reading data to inserted
					printf("Choose to which LIST element should be added : ");
					scanf("%d", &list_no);
					printf("Enter the element :");			// reading data to inserted
					scanf("%d", &data);
					
					if (list_no == 1)
					{	
						insert_node_last(&head1, data);
					}
					else
					{
						insert_node_last(&head2, data);
					}
					break;
				}
			case 2 :							// insert node at last
				{
					printf("1. LIST1\n2. LIST2\n");		// reading data to inserted
					printf("Choose option, which LIST should be sorted : ");
					scanf("%d", &list_no);
					
					if (list_no == 1)
					{	
						if (sort_list_nodes(&head1) != e_success )	// if LIST_1 sorting done successfully
						{
						    printf("sorting not possible for empty list\n");
						}
					}
					else
					{
						if (sort_list_nodes(&head2) != e_success )	// if LIST_2 sorting done successfully
						{
						    printf("sorting not possible for empty list\n");
						}
					}
					break;
				}
			case 3 :
				{
					if (merge_list_sorted(&head1, &head2) == e_success)
					{
						printf("\nMerged Linkedlist :\n");
						printf("\n---------------------------\n");
						print_list(&head1);
						printf("\n---------------------------\n");
						merge_flag = 1;
					}
					break;
				}
			
		}
		if (merge_flag != 1)
		{
			printf("-------- LIST_1 --------\n");
			print_list(&head1);
			printf("\n-------- LIST_2 --------\n");
			print_list(&head2);
		}
		
		printf("\nDo you want to continue (yY/nN) :");				// asking user if he want to to continue or not
		scanf(" %c", &cont);
	} while (cont == 'y' | cont == 'Y');						// continue if entered y/Y
	
	return 0;
}
