/* 
Title  : Single linked list (insert at first and last, delete at first &last, delete entire list, find given node, print list)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "double_linkedlist.h"

int main()
{
	int menu, data;
	char cont;
	dll* head = malloc(sizeof(dll));		// creating head node and assigning NULL to head
	dll* tail = malloc(sizeof(dll));
	head = tail = NULL;

	do
	{
		printf("1.Insert_first\n2. Insert_last\n3. Delete_first\n4. Delete_last\n5. Delete list\n6. Print_List\n");
		printf("Choose the option :");
		scanf("%d", &menu);

		switch(menu)
		{
			case 1 :							// insert node at first
				{	
					printf("Enter the element :");			// reading data to inserted
					scanf("%d", &data);
					insert_node_first(&head, &tail, data);
					break;
				}
			case 2 :							// insert node at last
				{
				    	printf("Enter the element :");			// reading node to be inserted
					scanf("%d", &data);
					if (insert_node_last(&head, &tail, data) == e_success )	// if node added successfully
					{
					    printf("%d Added\n", data);
					}
					break;
				}
			case 3 :							// delete node at first of list
				{
					if ( delete_node_first(&head, &tail) != e_success)
					{
						printf("List is empty, can't delete from empty list\n");
					}
					break;
				}
			case 4 :							// delete node at last of list
				{
					if (delete_node_last(&head, &tail) != e_success )
					{
						printf("List is empty, can't delete from empty list\n");
					}
					break;
				}
			case 5 :							// delete entire list
				{
					if (delete_list(&head, &tail) != e_success)
					{
						printf("List is empty, can't delete from empty list\n");
					}
					break;
				}
			case 6 :							// print list to check what all elements are there in list
				{
					if (print_list(&head) != e_success )
					{
						printf("List is Empty\n");
					}
					break;
				}
			
		}
		printf("\nDo you want to continue (yY/nN) :");				// asking user if he want to to continue or not
		scanf(" %c", &cont);
	} while (cont == 'y' | cont == 'Y');						// continue if entered y/Y
	
	return 0;
}
