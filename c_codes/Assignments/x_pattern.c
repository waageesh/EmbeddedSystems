/*
Title  : x_pattern
Author : Vaageesh
Time   : Monday 21 September 2020 11:37:39 PM IST
*/


#include<stdio.h>

int main()
{
	int n;
	char cont;
	do
	{
		printf("Enter number of lines :");
		scanf("%d",&n);					// taking no of lines to be printed
		if ( n >= 32 )
		{
			printf("Number out of range");
		}
		else
		{
			for (int i=1;i<=n;i++)				// outer for loop for rows
			{	
				for(int j=1;j<=n;j++)			// inner loop for each row printing
				{
					if( i==j || (i+j)==(n+1) )	// checking if row index == column index (or) row+column = max_rows+1
					{
						if (i == (n/2)+1 && j == (n/2)+1 && n%2 != 0 )		// prints 2 hellos at centre only of odd no of lines given
						{
							printf("HelloHello");
						}
						else					// print if its not centre line(s)
						{
							printf("Hello");		// printing hello if above condition met
						}
					}
					else
					{
						printf(" ");		// printing space( ) if above condition not met
					}
				}
				printf("\n");				// printing next line

			}
		}

		printf("\nDo you wnat to continue(y/n) :");	// asking user to continue or not
		scanf(" %c",&cont);

	} while(cont=='y');

	return 0;
}
