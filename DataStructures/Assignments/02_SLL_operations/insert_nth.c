/*
Title  : Single linked list(insert data after nth node)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "single_linkedlist.h"

status insert_nth(sll** head, int data, int pos)
{
	int cnt = 0;
	if (*head == NULL)		// if list is empty
	{
		return EMPTY_LIST;
	}
	else				// if list is non-empty
	{
		sll* ptr = *head;			// creating ptr that points to head
		while(ptr)
		{
			cnt++;					// cnt for every node visit, to reach nth pos
			if (cnt == pos)				// if cnt reaches required position
			{
				insert_before(head, data, ptr->data);	// insert data before this node
				return e_success;
			}
			else
			{
				ptr = ptr->link;		// if cnt doesn't reach pos, increment ptr to next node
			}
		}

		return e_failure;
	}
}
