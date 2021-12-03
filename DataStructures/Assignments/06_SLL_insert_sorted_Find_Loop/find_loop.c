/*
Title  : Single linked list( insert node at first)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/


#include <stdlib.h>
#include <stdio.h>
#include "single_linkedlist.h"

status find_loop(sll** head)
{
    sll* ptr1;
    sll* ptr2;				// initialize ptr1,ptr2 to head
    ptr1  = ptr2 = *head;
    if (*head == NULL)				// empty list case
    {
        return EMPTY_LIST;				// making given node as head
    }
    else					// if elements exist, update head pointer with new created node and node pointer with head pointer
    {
    	if ((*head)->link == NULL)			// single node case
    	{
    		return LOOP_NOT_FOUND;
    	}
    	while(ptr2 != NULL || ptr2->link != NULL)
    	{
        	if (ptr1 == ptr2 && ptr1 != *head)
        	{
        		return LOOP_FOUND;
        	}
        	ptr1 = ptr1->link;		// making ptr1 x speed
    		ptr2 = ptr2->link;
		if (ptr2 == NULL)		// even no of nodes case
		{
			printf("ptr2 is NULL\n");
			break;
		}
		else				// odd no of nodes case
		{
			printf("ptr2 : %d\n", ptr2->data);
			ptr2 = ptr2->link;		// moving ptr2 2x speed
		}
    	}
    	return LOOP_NOT_FOUND;
    }
}
