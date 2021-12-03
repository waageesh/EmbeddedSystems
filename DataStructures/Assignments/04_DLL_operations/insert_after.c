/*
Title  : Double linked list(insert data after given node data)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "double_linkedlist.h"

status insert_after(dll** head, int data, int after_before_data)
{
	if (*head == NULL)
	{
		return EMPTY_LIST;
	}
	else
	{
		/* create ptr and temp pointers*/
		dll* ptr;
		dll* temp = malloc(sizeof(dll));
		temp->data = data;
		temp->prev = temp->link = NULL;
		dll* prev_ptr;
		ptr = *head;
		if (ptr->data == after_before_data)			// single node case
		{
			if (ptr->link != NULL)	// single node and and data matches
			{
				temp->link = ptr->link; // assigning ptr link to create node link
				temp->prev = ptr;	// assigning prev pointer to ptr
				ptr->link = temp;	// updating ptr link to new node created
				return e_success;	
			}	
			else				// single node and data doesn't matches
			{
				ptr->link = temp;
				temp->prev = ptr;
				return e_success;
			}
		}
		while(ptr)			
		{	
			if (ptr->data == after_before_data)
			{
				temp->link = ptr->link; // assigning ptr link to create node link
				temp->prev = ptr;	// assigning prev pointer to ptr
				ptr->link = temp;	// updating ptr link to new node created
				
				/* shiting ptr, temp to next positions and to create prev connections  */
				ptr = temp;	// moving ptr to next node i.e, temp
				if(temp->link != NULL)	// moving temp to next node
				{
					printf("hello\n");
					temp = temp->link;
					temp->prev = ptr;
					return e_success;
				}
				else
				{
					printf("temp->link is empty\n");
				}
				return e_success;
			}
			else
			{
				ptr = ptr->link;	// if data not matches, increment ptr to next node
			}
		}

		return DATA_NOT_FOUND;
	}
}
