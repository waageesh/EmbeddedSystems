/*
Title  : Single linked list( delete node at last)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "single_linkedlist.h"


status delete_node_last(sll** head)
{
    if (*head == NULL)   // List is empty
    {
        return EMPTY_LIST;
    }
    else
    {
	/* creating ptr that points to curr node and second last pointer to point prev node  */    
        sll* ptr = (sll*)malloc(sizeof(sll));
        sll* sec_last = (sll*)malloc(sizeof(sll));
        ptr = *head;		 	// make ptr points to head

        /* if only single node exists */
        if (ptr->link == NULL)
        {
            *head = NULL;		// make head NULL
            free(ptr);			// delete the curr node
            return e_success;
        }

        /* if more than 1 node exists , move till last node*/
        while(ptr->link != NULL)                  // moving last but one node
        {
            sec_last = ptr;			  // assign curr node ptr to prev node sec_last ptr
            ptr = ptr->link;
        }
        sll* temp = malloc(sizeof(sll));        // creating temp node
        temp = ptr;                       // making last node as temp
        sec_last->link = NULL;                       // making last but one node points to NULL
        free(temp);                             // free the last node i.,e temp node

        return e_success;
    }
}
