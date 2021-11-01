/*
Title  : user defined read_int functon to read integers, alternative to scanf()
Author : Vaageesh	
Date   : Tuesday 03 November 2020 02:52:12 PM IST 

*/


#include <stdio.h>

void print_sorted_array(float arr[], int count_arr[], int size);		// function prototype for printing sorted array 

int main()
{
	int size;								// size for defining array size
	char cont;
	do
	{
		printf("Enter the count of float elements need to store :");		
		scanf("%d",&size);
		float arr[size];						// declaring float array with user given size
		int count_arr[size], count;					// declaring count array to get no of element's count, that are <= every number
		for(int i = 0 ; i < size ; i++)					// loop to read values into float array
		{
			printf("[%d] = ", i);
			scanf("%f", &arr[i]);
		}

		print_sorted_array(arr, count_arr, size);			// calling printed_sorted_array to print elements in sorted way, without modifying actual array

		printf("Array after sorted\n");			

		for(int i = 0 ; i < size ; i++)					// printing array elements according to no of element's count <= curr element, from count array
		{ 
			count = i;
			for(int j = 0 ; j < size ; j++)
			{
				if(count_arr[j] == count)
				{
					printf("%f ", arr[j]);
				}
			}
		}
		
		
		printf("\nDo you want to continue (yY/nN) :");			// asking user if he want to continue or not
		scanf(" %c", &cont);

	} while (cont == 'Y' || cont == 'y');					// continue if he entered y/Y

	return 0;
}


void print_sorted_array(float arr[], int count_arr[], int size)			// function prototype for printing sorted array 
{

	int count=0;
	for(int i = 0 ; i < size ; i++)                                        	// loop to get no of elements less than current number
	{
		count=0;
		for(int j = 0 ; j < size ; j++)					// loop counting how many elements are less than current element
		{
			if(arr[i] < arr[j])
			{
				count++;
			}
		}
		count_arr[i] = count;
	}
}
