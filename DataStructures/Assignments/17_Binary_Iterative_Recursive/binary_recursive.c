/* 
Title  : Binary Search (recursive)
Author : Vaageesh
Date   : Monday 14 December 2020 11:40:49 PM IST
*/

#include "search.h"
#include <unistd.h>

int binary_recursive(data_t arr[], data_t element, data_t high, data_t low)
{
	data_t mid = (low + high)/2;
	printf("low:%d, high:%d, arr[mid] %d, ele:%d\n", low, high, arr[mid], element);
	if(arr[mid] == element)
	{
		return 1;
	}
	else if (high < low)
	{
		return -1;
	}
	else if(element < arr[mid])
	{
		binary_recursive(arr, element, mid -1, low);
	}
	else
	{
		binary_recursive(arr, element, high, mid + 1);
	}
	
}
