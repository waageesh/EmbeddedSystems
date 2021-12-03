/*
Title  : Single linked list( printing entire linkedlist)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "single_linkedlist.h"


status print_list(sll** head)
{
    /* creating temp and pointing to head  */	
    sll* temp = malloc(sizeof(sll));
    temp = *head;
    while(temp)				// loop till last node
    {
        printf("%d->", temp->data);	// prints node's data
        temp = temp->link;		// increment temp to next node
    }
}
