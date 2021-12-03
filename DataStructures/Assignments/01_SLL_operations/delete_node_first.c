/*
Title  : Single linked list( delete node at first)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "single_linkedlist.h"


status delete_node_first(sll** head)
{
    if (*head == NULL)   // List is empty
    {
        return EMPTY_LIST;
    }
    else
    {
        sll* temp = (sll*)malloc(sizeof(sll));
        temp = *head;           // assign head(first) node to temp
        *head = (*head)->link;    // assign 2nd node to head
        free(temp);               // delete the first node i.e, temp node
        return e_success;
    }
}
