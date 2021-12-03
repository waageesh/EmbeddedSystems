/* 
Title  : Single linked list (sort nodes in list)
Author : Vaageesh
Date   : Tuesday 01 December 2020 11:55:02 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "single_linkedlist.h"

status sort_list_nodes(sll** head)
{
	int swapped=1;
	sll* ptr1 = *head;
	sll* ptr2;
	if (*head == NULL)
	{
	    /* creating node with data and link as NULL */
		return EMPTY_LIST;
	}
	else
	{
		while (ptr1->link)			// move till ptr1 reaches end
		{ 
			swapped = 0;
			ptr2 = ptr1->link;
			while (ptr2 != NULL) 		// move ptr2 reaches end
			{ 
			    sll* temp;
			    if (ptr1->data > ptr2->data) 			// if node1 data & node2 data are not in order
			    {  
				swap_nodes(head, ptr1->data, ptr2->data);	// swap the nodes to make them in order
				temp = ptr2;					// after swapping nodes, exhange ptr's to make them in previous places
				ptr2 = ptr1;
				ptr1 = temp;
				swapped = 1;
			    }
			    ptr2 = ptr2->link; 
			}
			ptr1 = ptr1->link ;
		}  
		return e_success;
		
	}
}


//To swap the data field of linked list
void swap_nodes(sll** head, int num1, int num2)
{  
    sll *prevNode1 = NULL;
    sll *prevNode2 = NULL;
    sll *node1 = *head; 
    sll *node2 = *head;
    sll *temp = NULL;  
      
    //Checks if list is empty  
    if(*head == NULL) 
    {  
        return;  
    }  
          
    //If num1 and num2 are equal, then list will remain the same  
    if(num1 == num2)  
        return;  
      
    //Search for node1  
    while(node1 != NULL && node1->data != num1)
    {  
        prevNode1 = node1;  
        node1 = node1->link;  
    }  
      
    //Search for node2  
    while(node2 != NULL && node2->data != num2)
    {  
        prevNode2 = node2;  
        node2 = node2->link;  
    }  
      
    if(node1 != NULL && node2 != NULL) 
    {  
          
        //If previous node to node1 is not null then, it will point to node2  
        if(prevNode1 != NULL)  
            prevNode1->link = node2;          
        else  
            *head  = node2;  
          
        //If previous node to node2 is not null then, it will point to node1  
        if(prevNode2 != NULL)  
            prevNode2->link = node1;  
        else  
            *head  = node1;  
          
        //Swaps the next nodes of node1 and node2  
        temp = node1->link;   
        node1->link = node2->link;   
        node2->link = temp;       
    }      
    else
    {  
        printf("Swapping is not possible\n");  
    }  
}


