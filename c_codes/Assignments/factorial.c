/*
Title  :  factorial_using_recursion
Author :  Vaageesh
Date   :  Thursday 08 October 2020 02:24:37 PM IST
*/


#include <stdio.h>

int main()
{
	static int num,fact=1;						// defining num, fact, cont as static variables
	static char cont;
	do
	{
		if (num < 1)						// beginning case of recursion
		{
			printf("Enter the number");
			scanf("%d",&num);
			if (num == 0)					// discarding recursion when num is 0, since 0! is 1
			{		
				printf("factorial of %d is 1\n", num);
				printf("\nDo you want to continue(y/n) :");
				scanf(" %c", &cont);
				//return 0;
			}
			fact = num ;					
		}
		if (num < 0)						// Invalid input since factorial for -ve is not valid
		{
			printf("Invalid input\n");
		}
		else if (num > 10)					// factorial for num>10 is out of int range
		{
			printf("%d is Out of range\n", num);
		}
		else							// if num>=0 and within range of int
		{
			if ( num != 1 )					// recursion till factorial being mutiplied from num to 1
			{
				fact = fact*(num-1);			// calculating fact for every recursion
				num--;
				main();					// recursion call by calling main again
			}
			else
			{
				printf("factorial is %d\n",fact);		// returning final factorial when reaches 1 from num
				printf("\nDo you want to continue(y/n) :");
				scanf(" %c", &cont);
				return 0;
			}
		}

		fact = num = 0;						// making fact, num as 0 for next number

	} while( cont == 'Y' | cont == 'y' ) ;				// continue if user enters 'Y/y'

	return 0;
}
