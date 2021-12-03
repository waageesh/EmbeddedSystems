/*
Title  : Double linked list( printing entire linkedlist)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "double_linkedlist.h"


status print_list(dll** head)
{
    /* creating temp and pointing to head  */	
    dll* temp = malloc(sizeof(dll));
    temp = *head;
    while(temp)				// loop till last node
    {
        printf("%d->", temp->data);	// prints node's data
        temp = temp->link;		// increment temp to next node
    }
}
