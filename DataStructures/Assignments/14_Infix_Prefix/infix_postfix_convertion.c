#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "stack.h"

status infix_postfix_convertion(char* expr, stack_t* stack, char postfix_array[])
{
	//printf("expr : %s\n", expr);
	char* temp = expr;
	char element;
	int index = strlen(postfix_array);
	while(*temp)
	{
		
		if (isdigit(*temp))
		{
			//printf("digit : %c\n", *temp);
			index++;
			postfix_array[index] = *temp;	// append scanned item to postfix_array
			temp++;
		}
		else
		{	
			//printf("char : %c\n", *temp);
			int char_prec = char_precedence(temp, &stack->item[stack->top]) ;
			if ( *temp == '(' )
			{
				push(stack, temp);
				temp++;
			}
			else if ( *temp == ')' )
			{
				/* postfix_array = pop all items till '(' */
				while(stack->top != -1 )
				{
					/* return popped item into "element" */
					pop(stack, &element);
					if (element != '(')
					{
						//printf("char %c\n", element);
						index++;
						postfix_array[index] = element;		// append popped item from stack to postfix_array
					}
				}
				/* discard '(' , ')' characters from stack*/
				//pop(stack, &element);
				temp++;
			}
			else if (*temp == '\0') 
			{	
				/* empty stack and discard '(' , ')' */
				while(stack->top != -1)
				{
					/* return popped item into "element" */
					pop(stack, &element);
					if (element != '(' && element != ')')
					{
						index++;
						postfix_array[index] = element;		// append popped item from stack to postfix_array
					}				
				}
				return e_success;
			}
			else if (stack->top == -1)		// check stack is empty
			{
				push(stack, temp);			// push scanned item onto stack, if its empty
				temp++;
			}
			else if (char_prec == -1 ||  char_prec == 0)	// if top item on stack has higher precedence than scanned item 
			{
				if (stack->item[stack->top] == '(')
				{
					push(stack, temp);
					temp++;
				}
				else
				{
					//printf("precedence : %d\n", char_prec);
					/* return popped item into "element" */
					pop(stack, &element);
					index++;
					postfix_array[index] = element;		// append popped item from stack to postfix_array
					push(stack, temp);			// push scanned item to stack
					temp++;
				}
			}
			else					// scanned item has more precedence than top item on stack
			{
				push(stack, temp);			// push scanned item onto stack
				temp++;
			}	
		}
		
		/*
		printf("postfix array :");
		for(int i=0;i<=index;i++)
		{
			printf("%c", postfix_array[i]);
		}
		printf("\nStack         :");
		for(int i=0;i<=stack->top;i++)
		{
			printf("%c", stack->item[i]);
		}
		printf("\n");
		*/
		
	}
	index++;
	postfix_array[index] = '\0';
	return e_success;
}




