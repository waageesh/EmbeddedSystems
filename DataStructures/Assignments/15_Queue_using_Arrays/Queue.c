#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

status create(queue_t* Q, int size)
{
	/* allocating Q array size  */
	Q->item = malloc(size);
	Q->front = Q->rear = -1;		// assigning front,rear = -1 to indicate queue is empty
	Q->capacity = size;			// assign capacity with given size
	return  e_true;	
}

status Enqueue(queue_t* Q, int data)
{
	if (Q->rear == Q->capacity-1)			// if Queue is full
	{
		return QUEUE_FULL;
	}
	if (Q->rear == -1)				// if Queue not full
	{
		Q->front++;				// if rear=-1, then make front form -1 to 0
	}
	Q->rear++;					// increment rear to get index
	(Q->item)[Q->rear] = data;			// save element in rear index
	return e_true;
}

status Dequeue(queue_t* Q, int* element)					
{
	printf("rear %d, front %d\n", Q->rear , Q->front);
	if (queue_isempty(Q)  == e_true)			// queue is empty
	{
		Q->front = Q->rear = -1;			// reset front, rear to -1
		return QUEUE_EMPTY;
	}	
	else							// queue not empty
	{
		*element = (Q->item)[Q->front];			// get front element, to send to main
		Q->front++;					// change front to next, to indicate 1 element is deleted
		return e_true;
	}

}

status front(queue_t* Q, int* element)
{
	if (queue_isempty(Q)  == e_true )			// if Queue is empty
	{
		printf("Q is empty\n");
		return e_false;
	}
	else
	{
		*element = (Q->item)[Q->rear];		// get top item on Queue, copy that to element
		return e_true;
	}
}

status print_queue(queue_t* Q)
{
	if (queue_isempty(Q)  == e_true )			// if Queue is empty
	{   
		printf("Q is empty\n");
		return e_false;
	}
	else
	{	
		int size = Q->rear;				
		for(int i=0; i<=size; i++)			// printing all Queue elements
		{
			printf("%d ",Q->item[i]);		
		}
		printf("\n");
		return e_true;
	}
}

status free_queue(queue_t* Q)
{
	
	if (queue_isempty(Q) == e_true)					// if Queue is empty
	{
		return e_false;
	}
	else							// makig top = -1, thus making Queue empty
	{
		Q->front = Q->rear = - 1;
		return  e_true;
	}
}

status queue_isempty(queue_t* Q)
{
	printf("rear %d, front %d\n", Q->rear , Q->front);
	if ( (Q->front == Q->capacity) || Q->front == -1)	// if front = -1, Queue is empty
	{
		return e_true;
	}
	else
	{
		return e_false;
	}
}
status queue_isfull(queue_t* Q)
{
	if (Q->front == (Q->capacity)-1)			// if front = capacity-1, then Queue is full
	{
		return e_true;
	}
	else
	{
		return e_false;
	}
}
