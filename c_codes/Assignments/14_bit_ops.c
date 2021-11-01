/*
Title  :  bitwise_operations
Author :  Vaageesh
Date   :  Thursday 08 October 2020 02:24:37 PM IST
*/

#include <stdio.h>


int get_nbits(int num, int n);						// declaring function prototypes for bitwise operations
int replace_nbits(int num, int n, int val);
int get_nbits_from_pos(int num, int n, int pos);
int replace_nbits_from_pos(int num, int n, int pos, int val);
int toggle_bits_from_pos(int num, int n, int pos);
int print_bits(unsigned int num, int n);

int main() 
{
	int opt,num,n,val,pos,final;					// declaring number, value, menu(opt), position and final variables
	char cont;
	printf("Select bit operation from below list\n1. get_nbits\n2. set_nbits\n3. get_nbits_from_pos\n4. set_nbits_from_pos\n5. toggle_bits_from_pos\n6. print_bits\n");
	do
	{
		printf("Enter your choice :");					// choose bitwise function from menu
		scanf("%d",&opt);
		switch(opt)
		{
			case 1 : 						// case for 'get_n_bits' bitwise function
				{
					// get_n_bits
					printf("Enter number :");		// reading number, n
					scanf("%d",&num);
					printf("Enter no bits to fetch :");
					scanf("%d",&n);
					final = get_nbits(num, n);		// calling get_nbits bitwise function and storing result in 'final'
					printf("%d",final);
					break;
				}

			case 2 : 
				{
					// set_n_bits				// case for 'set_n_bits' bitwise function
					printf("Enter number :");		// reading number, value, no_of_bits to fetch
					scanf("%d",&num);	
					printf("Enter value :");
					scanf("%d",&val);
					printf("Enter no bits to fetch :");
					scanf("%d",&n);
					final = replace_nbits(num, n, val);	// calling 'replace_nbits' bitwise function,storing result in 'final'
					printf("%d",final);
					break;
				}

			case 3 : 
				{       
					// get_n_bits_from_pos			// case for 'get_n_bits' bitwise function
					printf("Enter number :");		// reading number, no_bits_to_fetch, position
					scanf("%d",&num);
					printf("Enter no bits to fetch :");
					scanf("%d",&n);
					printf("Enter pos :");
					scanf("%d",&pos);
					final = get_nbits_from_pos(num, n, pos);	// calling 'get_nbits_from_pos' bitwise function
					printf("%d",final);
					break;
				}

			case 4 : 						// case for 'replace_nbits_from_pos' bitwise function
				{
					printf("Enter number :");		// reading number, value, no_of_bits_to_fetch, position
					scanf("%d",&num);
					printf("Enter value :");
					scanf("%d",&val);
					printf("Enter no bits to fetch :");
					scanf("%d",&n);
					printf("Enter pos :");
					scanf("%d",&pos);
					final = replace_nbits_from_pos(num, n, pos, val);	// calling 'replace_nbits_from_pos' bitwise function
					printf("%d",final);
					break;
				}

			case 5 : 						// case for 'toggle_bits_from_pos' bitwise function
				{
					printf("Enter number :");		// read number , no_of_bits_to_fetch, position
					scanf("%d",&num);
					printf("Enter no bits to fetch :");
					scanf("%d",&n);
					printf("Enter pos :");
					scanf("%d",&pos);
					final = toggle_bits_from_pos(num, n, pos);		// calling 'toggle_bits_from_pos' bitwise function
					printf("%d",final);
					break;
				}

			case 6 : 						// case for 'print_bits' bitwise function
				{
					printf("Enter number :");		// read number, no_ofbits_to_fetch
					scanf("%d",&num);
					printf("Enter no bits to fetch :");
					scanf("%d",&n);
					print_bits(num, n);			// calling 'print_bits' bitwise function
					break;
				}
		}

		printf("\nDo you want to continue(y/n) :");			// asking user if he wants to continue or not
		scanf(" %c",&cont);

	} while (cont == 'y' || cont == 'Y') ;					// continue if user enters Y/y
	return 0;

}

int get_nbits(int num, int n)					// bitwise function for getting n_bits from LSB
{
	return  (num & ~(-1 << n)); 
}

int replace_nbits(int num, int n, int val)			// bitwise function for replacing n bits from LSB of number with n bits of value
{
	return ((val & ~(-1 << n)) | (-1 << n)) & num ;
}

int get_nbits_from_pos(int num, int n, int pos)			// bitwise function for getting n_bits from pos position
{
	return  num >> (pos + 1 - n) & ~(-1 << n) ;
}

int replace_nbits_from_pos(int num, int n, int pos, int val)	// bitwise function for replacing n_bits from pos of value , with LSB n bits of number
{
	int num_mask = num & ( (-1<<pos+1) | (~(-1<<pos+1-n)) ) ;  // setting required bits to 0 in number
	int val_mask = ( (val & ~(-1<<n)) << (pos+1-n) );	  // creating required bits with bits from val and rest all bits 0
	return (num_mask | val_mask) ;
}

int toggle_bits_from_pos(int num, int n, int pos)		// bitwise function for toggling n bits starting from position 'pos'
{
	//return ~((-1 << pos + 1) | ~(-1 << n)) ^ num ;
	return ~((-1 << pos + 1) | ~(-1 << pos - n + 1)) ^ num ;
}

int print_bits(unsigned int num, int n)				// bitwise function to print n bits from LSB of given number
{
	int val = ~(-1<<32-n) & num ;				// getting bits from nth position to 0th position of given number
	for ( int i = n-1 ; i >= 0 ; i-- )
	{
		printf("%d ", (val >> i) & 1);			// printing fetched n bits from LSB
	}
	return 0;
}





