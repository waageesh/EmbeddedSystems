#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

status postfix_evaluation(char* array, int* result)
{ 
	
	//get postfix array("23*3-84/11+/+") from main
	char* ptr = "23*3-84/11+/+";
	//printf("postfix expr before evaluation : %s\n", ptr	);
	
	/* structure pointer to numbers_stack */
	numbers_stack* num_stack = malloc(sizeof(numbers_stack));
	num_stack->top = -1;
	num_stack->capacity = strlen(array);
	num_stack->item = malloc(sizeof(int) * strlen(array));
	
	// linkedlist for postfix_Array
	//postfix* head = NULL;
	
	
	
	while(*ptr)
	{
		if (isdigit(*ptr))
		{
			push(num_stack, ptr);
		}
		else
		{	
			int operand1, operand2 ;
			char operand;
			
			/* popping 1st element for getting operand 2 */
			pop(num_stack, &operand);
			operand2 = operand - 48;
			
			/* popping 2nd element for getting operand 1 */
			pop(num_stack, &operand);
			operand1 = operand - 48;
			
			/* evaluating based on operator */
			if (*ptr == '+')
			{
				*result = operand1 + operand2 + 48;
				push(num_stack, result);
			}
			else if (*ptr == '-')
			{
				*result = operand1 - operand2 + 48;
				push(num_stack, result);
			}
			else if (*ptr == '/')
			{
				*result = operand1 / operand2 + 48;
				push(num_stack, result);
			}
			else if (*ptr == '*')
			{
				*result = operand1 * operand2 + 48;
				push(num_stack, result);
			}
			else if (*ptr == '%')
			{
				*result = operand1 * operand2 + 48;
				push(num_stack, result);
			}
		}
		ptr++;
	}
	*result = *result - 48;
	free(num_stack);

	return e_success;
}


