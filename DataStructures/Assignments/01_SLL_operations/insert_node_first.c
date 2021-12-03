/*
Title  : Single linked list( insert node at first)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/


#include <stdlib.h>
#include <stdio.h>
#include "single_linkedlist.h"

status insert_node_first(sll** head, int data)
{
    sll* ptr = malloc(sizeof(sll));		// create node with given data and assinging link with NULL
    ptr->link = NULL;
    ptr->data = data;
    if (*head == NULL)				// empty list case
    {
        *head = ptr;				// making given node as head
    }
    else					// if elements exist, update head pointer with new created node and node pointer with head pointer
    {
        ptr->link = *head;  			// making ptr link pointing to head node
        *head = ptr;				// making ptr as head nod
    }
}
