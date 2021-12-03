/*
Title  : Single linked list(merge the 2 linkedlist in sorted manner)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "single_linkedlist.h"


status merge_list_sorted(sll** head1, sll** head2)
{
    /* creating a temp pointer and assing it to head*/
    sll* temp = *head1;
    while(temp->link)			// looping temp till NULL or end of the List
    {	
    	//sleep(1);
        printf("%d->", temp->data);	// printing node data 
        temp = temp->link;		// incrementing pointer everytime
    }
    
    temp->link = *head2;		// linking tail of list1 to list2
    sort_list_nodes(head1);		// sorted joined final list
    *head2 = NULL;			// making second list head as NULL
    return e_success;
}
