#include<stdio.h>
#include<stdlib.h>
#include "single_linkedlist.h"

int main()
{
	int menu, pos, element=0, data;
	char cont;
	sll* head = malloc(sizeof(sll));
	head = NULL;

	do
	{
		printf("1. Find_Mid\n2. Get_nth_last\n3. Insert_node_last\n4. Print_list\n");
		printf("Choose the option :");
		scanf("%d", &menu);

		switch(menu)
		{
			case 1 :	/* finding mid node of list  */
				{	
					if ( find_mid(&head, &element) == e_success)
					{
						printf("mid element in the list : %d\n", element);
					}
					break;
				}	
			case 2 :	/* getting nth last node from list */
				{
					printf("Enter the nth last pos :");
                                        scanf("%d", &pos);
					if ( get_nth_last_node(&head, &element, pos) != e_success )
					{
					    printf("Element %d not found in List\n", element);
					}
					else
					{
					    printf("nth last Element in List : %d\n", element);
					}
					break;
				}
			case 3 :	/* inserting node at last of list  */
				{
					printf("Enter the element :");
					scanf("%d", &data);
					insert_node_last(&head, data);
					break;
				}	
			case 4 :	/* priting list  */
				{
					print_list(&head);
				}
		}
		printf("\nDo you want to continue (yY/nN) :");		// asking user to continue or not
		scanf(" %c", &cont);	
	} while (cont == 'y' | cont == 'Y');				// continue if entered y/Y
	
	return 0;
}
