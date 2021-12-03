/* 
Title  : Binary Search (Iterative)
Author : Vaageesh
Date   : Monday 14 December 2020 11:40:49 PM IST
*/

#include "search.h"

int binary_iterative(data_t arr[], data_t element, data_t high, data_t low)
{
	data_t mid = 0;		// intializing mid value
	while(low <= high)
	{
		mid = (low + high)/2;		// calculating mid value
		if(arr[mid] == element)	// if element found
		{
			return 1;
		}
		else if(element < arr[mid])	// element is in left half
		{
			high = mid - 1;	// move high before mid
		}
		else				// element is in right half
		{	
			low = mid + 1;		// move low after to mid
		}
	}
	return -1;
}
