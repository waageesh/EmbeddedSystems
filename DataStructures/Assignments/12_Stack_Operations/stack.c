#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

status push(stack_t** top, int data, int* cnt, int size)
{
	if ( *cnt == size )			// if stack is full
	{
		return e_false;
	}
	else							// if stack not full
	{
		stack_t* node = malloc(sizeof(stack_t));
		node->data = data;                      // assign data in incremented index(top)
		node->link = *top;
		*top = node;
		(*cnt)++;
		return e_true;
	}
}

status pop(stack_t** top, int* element)					
{
	if (*top == NULL)			// if stack is empty
	{   
		return e_false;
	}
	else	
	{
		stack_t* temp = *top;
		*element = temp->data;		// copy top item on stack to element
		*top = temp->link;         // making head pointing to next node
		free(temp)  ;                // pops or deletes first or top node
		return e_true;
	}

}

status peek(stack_t** top, int* element)
{
	if (*top == NULL)			// if stack is empty
	{
		return e_false;
	}
	else
	{
		stack_t* temp = *top;
		*element = temp->data;		// copy top item on stack to element
		return e_true;
	}
}

status peep(stack_t** top)
{
	if (*top == NULL)			// if stack is empty
	{   
		return e_false;
	}
	else
	{
		stack_t* temp = *top;			
		while(temp)
		{
		    printf("%d ", temp->data);
		    temp = temp->link;
		}
		printf("\n");
		return e_true;
	}
}

status free_stack(stack_t** top)
{
	if (*top == NULL)					// if stack is empty
	{
		return e_false;
	}
	else							// makig top = -1, thus making stack empty
	{
	    stack_t* temp = malloc(sizeof(stack_t));
	    stack_t* ptr = malloc(sizeof(stack_t));
	    ptr = *top;
		while(*top)
		{
		    temp = *top;
		    *top = (*top)->link;
		    free(temp);
		}
		return  e_true;
	}
}

