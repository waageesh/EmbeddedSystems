/* 
Title  : Hash Table Insert (insert element into Hash Table using Direct Chaining)
Author : Vaageesh
Date   : Friday 11 December 2020 11:02:15 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "Hash_table.h"

status hash_insert(hash_t* hash_table, int data, int size)
{
	/* calculate index at which given data should be added */
	int index = data % size;
	if (index < 0)					// handling -ve numbers
	{
		index = -index;
	}
	/* creating node to add to hash list*/
	hash_t* node = malloc(sizeof(hash_t));
	node->data = data;
	node->index = index;
	
	if (hash_table[index].data == -1 )		// if data is not there at given index
	{
		hash_table[index].index = index;
		hash_table[index].data = data;		// assign data at calculated index
		return e_success;
	}
	else  if (hash_table[index].link == NULL)	// if data is already there at index, and no LIST associated at that index
	{
		hash_table[index].index = index;
		hash_table[index].link = node;		// attach created node at that index
		node->link = NULL;			// make node link as NULL
		return e_success;
	}
	else						// data not there and if there is list at that index
	{
		hash_t* temp = &hash_table[index];	// assign address of given index of heash_table
		while(temp->link)			// traverse till last node
		{	
			//printf("temp %d\n", temp->data);
			temp = temp->link;
		}
		temp->link = node;			// attach create node at last of the list
		node->link = NULL;
		return e_success;
	}
	
}




