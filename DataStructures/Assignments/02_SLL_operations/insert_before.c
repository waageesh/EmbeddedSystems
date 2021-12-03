/*
Title  : Single linked list(insert data before data)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "single_linkedlist.h"

status insert_before(sll** head, int data, int after_before_data)
{
	/* if list is empty  */
	if (*head == NULL)
	{
		return EMPTY_LIST;
	}
	else						// if list is non-empty
	{
		/* create ptr , prev_ptr that points to curr node and prev node  */
		sll* ptr ;
		sll* prev_ptr;
		
		/* create node to be inserted with given data */
		sll* node = malloc(sizeof(sll));
		node->data = data;

		ptr = *head;			// make ptr points to head
		
		if (ptr->link == NULL)		// if single node exists
		{
			node->link = ptr;
			*head = node;
			return e_success;
		}
		else if (ptr->data == after_before_data)
		{
			node->link = ptr->link;     // changing prevptr link to new node
			ptr->link = node;		
			return e_success;
		}
		while(ptr)
		{
			prev_ptr = ptr;			// assigning curr ptr to prev tr
			ptr = ptr->link;		// incrementing ptr to next node
			if (ptr->data == after_before_data)	// if data matches
			{
				node->link = prev_ptr->link;     // changing prevptr link to new node
				prev_ptr->link = node;		
				return e_success;
			}
			//ptr = ptr->link;		// incrementing ptr to next node
		}

		return e_failure;
	}
}

