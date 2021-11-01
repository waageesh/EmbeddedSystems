/*
Title  : progression.c
Author : waageesh
Date   : Tuesday 22 September 2020 11:37:09 PM IST
*/

#include<stdio.h>
#include<math.h>

int main()
{
	int a,r,n;
	char cont;
	do
	{
		printf("Enter the First Number :");				// taking first term
		scanf("%d",&a);
		printf("Enter the common difference/Ratio :");			// taking common-difference / Ratio for A.P and G.P
		scanf("%d",&r);
		printf("Enter number of terms :");				// taking no of terms to be generated for A.P, G.P & H.P
		scanf("%d",&n);

		if( a < 0 || r < 0 ||  n < 0)					// checking if any of the input is negative
		{
			printf("Invalid input(s)");
		}
		else if ( a > pow(2,10) || r > pow(2,10) || n > pow(2,10) )	// checking if of the input is > 2^10
		{
			printf("Input(s) out of range");
		}
		else
		{	int ap=0;
			int gp=0;
			float hp=0;
			printf("AP = ");	
			for(int i=1;i<=n;i++)					// loop to print A.P series
			{
				ap=a+(i-1)*r;					// calculating nth A.P term every time
				printf("%d ",ap);
			}

			printf("\nGP = ");
			for(int i=1;i<=n;i++)					// loop to print G.P series
			{
				int p = pow(r,i-1);				// calculating nth G.P term every time
				gp = a*p;
				printf("%d ",gp);
			}

			printf("\nHP = ");
			for(int i=1;i<=n;i++)
			{
				ap=a+(i-1)*r;					// calculating A.P term
				hp=(float)1/ap;					// calculating H.p term which reverse of of A.P term
				printf("%f ",hp);	
			}
		} 
		printf("\nDo you want to continue(y/n) :");			// asking user to continue or not
		scanf(" %c",&cont);

	} while( cont == 'y' );

	return 0;
}
