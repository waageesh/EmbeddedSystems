/* 
Title  : Hash Table Insert (insert element into Hash Table using Direct Chaining)
Author : Vaageesh
Date   : Friday 11 December 2020 11:02:15 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "Hash_table.h"

status hash_search(hash_t* hash_table, int data, int size)
{
	/* calculate index at which given data should be added */
	int index = data % size;
	if (index < 0)					// handling -ve numbers
	{
		index = -index;
	}
	if (hash_table[index].data == -1 )		// if data is not there at given index
	{
		return DATA_NOT_FOUND;
	}
	else  if (hash_table[index].data == data)	// if data is already there at index, and no LIST associated at that index
	{
		return DATA_FOUND;
	}
	else if (hash_table[index].link == NULL)
	{
		return DATA_NOT_FOUND;
	}
	else					// data not there and if there is list at that index
	{
		hash_t* temp = &hash_table[index];	// assign address of given index of heash_table
		while(temp->link)			// traverse till last node
		{
			temp = temp->link;
			if (temp->data == data)
			{
				return DATA_FOUND;
			}
		}
		return DATA_NOT_FOUND;
	}	
}


