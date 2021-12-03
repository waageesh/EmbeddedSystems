/* 
Title  : Merge Sort
Author : Vaageesh
Date   : Monday 14 December 2020 11:40:49 PM IST
*/


#include<stdlib.h>
#include<stdio.h>

void printArray(int arr[], int size);

void merge(int arr[], int l, int m, int r);

void mergeSort(int arr[], int L, int R);

// Merge Function
void merge(int arr[], int lft, int m, int rt)
{
	int i, j, k;
	int n1 = m - lft + 1;
	int n2 = rt - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[lft + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];
	i = 0;
	j = 0;
	k = lft;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;	
	}
}

void mergeSort(int arr[], int L, int R)
{
	if (L < R)
	{
		int mer = L + (R - L) / 2;
		mergeSort(arr, L, mer);
		mergeSort(arr, mer + 1, R);
		merge(arr, L, mer, R);
	}
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
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	printf("Given array is : \n");
	printArray(arr, arr_size);
	mergeSort(arr, 0, arr_size - 1);
	printf("\nSorted array is : \n");
	printArray(arr, arr_size);
	return 0;
}


void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}



