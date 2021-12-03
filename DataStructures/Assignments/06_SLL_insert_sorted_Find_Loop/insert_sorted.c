/*
Title  : Single linked list( insert in sorted place)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/


#include <stdlib.h>
#include <stdio.h>
#include "single_linkedlist.h"

status insert_sorted(sll** head, int data)
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
    	sll* temp = *head;
    	sll* curr = *head;
    	sll* next = (*head)->link;
    	if (next == NULL)			// single node case
    	{
    		if (data > temp->data)
    		{
    			ptr->link = temp->link;
    			temp->link = ptr;
    			return e_success;
    		}
    		else
    		{
    			ptr->link = temp;
    			*head = ptr;
    			return e_success;
    		} 
    	}
        while(curr != NULL)
        {
        	if (data >= temp->data && data <= next->data)
        	{
        		ptr->link = temp->link;
        		temp->link = ptr;
        		return e_success;
        	}
        	temp = curr;
		curr = temp->link;  			// moving temp to next link			
        }
	if (data > temp->data)
	{
		ptr->link = temp->link;
		temp->link = ptr;
		return e_success;
	}       
    }
}




