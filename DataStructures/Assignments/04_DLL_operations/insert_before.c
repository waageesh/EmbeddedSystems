/*
Title  : Double linked list(insert data before data)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "double_linkedlist.h"

status insert_before(dll** head, int data, int after_before_data)
{
	/* if list is empty  */
	if (*head == NULL)
	{
		return EMPTY_LIST;
	}
	else						// if list is non-empty
	{
		/* create ptr , prev_ptr that points to curr node and prev node  */
		dll* ptr = malloc(sizeof(dll));
		dll* prev_ptr = malloc(sizeof(dll));
		
		/* create node to be inserted with given data */
		dll* node = malloc(sizeof(dll));
		node->data = data;

		ptr = *head;			// make ptr points to head
		
		if (ptr->link == NULL)		// if single node exists
		{
			if (ptr->data != after_before_data)
			{
				return e_failure;
			}
			node->link = ptr;
			ptr->prev = node;
			*head = node;
			return e_success;
		}
		else if (ptr->data == after_before_data)	// first node , data matches
		{
			node->link = ptr;     // changing prevptr link to new node
			ptr->prev = node;
			node->prev = NULL;
			*head = node;		
			return e_success;
		}
		
		while(ptr)
		{
			prev_ptr = ptr;			// assigning curr ptr to prev tr
			ptr = ptr->link;		// incrementing ptr to next node
			if (ptr == NULL)
			{
				return DATA_NOT_FOUND;
			}
			if (ptr->data == after_before_data)	// if data matches
			{
				node->link = prev_ptr->link;     // changing prevptr link to new node
				node->prev = prev_ptr;		 // assigning prev ptr of node to prev_ptr
				prev_ptr->link = node;		// making prev_ptr pointing to new node
				return e_success;
			}
		}
		return e_failure;
	}
}

