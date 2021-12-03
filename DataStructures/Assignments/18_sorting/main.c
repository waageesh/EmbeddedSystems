/* 
Title  : Sorting (Bubble, insertion, selection)
Author : Vaageesh
Date   : Monday 14 December 2020 11:40:49 PM IST
*/

#include <stdio.h>
#include <stdio_ext.h>
#include "sort.h"

int main()
{
	data_t option, i, status;
	data_t size;
	printf("enter the size :");
	scanf("%d", &size);
	data_t arr[size];
	char ch;
	do
	{
		printf("Enter array elements :");
		for(i = 0; i < size ; i++)
		{
			scanf("%d", &arr[i]);
		}
		printf("\n**Menu**");
		printf("\n1.Bubble_sort\n2.Insertion_sort\n3.Selection_sort");
		printf("\nselect your option :");
		scanf("%d", &option);
		switch(option)
		{
			case 1 :
				{
					status = bubble_sort(arr, size);
					print_array(arr, size);
					if(status == 1)
					{
						printf("\nArray sorted using bubblesort successfully");
					}
					else
					{
						printf("\nsorting failure");
					}
					break;
				}
			case 2 :
				{
					status = insertion_sort(arr, size);
					print_array(arr, size);
					if(status == 1)
					{
						printf("\nArray sorted using insertion_sort successfully");
					}
					else
					{
						printf("\nsorting failure");
					}
					break;
				}
			case 3 :
				{
					status = selection_sort(arr, size);
					print_array(arr, size);
					if(status == 1)
					{
						printf("\nArray sorted using selection_sort successfully");
					}
					else
					{
						printf("\nsorting failure");
					}
					break;
				}
			default :
				printf("\nplease select valid option");
		}
		__fpurge(stdin);
		printf("\nDo you want to continue (Y/y||N/n):");
		scanf("%c",&ch);
	}while(ch == 'Y' || ch == 'y');
	return 0;
}



void print_array(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


