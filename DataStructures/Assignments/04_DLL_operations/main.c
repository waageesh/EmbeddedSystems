/*
Title  : Double linked list(insert data before/after given data, delete given data)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/


#include<stdio.h>
#include<stdlib.h>
#include "double_linkedlist.h"

int main()
{
	int menu, data, after_before_data, pos;
	char cont;
	dll* head = malloc(sizeof(dll));
	head = NULL;

	do
	{
		printf("1. Insert_After\n2. Insert_before\n3. Delete_element\n4. insert_node_last\n5. Print_List\n");
		printf("Choose the option :");
		scanf("%d", &menu);

		switch(menu)
		{
			case 1 :	/* insert after given node */	
				{	
					printf("Enter the element to be inserted:");
					scanf("%d", &data);
					printf("Enter after which element to inserted:");
					scanf("%d", &after_before_data);
					status insert_status = insert_after(&head, data, after_before_data) ;
					if ( insert_status == EMPTY_LIST)
					{
						printf("List is empty\n");
					}
					else if ( insert_status == DATA_NOT_FOUND)
					{
						printf("element %d not found in the list\n", data);
					}
					break;
				}
			case 2 :	/* insert before given node */
				{
				        printf("Enter the element to be inserted :");
					scanf("%d", &data);
					printf("Enter before which element to inserted:");
					scanf("%d", &after_before_data);
					if (insert_before(&head, data, after_before_data) != e_success )
					{
					    printf("Element %d not found in List\n", data);
					}
					break;
				}
			case 3 :	/* delete given node */
				{
					printf("Enter the element :");
                                        scanf("%d", &data);
					status delete_status = delete_element(&head, data) ;
					if (delete_status == DATA_NOT_FOUND)
					{
						printf("Data not found");
					}
					else if (delete_status == EMPTY_LIST)
					{
						printf("List is empty");
					}
					break;
				}
			case 4 :	/* insert node at last of list  */
				{
					printf("Enter the element :");
					scanf("%d", &data);
					insert_node_last(&head, data);
					//break;
				}	
			case 5 :	/* print the list  */
				{
					print_list(&head);
				}
		}
		printf("\nDo you want to continue (yY/nN) :");		// asking user to continue or not
		scanf(" %c", &cont);

	} while (cont == 'y' | cont == 'Y');				// continue if entered y/Y
	
	return 0;
}
