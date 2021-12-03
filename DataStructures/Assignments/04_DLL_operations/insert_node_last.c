/* 
Title  : Double linked list (insert node at last)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "double_linkedlist.h"

status insert_node_last(dll** head, int data)
{
	/* creating node with data and link as NULL */
	dll* ptr = malloc(sizeof(dll));
	ptr->data = data;
	ptr->link = NULL;
	ptr->prev = NULL;
	
	if (*head == NULL)
	{
		*head = ptr;		// making create node as header
		return e_success;
	}
	else
	{

		/* assigning temp pointer to head for traversal */
		dll* temp = *head;

		/* traversing till last node */
		while(temp->link)
		{
			temp = temp->link;
		}
		temp->link = ptr;  // assigning create node to last node
		ptr->prev = temp;  // assigning prev pointer of new node to temp
		return e_success;
	}
}
