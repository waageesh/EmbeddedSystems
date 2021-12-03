/*
Title  : Single linked list(insert data after nth node)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "single_linkedlist.h"

status find_mid(sll** head, int* element)
{
	int cnt = 0;
	if (*head == NULL)					// empty list
	{
		return EMPTY_LIST;
	}
	else
	{
		sll* ptr_x = malloc(sizeof(sll));
		sll* ptr_2x = malloc(sizeof(sll));
		ptr_x = ptr_2x = *head;				// assigning both x_speed and 2x speed pointers to head

		if (ptr_2x->link == NULL)			// single node list
		{
			*element = ptr_x->data;
			return e_success;
		}
		while(ptr_2x->link)				// more than one node in the list
		{
			ptr_x = ptr_x->link;			// moving ptr_x one step forward
			if (ptr_2x->link != NULL)		// moving ptr_2x one step forward
			{
				ptr_2x = ptr_2x->link;		// moving ptr_2x one more step forward
				if (ptr_2x->link != NULL)		// even no of nodes, 2nd shift of ptr_2x wont become null at end
				{
					ptr_2x = ptr_2x->link;
					if (ptr_2x->link == NULL)  // checking end node or not
					{
						*element = ptr_x->data;
						return e_success;
					}
				}
				else				// if odd no nodes, 2nd shift of ptr_2x will become null at end
				{
					*element = ptr_x->data;
					return e_success;
				}
			}
			else
			{
				*element = ptr_x->data;
				return e_success;
			}
		}

		return e_failure;
	}
}
