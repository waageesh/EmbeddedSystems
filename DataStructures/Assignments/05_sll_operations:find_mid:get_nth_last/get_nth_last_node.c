/*
Title  : Single linked list( printing entire linkedlist)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "single_linkedlist.h"


status get_nth_last_node(sll** head, int* element, int pos)
{
	if ( *head == NULL )			// if list is empty
	{
		return EMPTY_LIST;
	}
	else					// if list is non empty
	{   
		int count = 0;	
		int i = 1;
		/* temp node to move single stpe, ptr_n to move n_steps every time */
		sll* temp = malloc(sizeof(sll));	
		sll* ptr_n = malloc(sizeof(sll));

		/* assign both pointers to head */
		temp = ptr_n = *head;
		
		while(ptr_n)			// looping ptr_n till last node / NULL
		{
			if (count == pos)	// checking count reaches pos, to surpass this for 1st iteration
			{
				temp = temp->link;		// increment temp,ptr_n to next node single step from 2nd iteration
				ptr_n = ptr_n->link;
				if (ptr_n == NULL)		// if ptr_n reaches last node i.,e NULL
				{
					*element = temp->data;	// return node data
					return e_success;
				}
			}		
			while(count != pos)			// for 1st iteration, move ptr_n alone for n times
			{
				if (ptr_n->link == NULL)	// if only one node exists
				{
					*element = temp->data;  // return that single node data
					return e_success;;
				}
				else
				{
					ptr_n = ptr_n->link;	// if ptr_n doesn't reaches NULL, increment to next node
					count++;		// increment count 
				}
			}
		}
	}
}
