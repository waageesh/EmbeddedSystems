// Ref : https://youtu.be/eA3PMKlRZs8

#include <stdio.h>
int printArray(int* arr, int size)
{
	for (int i=0; i<size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int swap(int* n1, int* n2)
{
	int temp = *n1;
	*n1=*n2;
	*n2=temp;
}
int partition(int* arr, int low, int high)
{
	int pivot = arr[high];
	int i = low;
	for (int j=low; j<high; j++)
	{
		if (arr[j]<=pivot)
		{
			swap(&arr[j], &arr[i]);
			i++;
		}
	}
	swap(&arr[i], &arr[high]);
	return i;
}

void quickSort(int* arr, int low, int high)
{
	if (low<high)
	{
		int pivot_index = partition(arr, low, high);
		quickSort(arr, low, pivot_index-1);
		quickSort(arr, pivot_index+1, high);
	}
}

int main()
{
	int arr[] = {3,1,5,9,6,12,4,1,4,5,2,0};
	int size = sizeof(arr)/sizeof(int);
	quickSort(arr, 0, size-1);
	printArray(arr, size);

	return 0;
}


















// 
