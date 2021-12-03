/* 
Title  : Single linked list (insert node at last)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "single_linkedlist.h"

status insert_node_last(sll** head, int data)
{
	if (*head == NULL)
	{
	    /* creating node with data and link as NULL */
		sll* ptr = malloc(sizeof(sll));
		ptr->data = data;
		ptr->link = NULL;

		*head = ptr;
		return e_success;

	}
	else
	{
		/* creating node with data and link as NULL */
		sll* ptr = malloc(sizeof(sll));
		ptr->data = data;
		ptr->link = NULL;

		/* assigning temp pointer to head for traversal */
		sll* temp = malloc(sizeof(sll));
		temp = *head;

		/* traversing till last node */
		while(temp->link)
		{
			temp = temp->link;
		}
		temp->link = ptr;  // assigning create node to last node
		return e_success;
	}
}
