/* 
Title  : Hash Table create (create Hash Table with given size)
Author : Vaageesh
Date   : Friday 11 December 2020 11:02:15 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "Hash_table.h"

status create_hash_table(hash_t* hash_table, int size)
{
	/* initializing the HASH_TABLE with default values data=-1 to indicate it is empty, 
	   index with i and link as NULL to indicate no list attqached for that index of hash table */
	for (int i = 0; i < size; i++)
	{
		hash_table[i].index = i;
		hash_table[i].data = -1;
		hash_table[i].link = NULL;
	}
	return e_success;
}




