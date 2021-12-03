/*
Title  : Single linked list( reverse list recursive method)
Author : Vaageesh
Date   : Tuesday 05 December 2020 11:55:02 AM IST
*/

#include <stdio.h>
#include <stdlib.h>
#include "single_linkedlist.h"

sll* reverse_list_recursive(sll** head)
{
	if (*head == NULL || (*head)->link == NULL)		// when reaches END
	{
		return *head;
	}
        /* reverse the rest list and put the first element at the end */
        sll* rest = reverse_list_recursive( &((*head)->link) );
        sll* temp = (*head)->link;
	temp->link = *head;
        
	/* making curr node next pointer NULL, which is updated in previous recursive call */
        (*head)->link = NULL;
        
	/* return the head pointer through the recursion to main */
        return rest;

}

