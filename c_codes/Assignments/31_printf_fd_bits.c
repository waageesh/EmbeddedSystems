/*
Title   : IEEE std printing of floating point conversion
Author  : Vaageesh
Date    : Monday 09 November 2020 01:13:02 AM IST
*/

#include <stdio.h>

void print_binary(int num, int bits_cnt);				// function prototype for printing binary format of given number

int main()
{

	float num;							
	char cont;
	do
	{
	int mantissa_size, exponent_size, menu;				// variables for mantissa_size, exponent_size
	printf("Enter the Choice:\n1. float\n2. double\nChoice :");
	scanf("%d", &menu);						// reading choice from user for single/double point conversion
	printf("Enter the float value :");
	scanf("%f", &num);						// reading float value

	if (menu == 1)							// setting mantissa_size, exponent_size for single point conversion
	{
		mantissa_size = 8;
		exponent_size = 23;
	}
	else if (menu == 2)						// setting mantissa_size, exponent_size for single point conversion
	{
		mantissa_size = 11;
		exponent_size = 52;
	}
	
	float temp = num;				// defining temp variable for getting exponent value from value after decimal part
	int num_int = (int)num;				// getting decimal value from given float value

	int size = 31;
	int arr[size+1] ;
	int length = 0, sign;
	int first, mantissa;				// lenght to calculate bias, mantissa to store mantissa value

	if (num > 0 )					// if num is +Ve, sign bit is 0
	{
		sign = 0;
	}
	else						// if num is -ve, sign bit is 1
	{
		sign = 1;
	}

	for(int i=0; i<32; i++ )			// intializing entire array with values 0
	{
		arr[i] = 0;
	}
	while(num_int)					// storing binary format of numeric part of given float number into an array
	{
		arr[size] = num_int % 2;		// getting bit everytime by getting remainder 
		num_int = num_int/2;			// going for next value by dividing with 2
		length++;				// inceementing lenght to get binary format lenght and decrementing size to move next element in binary fomrat
		size--;
	}



	for (int i = 0; i <= 31 ; i++)			// getting first occurence of 1 and marking it as "first", which is used for calculating bias
	{
		if ( arr[i] == 1 )			// if first occurence bit 1 is occured, store the index to "first" and 	break the loop
		{
			first = i ;
			break;
		}
	}
	mantissa = 127 + (31 - first);			// caculating bias value

	printf("sign\tmanitssa\t\tExponent\n");
	printf("\n----------------------------------------------------------------------------------------\n");

	printf("%d \t",sign);			
	print_binary(mantissa, mantissa_size);		// printing mantissa by calling print_binary function for mantissa
	printf("\t");

	for (int i = first+1; i <= 31 ; i++)		// printing value after shiting decimal point to make scientific conversion (1.0 * 2^exp)
	{
		printf("%d ", arr[i]);			
	}
	for (int i = 0 ; i < exponent_size ; i++)	// printing exponent bits from floating part of given float number
	{
		temp = temp - (int)temp;
		temp  = temp * 2;
		printf("%d ", (int)temp); 
	}

	printf("\nDo you want to continue (yY/nN) :");
	scanf(" %c", &cont);
	
	} while (cont == 'y' || cont == 'Y');


	return 0;
}

void print_binary(int num, int bits_cnt)
{
	for (int i = bits_cnt ; i > 0 ; i--)
	{
		if ( (num >> i)&1 == 1 )		// checking if bit is 1 
		{
			printf("1 ");
		}
		else					// checking if bit is 0
		{
			printf("0 ");
		}
	}
}

