/*
Title  : Product of nxn matrix with its transpose matrix
Author : Vaageesh
Date   : Wednesday 18 November 2020 11:04:48 PM IST 
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int rows, columns, i, j, k;			// declaring rows & columns for matrix
	printf("Enter number of rows: ");	
	scanf("%d", &rows);
	printf("Enter number of columns: ");
	scanf("%d", &columns);
	int *a[rows];				// defining matrix a 
	int *at[columns];			// defining transpose matrix a
	for (i = 0; i < rows; i++)					// defining 2D array for matrix "a" using DMA(Dynamic memory) 
	{
		a[i] = (int*)malloc(sizeof(int) * columns);
	}
	printf("Enter values of %dx%d matrix :\n", rows, columns);
	for ( i = 0; i < rows; i++)
	{
		for(j = 0 ; j < columns ; j++)
		{
			scanf("%d", &a[i][j]);				// reading matrix "a" from user
		}
	}
	for(i = 0; i < columns; i++)
	{
		at[i] = (int*)malloc(sizeof(int) * rows);			// defining 2D array for transpose matrix "at" usinf DMA(Dynamic Memory)
	}
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < columns; j++)
		{
			at[j][i] = a[i][j];				// generating trasnpose matrix "at" from "a"
		}
	}
	for(i = 0; i < columns; i++)
	{
		for(j = 0; j < rows; j++)
		{
			printf("%d ", at[i][j]);				// printing trasnpose matrix
		}
		printf("\n");
	}



	for(i = 0; i < columns; i++)						// product of matrix "a" with its transpose matrix "at"
	{
		for(j = 0; j < rows; j++)
		{
			int sum = 0;
			for(k = 0; k < rows; k++)
			{
				sum += a[i][k] * at[k][j] ;
			}
			printf("%d ", sum);
		}
		printf("\n");
	}

	return 0;
}



