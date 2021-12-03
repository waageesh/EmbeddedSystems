#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

status create(stack_t* stack, int size)
{
	/* allocating stack array size  */
	stack->item = (char*)malloc(size);
	stack->top = -1;					// assigning top = -1 to indicate stack is empty
	stack->capacity = size;				// assign capacity with given size
	return  e_success;	
}

status push(stack_t* stack, char* data)
{
	if (stack_isfull(stack)  == e_success )			// if stack is full
	{
		return e_failure;
	}
	else							// if stack not full
	{
		stack->top++;					// increment top
		stack->item[stack->top] = *data;			// assign data in incremented index(top)
		return e_success;
	}
}

status pop(stack_t* stack, char* element)					
{
	if (stack_isempty(stack)  == e_success )			// if stack is empty
	{   
		return e_failure;
	}
	else	
	{
		*element = stack->item[stack->top];		// copy top item on stack, copy that to element
		stack->top--;					// decrement top
		return e_success;
	}

}

status peek(stack_t* stack,int* element)
{
	if (stack_isempty(stack)  == e_success )			// if stack is empty
	{
		printf("Stack is empty\n");
		return e_failure;
	}
	else
	{
		*element = stack->item[stack->top];		// get top item on stack, copy that to element
		return e_success;
	}
}

status peep(stack_t* stack)
{
	if (stack_isempty(stack)  == e_success )			// if stack is empty
	{   
		printf("Stack is empty\n");
		return e_failure;
	}
	else
	{
		int size = stack->top;				
		for(int i=0; i<=size; i++)			// printing all stack elements
		{
			printf("%d ",stack->item[i]);		
		}
		printf("\n");
		return e_success;
	}
}

status free_stack(stack_t* stack)
{
	if (stack->top == -1)					// if stack is empty
	{
		return e_failure;
	}
	else							// makig top = -1, thus making stack empty
	{
		stack->top = -1;
		return  e_success;
	}
}

status stack_isempty(stack_t* stack)
{
	if (stack->top == -1)					// if top=-1, stack is empty
	{
		return e_success;
	}
	else
	{
		return e_failure;
	}
}
status stack_isfull(stack_t* stack)
{
	if (stack->top == (stack->capacity)-1)			// if top=size-1, then stack is full
	{
		return e_success;
	}
	else
	{
		return e_failure;
	}
}
