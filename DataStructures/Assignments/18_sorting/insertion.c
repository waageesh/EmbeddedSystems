#include "sort.h"

int insertion_sort(data_t arr[], data_t size)
{
	data_t i,j, temp;
	for(i = 1; i < size - 1; i++)
	{
		temp = arr[i];
		  j = i - 1;
		while(j >= 0 && (arr[j] > temp))
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
	return SUCCESS;
}
