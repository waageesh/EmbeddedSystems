/*
Title : perfect_number
Author: vaageesh
Date  : Saturday 19 September 2020 10:01:23 PM IST 
*/


#include<stdio.h>
#include<math.h>
int main()
{
	int num;
	char cont;
	do
	{
		printf("Enter a number :");
	       	scanf("%d",&num);
		
		if (num < 0)							// checking for -ve number which is INVALID input
		{
			printf("Invalid input");
		}
		else if (num>pow(2,20))						// checking within range or not
		{
			printf("Number out of range");
			
		}
		else			
		{	
			int sum=0;
			for(int i=1;i<=num;i++)					// looping for summ of all divisors for given number
			{
				if (num%i == 0)
				{
					sum=sum+i;				// adding divisor cummulatively
				}
			}
			if (sum/2 == num)					// checking if given num is half of sum of all divisors 
			{
				printf("%d is a perfect number",num);
			}
			else
			{
				printf("%d is not a perfect number",num);
			}
		}

		printf("\nDo you want to contniue(y/n) :");			// asking user to continue or not
		scanf(" %c",&cont);
	} 
	while(cont=='y');
	
	return 0;
}
