/* 
Title  : Hash Table delete element (delete element from Hash Table using Direct Chaining)
Author : Vaageesh
Date   : Friday 11 December 2020 11:02:15 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "Hash_table.h"

status hash_delete_element(hash_t* hash_table, int data, int size)
{
	/* calculate index at which given data should be added */
	int index = data % size;
	if (index < 0)					// handling -ve numbers
	{
		index = -index;
	}
	
	hash_t* temp = &hash_table[index];		// assign address of given index of heash_table
		
	if (hash_table[index].data == -1 )		// if data is not there at given index
	{
		return DATA_NOT_FOUND;
	}
	else if (hash_table[index].data == data)
	{
		if (hash_table[index].link == NULL)
		{
			hash_table[index].data = -1;
			return e_success;
		}
		else
		{
			temp = temp->link;	
			hash_table[index].data = temp->data;
			hash_table[index].link = temp->link;
			return e_success;
		}
	}
	else					// data not there and if there is list at that index
	{	hash_t* prev = temp;
		while(temp)			// traverse till last node
		{
			printf("prev %d, temp %d\n", prev->data, temp->data);
			if (temp->data == data)
			{
				printf("prev %d, temp %d\n", prev->data, temp->data);
				prev->link = temp->link;
				free(temp);
				return e_success;
			}
			prev = temp;
			temp = temp->link;
			//printf("prev %d, temp %d\n", prev->data, temp->data);
		}
		return DATA_NOT_FOUND;
	}	
}


