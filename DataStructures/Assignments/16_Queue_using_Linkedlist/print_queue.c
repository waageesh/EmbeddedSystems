
/*
Title  : queue implementation using linked list.
Author : Vaageesh
Date   : Wednesday 09 December 2020 05:23:51 PM IST
*/
#include "queue.h"

void print_queue(Queue Q)
{
	//take a local reference to traverse through the queue
	SLink *temp = Q.rear;

	//print the values present from front till rear in the queue
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}
