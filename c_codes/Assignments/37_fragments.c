/*
Title  : sorting fragments based on average values of each fragment stored at end of fragment
Author : Vaageesh
Date   : Thursday 12 November 2020 01:52:53 AM IST
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int rows;						
	printf("Enter no of rows :");
	scanf("%d", &rows);						// reading no of rows for 2D array
	float *p[rows];							// floating pointer to array with read no rows above
	int col_arr[rows];
	for (int i = 0; i < rows; i++)					// loop to allocate size for 1D arrays inside pointer to arrays
	{
		printf("Enter no of columns in row[%d] :", i);		// read col size for each 1D array
		scanf("%d", &col_arr[i]); 
		p[i] = malloc( sizeof(float) * (col_arr[i]+1) );	// dynamic memory allocation of given col size
	}

	for (int i = 0; i < rows; i++)					// loop to enter element for each row
	{
		float sum = 0;
	       	int cnt = 0;
		printf("Enter values of row[%d] :",i);			
		for (int j = 0; j < col_arr[i] ; j++)			
		{
			scanf("%f", ( *(p + i) + j));			// reading element and storing at ith tow, jth col in 2D array
			sum = sum + *(*( p + i ) + j);			// cummulative addition of element for every iteration
			cnt++;						// getting elements count for each row
		}
		sum = sum / cnt;					// elements sum divided by elements count giving average
		*(*( p + i ) + col_arr[i] ) = sum ;
	}
	
	printf("Before sorting output is :\n");				// printing stored values in 2D array, along with average values at end of each 1D array
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j <= col_arr[i] ; j++)
		{
			printf("%.2f ", *(*(p+i)+j));
		}
		printf("\n");
	}

	for (int i = 0; i < rows-1; i++)				// loop tp re-arrange fragment based on average values of each 1D array
	{
		for (int j = 0; j < rows - i - 1; j++)			
		{
			if ( *(*(p + j) + col_arr[j] ) > *(*(p + j+1) + col_arr[j+1]) )		// compare adjacent elements everytime, for swapping if not in order
			{
				int temp = col_arr[j+1];					// swapping col_size in col_arr, if average value is not in order
				col_arr[j+1] = col_arr[j];
				col_arr[j] = temp;
				p[j] = realloc(p[j], sizeof(float) * col_arr[j] );		// reallocating memory for 1d array, according swapped column sizes above
				p[j+1] = realloc(p[j+1], sizeof(float) * col_arr[j+1] );
				float* temp_ptr = p[j+1];					// now swap address of re-allocated pointer arrays, to re-arrange fragment
				p[j+1] = p[j];
				p[j] = temp_ptr;
			}
		}
	}

	printf("After sorting output is :\n");				// printing fragments after swapping
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j <= col_arr[i] ; j++)
		{
			printf("%.2f ", p[i][j] );
		}
		printf("\n");
	}


	return 0;
}
