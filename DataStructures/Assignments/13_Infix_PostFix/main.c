#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"


int main(int argc, char* argv[]) 
{
	int menu;
	char cont;
	char* postfix_expr = argv[1];
	int size = strlen(argv[1]);
	char postfix_array[size];
	stack_t* stack = malloc(sizeof(stack_t));
	if (create(stack, size) != e_success)
	{
		printf("creating stack fails\n");
	}

	do
	{
		printf("1. Convert Infix to Postfix Expression\n2. Evalute converted Postfix expression\n");
		printf("Choose option :");
		scanf("%d", &menu);

		switch(menu)
		{
			case 1 :	/* Convert Infix expression to Postfix expression  */
				{
					if (infix_postfix_convertion(postfix_expr, stack, postfix_array) != e_success)
					{
						printf("postfix convertion fails\n");
					}
					else
					{
						int k=0;
						printf("Postfix Array :");
						while(k < size)
						{
							printf("%c", postfix_array[k]);
							k++;
						}
					}
					break;
				}
			case 2 :	/* Evaluate postfix converted expression  */
				{
					int result;
					postfix_evaluation(postfix_array, &result);
					printf("postfix evaluation results : %d\n", result);
				}
		}

		printf("\nDo you want to continue (yY/nN) :");		// asking user to continue or not
		scanf(" %c", &cont);	

	} while (cont == 'Y' || cont == 'y');				// continue if entered y/Y

	return 0;
}
