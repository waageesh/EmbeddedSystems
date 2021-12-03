/*
Title  : Single linked list( printing entire linkedlist)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "double_linkedlist.h"


status print_list(dll** head)
{
    if (*head == NULL)		// empty list
    {
	    return EMPTY_LIST;
    }	    
    /* creating a temp node and assing head to it  */
    dll* temp = malloc(sizeof(dll));
    temp = *head;
    while(temp)			// looping temp till NULL or end of the List
    {
        printf("%d->", temp->data);	// printing node data 
        temp = temp->link;		// incrementing pointer everytime
    }		
}
