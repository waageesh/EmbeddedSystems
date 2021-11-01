/*
Title  :  replace_n_bits_from_position
Author :  Vaageesh
Date   :  Thursday 08 October 2020 02:24:37 PM IST
*/

#include<stdio.h>

int set_nbits_from_pos(int val, int n, int b, int num);				// function prototype or declaration

int main()
{
	int num,a,b,val;							// declaring variables for num,val,a,b
	char cont;
	do
	{
		printf("Enter the value of 'n' :");				// reading values for num,val,a,b
		scanf("%d",&num);
		printf("Enter the value of 'I' :");
		scanf("%d",&val);
		printf("Enter the value of 'a' :");
		scanf("%d",&a);
		if ( a < 0 && a > 31)						// checking range of a within 0-31
		{
			printf("a is not in range");
			continue;
		}
		else
		{	
			printf("Enter the value of 'b' :");
			scanf("%d",&b);
			if ( b < 0 && b > 31 )					// checking range of b within 0-31
			{
				printf("b is not in range");
				continue;
			}
			else
			{


				printf("\nThe binary form of 'n'          :");
				for (int j = 31; j >= 0; j--)
				{
					printf("%d ", (num >> j) & 1);			// printing binary format of number
				}

				printf("\nThe binary form of 'I'          :");
				for (int j = 31; j >= 0; j--)
				{
					printf("%d ", (val >> j) & 1);			// printing binary format of value(I)
				}

				val = set_nbits_from_pos(val, b-a+1, b, num);		// calling fuction to replace bits, result storing in value(I)

				printf("\nThe binary form of modified 'I' :");
				for (int j = 31; j >= 0; j--)
				{
					printf("%d ", (val >> j) & 1);			// printing modified value(I)
				}

			}

		}


		printf("\nDo you want to continue(y/n) :");				// asking user if he wants to continue or not
		scanf(" %c",&cont);

	} while ( cont =='y' || cont == 'Y') ;						// continue if user enters Y/y

	return 0;

}


int set_nbits_from_pos(int val, int n, int b, int num)					// funcion declaration for replacing bits
{

	int val_mask = val & ( (-1<<b+1) | (~(-1<<b+1-n)) ) ;				// creating mask from value(I)
	int num_mask = ( (num & ~(-1<<n)) << (b+1-n) ) ;				// creating mask from number(num)
	return num_mask | val_mask ;							// 'OR'ing both masks to get modified value(I)
}	

