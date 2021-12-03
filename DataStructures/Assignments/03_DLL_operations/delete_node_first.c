/*
Title  : Single linked list( delete node at first)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "double_linkedlist.h"


status delete_node_first(dll** head, dll** tail)
{
    if (*head == NULL && *tail == NULL)   // List is empty
    {
        return EMPTY_LIST;
    }
    else
    {
        dll* temp = *head;       		 // assign head(first) node to temp
        /* single node condition  */
	if (*head == *tail)
	{
		*head = *tail = NULL;
		temp->link = temp->prev = NULL;
		free(temp);
	}
	*head = (*head)->link;    		 // moving head node to next node
        (*head)->prev == NULL;			 // making head node prev pointer as NULL
	temp->link = temp->prev = NULL ;	 // assign next and prev pointers to NULL
	free(temp);              		 // delete the first node i.e, temp node
        return e_success;
    }
}
