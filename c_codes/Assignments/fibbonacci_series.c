/*
Title : fibbonacci_series
Author: vaageesh
Date  : Saturday 19 September 2020 10:01:23 PM IST
*/


#include<stdio.h>
int main()
{
	char cont;
	do	
	{
		int num,prev=0,curr=1,next;			// defining previous , current and next terms in series
		printf("Enter a number :");
		scanf("%d",&num);				// taking n to generate fibbonacci series <=n
		if (num < 0)					// generating for -ve number
		{
			int next_abs ;
			printf("%d %d ",prev,curr);
			next=prev-curr;				// generating next term in series
			if (next<0)
			{
				next_abs=-next;			
			}
			while (next_abs <= -(num))		// checking next number less than or equal to given number irrespective of sign
			{
				printf("%d ",next);		// printing next term in series
				prev=curr;			// shiting previou and current to right in series
				curr=next;
				next=prev-curr;			// generating new 'next' term in series
				if (next<0)			
				{
					next_abs=-next;		// if next is -ve, making it as +ve to check if its crossed given number or not
				}
				else
					next_abs=next;
			}
		}
		else if(num==0)					// stopping series if 0 is given
		{
			printf("%d",prev);
		}
		else
		{						// fibbonacci series for +ve numbers
			printf("%d %d ",prev,curr);
			next=prev+curr;
			while(next<=num)
			{
				printf("%d ",next);
				prev=curr;			// shifting prev, curr to 1 position right
				curr=next;
				next=prev+curr;			// generating new 'next' term in series
			}
		}


		printf("\nDo you want to continue(y/n) :");	// asking user whether continue or not
		scanf(" %c",&cont);
	}
	while(cont=='y');
	return 0;
}
