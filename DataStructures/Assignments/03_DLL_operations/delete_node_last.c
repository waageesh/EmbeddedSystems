/*
Title  : Single linked list( delete node at last)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "double_linkedlist.h"


status delete_node_last(dll** head, dll** tail)
{
    if (*head == NULL && *tail == NULL)   // List is empty
    {
        return EMPTY_LIST;
    }
    else
    {
	/* creating ptr that points to curr node and second last pointer to point prev node  */    
        dll* ptr = *tail;		 	// make ptr points to tail

        /* if only single node exists */
        if (*head == *tail)
        {
            *head = *tail = NULL;		// make head NULL
            ptr->link = ptr->prev = NULL;      // making prev and next pointers NULL
	    free(ptr);			// delete the curr node
            return e_success;
        }

        /* if more than 1 node exists , move fron tail node*/
        
	*tail = (*tail)->prev;
	(*tail)->link = NULL;
	ptr->link = ptr->prev = NULL;	
	free(ptr);
        return e_success;
    }
}
