/* 
Title  : Single linked list (insert node at last)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "double_linkedlist.h"

status insert_node_last(dll** head, dll** tail, int data)
{
	if (*head == NULL && *tail == NULL)
	{
	    /* creating node with data and link as NULL */
		dll* ptr = malloc(sizeof(dll));
		ptr->data = data;
		ptr->link = NULL;
		*head = ptr;
		return e_success;

	}
	else
	{
		/* creating node with data and link as NULL */
		dll* ptr = malloc(sizeof(dll));
		ptr->data = data;

		/* assigning temp pointer to head for traversal */
		dll* temp = malloc(sizeof(dll));
		temp = *head;
		
		/* singl node condition  */
		if (*head == *tail)
		{
			(*head)->link = ptr;
			ptr->prev = *head;
			ptr->link = NULL;
			*tail = ptr;
			return e_success;
		}
		/* traversing till last node */
		while(temp->link)
		{
			temp = temp->link;
		}
		temp->link = ptr;  // assigning create node to last node
		ptr->prev = temp;  // assigning prev pointer to temp
		ptr->link = NULL;  // making next pointer of ptr as NULL
		*tail = ptr;	  // assinging last node to tail
	
		return e_success;
	}
}
