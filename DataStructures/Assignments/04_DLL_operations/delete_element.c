/*
Title  : Double linked list(delete element)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "double_linkedlist.h"

status delete_element(dll** head, int data)
{
	if (*head == NULL)		// empty list 
	{
		return EMPTY_LIST;
	}
	else
	{
		dll* ptr;
		dll* prev_ptr;
		dll* temp;
		ptr = prev_ptr = *head;

		if ( ptr->data == data)			  // single node case
		{
			/* data is first element and not a single node*/
			if (ptr->link == NULL)	
			{
				*head = ptr->link;	  // making head pointing to next element
				ptr->link = NULL;
				ptr->prev = NULL;
				free(ptr);	  // freeing the current node
				return e_success;
			}
			else
			{
				temp = ptr;
				ptr = ptr->link;
				*head = ptr;
				free(temp);
				return e_success;
			}

		}

		while(ptr)		// more than one node case
		{
			printf("prev_ptr:%d, ptr :%d\n", prev_ptr->data, ptr->data);
			//ptr = ptr->link;			 // if data doesn't matches, move the pointer to next node
			if (ptr->data == data)
			{
				dll* temp = ptr;  // creating temp ptr to store current node
				
				prev_ptr->link  = ptr->link ;     // connecting prev_ptr to nextnode ptr
				ptr = ptr->link;		  // move ptr to next node
				if (ptr == NULL)
				{
					return e_success;
				}
				ptr->prev = prev_ptr;		  // making prev connection for ptr as prev_ptr
				//temp->link = temp->prev = NULL;
				
				/*dll* temp = ptr;
				*(temp->prev)->link = temp->link;
				*(temp->link)->prev = temp->prev;
				*/
				free(temp);			  // free the isolated node, to delete from LinkedList
				return e_success;
			}
			prev_ptr = ptr;
			ptr = ptr->link;			 // if data doesn't matches, move the pointer to next node
		}
		if (ptr->data == data)		// last node case
		{
			dll* temp = ptr;
			prev_ptr->link = ptr->link;
			free(temp);
			return e_success;
		}

		return DATA_NOT_FOUND;
	}
}
