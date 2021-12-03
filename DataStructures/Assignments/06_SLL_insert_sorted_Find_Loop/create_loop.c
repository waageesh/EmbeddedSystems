/*
Title  : Single linked list( insert node at first)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/


#include <stdlib.h>
#include <stdio.h>
#include "single_linkedlist.h"

status create_loop(sll** head, int k)
{
	int node_num=0;
	sll* last;
	sll* k_node;				// initialize ptr1,ptr2 to head
	last = *head;
	if (*head == NULL)				// empty list case
	{
		return EMPTY_LIST;				// making given node as head
	}
	else					// if elements exist, update head pointer with new created node and node pointer with head pointer
	{
		if ((*head)->link == NULL)			// single node case
		{
			return SINGLE_NODE_LIST;
		}

		printf("k :%d, node_num : %d\n", k, node_num);
		while(last->link != NULL)		// move till last node
		{
			node_num++;
			if (node_num == k)		// checking whether kth node reached or not
			{
				k_node = last;		// assigning node address to k_node
				printf("k node data:%d\n", k_node->data);
			}
			last = last->link;
		}
		printf("k :%d, node_num : %d\n", k, node_num);
		last->link = k_node;			// linking last node to kth node
		return e_success;
	}
}
