/* 
Title  : Hash Table Insert (insert element into Hash Table using Direct Chaining)
Author : Vaageesh
Date   : Friday 11 December 2020 11:02:15 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include "Hash_table.h"

int main()
{
	int menu, data, size;
	char cont;
	printf("Enter the size of hash table array : ");
	scanf("%d", &size);
	hash_t hash_table[size];		// declaring hash table(array of structure here) of given size
	/*
	for (int i = 0; i < size; i++)
	{
		hash_table[i].index = i;
		hash_table[i].data = -1;
		hash_table[i].link = NULL;
	}
	*/
	do
	{
		printf("1. Hash Search\n2. Hash Insert\n3. Hash_delete_element\n4. Hash_table_delete\n5. Create HASH-TABLE\n");
		printf("Choose the option :");
		scanf("%d", &menu);

		switch(menu)
		{
			case 1 :							// searching element in hash_table
				{	
					printf("Enter the element to be searched:");	// reading data to searched
					scanf("%d", &data);
					if (hash_search(hash_table, data, size) != DATA_FOUND)
					{
						printf("Element %d doesn't found in hash table\n", data);
					}
					else
					{
						printf("Element %d found in hash table\n", data);
					}
					break;
				}
			case 2 :							// insert element in hash_table
				{
					printf("Enter the element to be inserted:");	// reading data to inserted
					scanf("%d", &data);
					hash_insert(hash_table, data, size);
					break;
				}
			case 3 :							// delete element in hash_table
				{	
					printf("Enter the element to be deleted:");			// reading data to deleted
					scanf("%d", &data);
					if (hash_delete_element(hash_table, data, size) != e_success)
					{
						printf("Element doesn't exist in hash table");
					}
					break;
				}
			case 4 :							// delete entire hash_table
				{
					if (hash_table_delete(hash_table, size) != e_success )	// if deleting hash_table done successfully or not
					{
					    printf("deleting empty HASH TABLE not possible\n");
					}
					break;
				}
			case 5 :							// delete entire hash_table
				{
					if (create_hash_table(hash_table, size) != e_success )	// if deleting hash_table done successfully or not
					{
					    printf("creating HASH TABLE Failed\n");
					}
					else
					{
					    printf("HASH TABLE created successfully\n");
					}
					break;
				}
			
		}
		printf("-----------------------\n");
		print_hash_table(hash_table, size);
		printf("-----------------------");						// printing HASH_TABLE
		
		printf("\nDo you want to continue (yY/nN) :");			// asking user if he want to to continue or not
		scanf(" %c", &cont);
	
	} while (cont == 'y' | cont == 'Y');						// continue if entered y/Y
	
	return 0;
}
