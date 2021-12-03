/*
Title  : Single linked list( Delete entire linkedlist)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include <stdio.h>
#include <stdlib.h>
#include "single_linkedlist.h"

status remove_duplicates(sll** head)
{
	if (*head == NULL)   // List is empty
	{
		return EMPTY_LIST;
	}
	else
	{
		sll *ptr1,*ptr2,*ptr3,*prev;
		ptr1 = ptr2 = *head ;
		while(ptr1 != NULL)
		{
			if (ptr2 == NULL)	// prev should start from ptr1, when ptr2 reaches end of the list
			{
				prev = ptr1;
			}
			else			// prev should follow ptr2, when ptr2 is not null
			{
				prev = ptr2;
			}
			ptr2 = ptr1->link;
			while (ptr2 != NULL)
			{	
				if (ptr1->data == ptr2->data)
				{
					sll* temp = ptr2;           // assign ptr2 node to temp
					prev->link = ptr2->link; 	    // change link of ptr1 to next node
					ptr2 = ptr2->link;	    // move ptr2 to next node
					temp->link = NULL;
					free(temp);                 // delete the temp node
				}
				else
				{
					prev = ptr2;
					ptr2 = ptr2->link;	// move ptr2 to next node, without deleting curr node
				}
			}
			ptr1 = ptr1->link;			// move ptr1 to next node
		}
		return e_success;
	}
}
