/*
Title  :  factorial_using_recursive_functions
Author :  Vaageesh
Date   :  Thursday 16 October 2020 08:24:37 PM IST
*/


#include <stdio.h>

int fibbonacci_series(int prev, int curr, int next, int num);		// function declaration for fibbonacci_series

int main()
{
	int num ;							// declaring variables for number & continue option
	char cont;	
	do
	{	
		int prev = 0, curr = 1, next, num;			// declaring and intializing previous, current and next variables
		printf("enter the number :");
		scanf("%d", &num);					// reading the number
		if (num == 0)						
		{
			printf("0");					// if num=0 , stopping series at 0
		}
		else
		{
			printf("0 1 ");						// printing starting 2 terms of series
			fibbonacci_series(prev, curr, 0, num);			
		}
		printf("\nDo you want to continue (yY/nN) :");		// asking user if he wants to continue or not
		scanf(" %c", &cont);

	} while (cont == 'y' | cont == 'Y');				// continue if user prmpts y/Y
}

int fibbonacci_series(int prev, int curr, int next, int num)		// function defintion for fibbonacci series
{

	if ( num > 0 )							// if num is positive
	{
		next = prev + curr;					// adds prev, curr to get next number if number is +VE
		if (next <= num)
		{
			printf("%d ", next);				// print next term in series
			prev = curr;					// moving prev, next to right and recalculating next term
			curr = next;
			next = prev + curr ;
			fibbonacci_series(prev, curr, next, num);	// recursive call for fibbonacci_series with new prev, next & next
		}
		else
		{
			return 0;					// if next temr reaches number, terminates the function
		}
	}

	else if ( num < 0 )						// if num is -VE
	{
		next = prev - curr;					// add prev, curr to get next term in series
		if (next >= num)					// checking next term reaches number or not
		{	
			if (next > -num)				// terminate when next reaches absolute value of num
			{
				return 0;
			}
			printf("%d ", next);				// print next term in series 
			prev = curr;					// move prev, curr to right and recalculate next term in series
			curr = next;
			next = prev + curr ;
			fibbonacci_series(prev, curr, next, num);	// recursive call for fibbonacci_series with new prev,curr & next values
		}
		else
		{
			return 0;					// terminate if next term reaches number
		}
	}
}
