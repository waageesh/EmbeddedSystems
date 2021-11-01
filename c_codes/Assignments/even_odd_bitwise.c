/*
Title  : Even_odd_bitwise
Author : Vaageesh
Date   : Wednesday 23 September 2020 04:42:44 PM IST
*/


#include <stdio.h>

int main()
{
	int n;
	char cont;
	do
	{
		printf("enter num :");
		scanf("%d",&n);

		if ( n & 1) 	                                // checks LSB bit is 0(odd) or 1(even)
		{
			if ( (n >> 31) & 1 )                    // checks MSB is 1(signed) or 0(unsigned)
			{   
				printf("%d is negative odd",n);    
			}
			else
			{
				printf("%d is positive odd",n); 
			}

		}

		else                                       	 // checks LSB bit is 0(odd) or 1(even)
		{
			if ( (n >> 31) & 1 )                   	// checks MSB is 1(signed) or 0(unsigned)
			{   
				printf("%d is negative even",n);    
			}
			else
			{
				printf("%d is positive even",n); 
			}
		}


		printf("\nDo you want to continue(y/n) :");	// asking user to continue or not
		scanf(" %c",&cont);

	} while( cont == 'y' || cont == 'Y' ) ;

	return 0;
}

