/* 
Title  : Hash Table Insert (insert element into Hash Table using Direct Chaining)
Author : Vaageesh
Date   : Friday 11 December 2020 11:02:15 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "Hash_table.h"


status print_hash_table(hash_t* hash_table, int size)
{
	hash_t* temp;					// assign address of  of hash_table
	for(int i = 0; i < size; i++)			// looping temp till NULL or end of the List
	{
		printf("%d : ", hash_table[i].data);	// printing node data 
		if (hash_table[i].link != NULL)
		{	
			temp = hash_table[i].link;
			while(temp)
			{
				printf("%d->", temp->data);
				temp = temp->link;
			}
		}
		printf("\n");
	}		
}
