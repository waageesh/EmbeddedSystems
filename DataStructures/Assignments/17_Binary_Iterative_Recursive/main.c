/* 
Title  : Binary Search (Iterative ad recursive)
Author : Vaageesh
Date   : Monday 14 December 2020 11:40:49 PM IST
*/

#include<stdio.h>
#include<stdio_ext.h>
#include "search.h"

int main()
{
	
	data_t option, i, element, status;
	char ch;
	do
	{
	int SIZE;
	printf("Enter size of array :");
	scanf("%d", &SIZE);
	data_t arr[SIZE];
		printf("\n1.Binary_search_iterative\n2.Binary_search_recursive");
		printf("\n");
		printf("\nChoose your option from above :");
		scanf("%d", &option);
		
		printf("Enter array elements\n");
		for(i = 0; i < SIZE ; i++)
		{
			scanf("%d", &arr[i]);
		}
		
		switch(option)
		{
			case 1 :
			    printf("enter element to search:");
			    scanf("%d", &element);
			    status = binary_iterative(arr, element, SIZE, 0);
				if(status == 1)
				{
					printf("\nElement found");
				}
				else
				{
					printf("\nElement not found");
				}
				break;
			case 2 :
				printf("\nenter element to search:");
			    scanf("%d", &element);
			    status = binary_recursive(arr, element, SIZE-1, 0);
				if(status == 1)
				{
					printf("\nElement found");
				}
				else
				{
					printf("\nElement not found");
				}
				break;
			default :
				printf("plz select valid option");
		}
		__fpurge(stdin);
		printf("\nDo you want to continue (Y/y||N/n):");
		scanf("%c",&ch);
	}while(ch == 'Y' || ch == 'y');
	return 0;
}
