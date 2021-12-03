#include<stdio.h>
#include<stdlib.h>
#include "single_linkedlist.h"

int main()
{
	int menu, data, after_before_data, pos;
	char cont;
	sll* head = malloc(sizeof(sll));
	head = NULL;

	do
	{
		printf("1. Insert_After\n2. Insert_before\n3. Delete_element\n4. Insert_nth\n5. insert_node_last\n6. Print_List\n");
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
					if ( insert_after(&head, data, after_before_data) != e_success)
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
					if (delete_element(&head, data) != e_success)
					{
						printf("List is empty");
					}
					break;
				}
			case 4 :	/* insert node at nth position in list  */
				{
					printf("Enter the element :");
                                        scanf("%d", &data);
					printf("Enter the nth pos element to be inserted:");
                                        scanf("%d", &pos);
					insert_nth(&head, data, pos);
					break;
				}
			case 5 :	/* insert node at last of list  */
				{
					printf("Enter the element :");
					scanf("%d", &data);
					insert_node_last(&head, data);
					//break;
				}	
			case 6 :	/* print the list  */
				{
					print_list(&head);
				}
		}
		printf("\nDo you want to continue (yY/nN) :");		// asking user to continue or not
		scanf(" %c", &cont);

	} while (cont == 'y' | cont == 'Y');				// continue if entered y/Y
	
	return 0;
}
