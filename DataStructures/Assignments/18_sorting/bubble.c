#include "sort.h"

int bubble_sort(data_t arr[], data_t size)
{
	data_t i = 0, flag = 0, j;
	for(i = 0; i < size - 1; i++)
	{
		flag = 0;
		for(j = 0; j < (size - i - 1); j++)
		{
			if(arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = 1;
			}
		}
		if(flag == 0)
		  break;
	}
	return SUCCESS;
}
