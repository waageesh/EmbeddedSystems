/*
Title  : Single linked list( reverse list iterative method)
Author : Vaageesh
Date   : Tuesday 05 December 2020 11:55:02 AM IST
*/

#include <stdio.h>
#include <stdlib.h>
#include "single_linkedlist.h"

status reverse_list_iterative(sll** head)
{
	if (*head == NULL)   // List is empty
	{
		return EMPTY_LIST;
	}
	else
	{
		sll *prev, *curr, *next;
		curr = *head;
		prev = next = NULL ;
		while(curr != NULL)			// loop till reaches last
		{
			/* before reversing the link, move next to 1 pos */
			next = curr->link;
			/* this is where reversing the link happens  */
			curr->link = prev;
			/* move prev, curr to next pos  */
			prev = curr;
			curr = next;
		}
		*head = prev;  // making prev as head, since curr becomes null and prev becomes last node
		return e_success;
	}
}
