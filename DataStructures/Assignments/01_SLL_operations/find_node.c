/*
Title  : Single linked list( find node existence in linkedlist)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "single_linkedlist.h"

status find_node(sll** head, int data)
{
    if (head == NULL)				// List is empty
	{
		return  EMPTY_LIST;
	}
	else					// List is not empty
	{
	    sll* ptr = malloc(sizeof(sll));     // creating a node and assigning it to head
	    ptr = *head;
	    while(ptr)				// looping ptr till reaches end
	    {
	        if (ptr->data == data)		// if data found, return data_found
	        {
	            return DATA_FOUND ;
	        }
	        ptr = ptr->link;		// moving ptr to next node
	    }
	    return DATA_NOT_FOUND;
	}
}
