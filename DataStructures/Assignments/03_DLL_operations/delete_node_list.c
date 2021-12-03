/*
Title  : Single linked list( Delete entire linkedlist)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "double_linkedlist.h"

status delete_list(dll** head, dll** tail)
{
    if (*head == NULL)   // List is empty
    {
        return EMPTY_LIST;
    }
    else
    {
        while( *head != NULL )
        {
	    dll* temp = *head;           // assign head node to temp
	    if ((*head)->link == NULL)
	    {
		    *tail = NULL;
	    }
            *head = (*head)->link;	// assign head to next pointer
            free(temp);               // delete the first node i.e, temp node
	    
        }
	return e_success;
    }
}
