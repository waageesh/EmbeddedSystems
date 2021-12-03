/*
Title  : Single linked list(delete element)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "single_linkedlist.h"

status delete_element(sll** head, int data)
{
	if (*head == NULL)		// empty list 
	{
		return EMPTY_LIST;
	}
	else
	{
		sll* ptr ;
		sll* prev_ptr ;
		ptr = *head;
		
		printf("first element : %d\n", ptr->data);
		/* data is first element */
		if (ptr->data == data)	
		{
			*head = ptr->link;	  // making head pointing to next element
			ptr->link = NULL;
			free(ptr);	  // freeing the current node
			return e_success;
		}

		while(ptr)		// data is not first element
		{
			prev_ptr = ptr;
			ptr = ptr->link;			 // if data doesn't matches, move the pointer to next node
			if (ptr->data == data)
			{
				sll* temp = malloc(sizeof(sll));  // creating temp ptr to store current node
				temp = ptr;
				
				prev_ptr->link  = ptr->link ;     // connecting prev_ptr to nextnode ptr
				ptr->link = NULL;		  // making current node pointer as NULL to isolate it from Linkedlist

				free(temp);			  // free the isolated node, to delete from LinkedList
				return e_success;
			}
		}

		return e_failure;
	}
}
