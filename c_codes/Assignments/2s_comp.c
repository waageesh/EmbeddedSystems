/*
Title  : 2s_Compliment
Author : Vaageesh
Date   : Wednesday 23 September 2020 04:42:44 PM IST
*/


#include<stdio.h>
#include<math.h>

int main()
{
	int num,bit;
	long int two_comp;
	int bits_cnt = sizeof(int) * 8;
	char cont;
	do
	{
		int toggle = 0;
		printf("Enter the number :");				      	// taking number from user
		scanf("%d", &num);

		two_comp = pow(2, bits_cnt)-num;				      	// generating 2s compliment(2^32-number)
		
		printf("\n+%d : ", num);

		for (int i = (bits_cnt - 1) ; i >= 0 ; i--)                     	// loop to print binary 32 bits of given number
		{
			bit = (num >> i) & 1;                			// shifting MSB to end and checking it's 0/1 using & operator
			printf("%d ", bit);
		}

		printf("\n-%d : ", num);
 
		for (int i = (bits_cnt - 1) ; i >= 0 ; i--)                     	// loop to print binary 32 bits of 2s_compliment of given number
		{
			bit = (two_comp >> i) & 1;	  	             	// shifting MSB to end and checking it's 0/1 using & operator
			printf("%d ", bit);
		}


		printf("\nDo you want to continue(y/n) :");			// asking user to continue or not
		scanf(" %c", &cont);

	} while ( cont == 'y' || cont == 'Y' );


	return 0;
}


