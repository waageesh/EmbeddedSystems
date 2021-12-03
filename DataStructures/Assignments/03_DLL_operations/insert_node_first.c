/*
Title  : Single linked list( insert node at first)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/


#include <stdlib.h>
#include <stdio.h>
#include "double_linkedlist.h"

status insert_node_first(dll** head, dll** tail, int data)
{
    dll* ptr = malloc(sizeof(dll));		// create node with given data and assinging link with NULL
    dll* temp = *head;
    ptr->link = NULL;
    ptr->prev = NULL;
    ptr->data = data;
    if (*head == NULL && *tail == NULL)				// empty list case
    {
        *head = *tail = ptr;				// making given node as head
    }
    else					// if elements exist, update head pointer with new created node and node pointer with head pointer
    {
        ptr->link = *head;  			// making ptr link pointing to head node
        temp->prev = ptr;
	*head = ptr;				// making ptr as head node
    	return e_success;
    }
}
