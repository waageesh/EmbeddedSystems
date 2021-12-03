#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main() 
{
	int size, data, cnt=0;
	int element;
	int menu;
	char cont;
	printf("Enter the size of array :");
	scanf("%d", &size);
	stack_t* top = NULL;

	do
	{
		printf("1. Push\n2. Pop\n3. peek\n4. Peep\n5. free_stack\n");
		printf("Choose option :");
		scanf("%d", &menu);

		switch(menu)
		{
			case 1 :	/* push elements to stack  */
				{
					printf("Enter the element to be pushed :");
					scanf("%d", &data);
					if (push(&top, data, &cnt, size) != e_true)
					{
						printf("stack is already full, push not possible\n");
					}
					break;
				}
			case 2 :	/* print top most element on stack  */
				{
					if (pop(&top, &element) != e_true)
					{
						printf("pop not possible for empty stack\n");
					}
					else
					{
						printf("popped element is %d\n", element);
					}
					break;
				}
			case 3 :	/* print top most element on stack  */
				{
					if (peek(&top, &element) == e_true)
					{
						printf("peek : %d\n", element);
					}
					else
					{
						printf("stack is empty, no peek element\n");
					}

					break;
				}
			case 4 :	/* print elements from stack  */
				{
					if (peep(&top) != e_true)
					{
						printf("stack is empty, no elements to print\n");
					}
					break;
				}
			case 5 :	/* free elements from stack  */
				{
					if (free_stack(&top) != e_true)
					{
						printf("stack is already empty\n");
					}
					break;
				}
		}

		printf("Do you want to continue (yY/nN) :");		// asking user to continue or not
		scanf(" %c", &cont);	

	} while (cont == 'Y' || cont == 'y');				// continue if entered y/Y

	return 0;
}

