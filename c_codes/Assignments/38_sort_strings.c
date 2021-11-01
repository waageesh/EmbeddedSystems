/*
Title  : sort strings in 2D array
Author : vaageesh
Date   : Saturday 31 October 2020 05:16:33 PM IST
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CITY_NAME_LEN 32					// defining MACRO for city name length

int city_sort(const void* city1, const void* city2) ;		// function prototype for city sort

int main()
{       
	int n;
	char cont;
	do
	{
		printf("Enter no of cities :");
		scanf("%d", &n);							// reading no of cities
		char (*cities)[CITY_NAME_LEN] = malloc(sizeof(char)*10*n);		// Dynamic memory allocation for 2D array of cities

		printf("Enter the %d names of length max 32 characters in each:\n", n);	
		for (int i = 0; i < n ; i++)
		{   
			printf("[%d] -> ", i);
			scanf("%s",cities[i]);						// reading city names into 2D array
		}

		printf("\ncities before sort:\n");
		for(int i = 0; i < n ; i++)
		{
			printf("[%d] -> %s\n", i, cities[i]);				// printing city names before sorting
		}

		qsort(cities, n, CITY_NAME_LEN, city_sort);				// sorting strings using qsort

		printf("\ncities after sort:\n");					// printing city names after sorting
		for(int i = 0; i < n ; i++)
		{
			printf("[%d] -> %s\n", i, cities[i]);
		}	
		
		free(cities);								// free the Dynamic memory allocated for cities
		printf("Do you want to continue (yY/nN) :");				// asking user to continue or not
		scanf(" %c", &cont);

	} while (cont  == 'Y' || cont == 'y');						// continue if entered  y/Y
	return 0;
}

int city_sort(const void* city1, const void* city2)					// funciton definiton for string sorting
{

	int ret = strcasecmp( (char*)city1, (char*)city2);				// comparing 2 strings using strmcp function
	if (ret == 0)									// returns 0 if equal
		return 0;
	else if (ret > 0)								// returns +ve value if city1 ascii value > city2 value
		return 1;
	else										// returns -ve value if city1 ascii value < city2 value
		return -1;
}

