/*
Title  :  increment_using_bitwise
Author :  Vaageesh
Date   :  Thursday 14 October 2020 02:24:37 AM IST
*/

#include<stdio.h>

int pre_increment ( int* num );				// function declaration for pre_increment, post_increment
int post_increment ( int* num );

int main()
{
	int num, option, i;				// declaring variables for number, pre/post increment option, auxillary number
	char cont;					// declaring variable for continue 
	do
	{
		printf("Enter the value of N :");	// taking input number from user
		scanf("%d", &num);
		printf("Enter the operation :\n1. Pre-Increment\n2. Post-Increment\nChoice :");
		scanf("%d", &option);			// taking pre/post increment option from user
		i = num ;				// copying actual number to auxillary number
		if (option == 1)
		{
			printf("After pre_increment, i = %d, num = %d", num, pre_increment(&num) );         // calling pre_increment function
		}
		else
		{
			printf("After post_increment, i = %d, num = %d", i, post_increment(&num) );	     // calling post_increment function
		}

		printf("\nDo you want to continue(yY/nN) :");		// asking user if he want to continue or not
		scanf(" %c", &cont);

	} while ( cont == 'y' | cont == 'Y' ) ;				// continue if user prompts y/Y

	return 0;
}

int pre_increment( int* num )				// pre-increment function definition
{
	if (*num & 1 == 0)				// checking for even or odd
	{
		*num = *num ^ 1;			// use xor(^) if even to increment
	}
	else
	{
		int i = 0;
		while(1)
		{
			if( *num & (1 << i) )			// checking if bit is 1
			{
				*num = *num & ~(1 << i) ;	// toggle the bit to 1 with mask ~(1<<i) if bit is 1
				i++;				// increment i for checking next bit
			}
			else
			{
				*num = *num | 1 << i ;		// if bit is 0, OR num with mask (1<<i) and break
				break;
			}
		}
	}
	return *num;					// return incremented value
}

int post_increment( int* num )
{
	if (*num & 1 == 0)				// checking for even or odd
	{
		*num = *num ^ 1;			// use xor(^) if even to increment
	}
	else
	{
		int i = 0;
		while(1)
		{
			if( *num & (1 << i) )			// checking if bit is 1
			{
				*num = *num & ~(1 << i) ;	// toggle the bit to 1 with mask ~(1<<i) if bit is 1
				i++;				// increment i for checking next bit
			}
			else
			{
				*num = *num | 1 << i ;		// if bit is 0, OR num with mask (1<<i) and break
				break;
			}
		}
	}
	return *num;					// return incremented value
}
