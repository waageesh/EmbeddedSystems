/*
Title  : Variance using Dynamic Memory Allocation
Author : Vaageesh
Date   : Friday 23 October 2020 06:27:03 PM IST
*/

#include <stdio.h>
#include <stdlib.h>

static float variance(int n, int* arr, float* d_arr, float* d2_arr);   // function prototype for variance function

int main()
{
	int n;								// declaring variables for no of elements, variance
	float sigma;
	char cont;
	do{
		printf("Enter no of elements :");					
		scanf("%d",&n);						// reading no of elements
		int* arr = malloc(n*sizeof(int));			// using malloc and sizeof(int), declaring total no of bytes for arrays
		float* d_arr = malloc(n*sizeof(int));			// dynamic memory allocation for storing X-mean values
		float* d2_arr = malloc(n*sizeof(int));			// dynamic memory allocation for storing (X-mean)^2 values

		sigma = variance(n, arr, d_arr, d2_arr);		// calling varaince function and returning variance to sigma

		printf("variance of entered numbers is %f\n", sigma);	// printing variance

		printf("Do you want to continue (yY / nN) :");		// asking user if he wants to continue
		scanf(" %c", &cont);

	} while ( cont == 'y' || cont == 'Y') ;				// continue if entered y/Y

	return 0;
}

static float variance(int n, int* arr, float* d_arr, float* d2_arr)	// function definition for variance of given array of values
{
	float mean = 0, d2_mean = 0;					// variable for calculating mean of given array and mean of array of (X-mean)^2

	for(int i=0; i<n; i++)						// reading n value into dynamic array
	{
		printf("[%d] -> ",i);
		scanf("%d", &arr[i]);
		mean = mean + arr[i] ;					// calculating sum for each element
	}

	mean = (mean / n) ;						// calculating mean by dividing it with n

	for(int i=0; i<n; i++)						// calculating array of values with X-mean and (X-mean)^2 
	{
		d_arr[i] = mean - arr[i] ;
		d2_arr[i] = d_arr[i] * d_arr[i];
		d2_mean = d2_mean + d2_arr[i];				// cumulative addition of (X-mean)^2 values
	}

	return (d2_mean / n) ;						// returning variance value of final array

}

