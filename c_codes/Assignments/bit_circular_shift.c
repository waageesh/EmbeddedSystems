#include <stdio.h>

int circular_right_shift(int num, int n);			// function declaration for circular left and right shift of a number
int circular_left_shift(int num, int n);

int main()	
{
	int num, n, opt;					// declaring variables num, options, no_of_bits(n)
	char cont;
	do
	{
		printf("Enter num :");
		scanf("%d", &num);
		printf("Enter n :");
		scanf("%d", &n);
		printf("possible operations\n1. circular right shift\n2. circular left shift");
		printf("\nEnter your choice :");				// enter chouce for left shift or right shift
		scanf("%d", &opt);

		printf("\nThe Binary form of number :");			// printing binary form of number before shifting
		for ( int i = 31; i >= 0 ; i-- )
		{
			printf("%d ", (num >> i) & 1 );
		}

		switch(opt)
		{
			case 1:						// case 1 for circular right shift
				{
					num = circular_right_shift(num, n);
					printf("\nAfter circular right shift by %d",n);
					break;
				}
			case 2 :					// case 2 for circular left shift
				{
					num = circular_left_shift(num, n);
					printf("\nAfter circular left shift by %d",n);
					break;
				}
		}

		printf("\nThe Binary form of number :");		// printing shifted Binary number
		for ( int i = 31; i >= 0 ; i-- )
		{
			printf("%d ", (num >> i) & 1 );
		}

		printf("\nDo you want to continue (y/n) :");		// asking user if he wants to continue or not
		scanf(" %c", &cont);

	} while ( cont == 'y' | cont == 'Y' ) ;				// continue if user enters 'y/Y'
	
	return 0;
}

int circular_right_shift( int num , int n )				// function definition for circular right shift
{
	num = ((~(-1 << n) & num) << (32 - n)) | ( (num >> n) & ~(-1 << 32-n)) ;		// right shift the number
	return num;
}

int circular_left_shift( int num , int n )				// function definiton after circular left shift
{
	num = ( (unsigned) (num & -1<<32-n) >> 32-n ) | (num << n) ;				// left shift the number
	return num;
}



