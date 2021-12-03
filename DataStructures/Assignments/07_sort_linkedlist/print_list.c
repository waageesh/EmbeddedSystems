/*
Title  : Single linked list( printing entire linkedlist)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "single_linkedlist.h"


status print_list(sll** head)
{
    /* creating a temp node and assing head to it  */
    sll* temp = malloc(sizeof(sll));
    temp = *head;
    while(temp)			// looping temp till NULL or end of the List
    {	
    	//sleep(1);
        printf("%d->", temp->data);	// printing node data 
        temp = temp->link;		// incrementing pointer everytime
    }		
}
