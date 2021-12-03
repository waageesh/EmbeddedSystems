

#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b);
int maxheapify(int arr[], int index, int size);
int build_maxheap(int arr[], int size);
int heap_sort(int arr[], int size);
void printarray(int arr[], int size);


void swap (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int maxheapify(int arr[], int index, int size)
{
	int large = index;
	int L = 2 * index + 1;
	int R = 2 * index + 2;
	
	if ((arr[index] < arr[L]) && (L < size))
		large = L;
	else
		large = index;
	
	if ((arr[large] < arr[R]) && (R < size))
		large = R;
	if (index != large)
	{
		swap(&arr[large], &arr[index]);
		maxheapify (arr, large, size);
	}
}


int heap_sort(int arr[], int size)
{
	int i;
	for (i = size / 2 - 1; i >= 0; i--)
	{
		maxheapify(arr, i, size);
	}
	for (i = size - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		maxheapify(arr, 0, i);
	}
}


void printarray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main()
{
	int i, num;
	printf("Enter the num of elements : ");	
	scanf("%d", &num);
	int arr[num];
	printf("Enter the elements : ");
	for(i = 0; i < num; i++) 
	{
     	scanf("%d", &arr[i]);
  	}
	int size = sizeof(arr) / sizeof(arr[0]);
	heap_sort(arr, size);
	printf("Sorted array is :");
	printarray(arr, size);
	return 0;
}





