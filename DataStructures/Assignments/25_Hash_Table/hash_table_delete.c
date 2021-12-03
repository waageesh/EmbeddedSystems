/* 
Title  : Hash Table Delete (delete Hash Table using Direct Chaining)
Author : Vaageesh
Date   : Friday 11 December 2020 11:02:15 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "Hash_table.h"

status hash_table_delete(hash_t* hash_table, int size)
{
	/* creating pointers to point nodes of hash_table list */
	hash_t* temp;
	hash_t* prev;				
	for(int i = 0; i < size; i++)			// looping temp till NULL or end of the List
	{
		if (hash_table[i].data == -1 )
		{
			continue;	
		}
		else if (hash_table[i].link != NULL)
		{	
			temp = hash_table[i].link;
			prev = &hash_table[i];
			while(temp)
			{
				prev->link = temp->link;
				free(temp);
				temp = prev->link;
			}
		}
		hash_table[i].data = -1;
	}	
	return e_success;
}


