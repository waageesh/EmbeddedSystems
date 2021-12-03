/*
Title  : Single linked list(insert data after given node data)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "single_linkedlist.h"

status insert_after(sll** head, int data, int after_before_data)
{
	if (*head == NULL)
	{
		return EMPTY_LIST;
	}
	else
	{
		/* create ptr and temp pointers*/
		sll* ptr;
		sll* temp = malloc(sizeof(sll));
		ptr = *head;
		while(ptr)			
		{	
			if (ptr->data == after_before_data)
			{
				temp->data = data ;     // changing prevptr link to new node
				temp->link = ptr->link; // assigning ptr link to create node link
				ptr->link = temp;	// upodating ptr link to new node created
				return e_success;
			}
			else
			{	
				ptr = ptr->link;	// if data not matches, increment ptr to next node
			}
		}

		return e_failure;
	}
}
