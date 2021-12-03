#include "sort.h"

int selection_sort(data_t arr[], data_t size)
{
	data_t i = 0, min, j;
	for(i = 0; i < size - 1; i++)
	{
		min = j;
		for(j = i + 1; j < size; j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
			if(min != i)
			{
				swap(arr[i], arr[min]);
			}
		}
	}
	return SUCCESS;
}
