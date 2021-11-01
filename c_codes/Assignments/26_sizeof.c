/*
Title  : SIZEOF macro for all data types
Author : Vaageesh
Date   : Thursday 05 November 2020 03:24:34 PM IST
*/

#include <stdio.h>
#define SIZEOF(x)  (int)((char*)(&x+1)-(char*)&x)   // defining macro for sizeof operator
						
						   // char* byte size is 1, and block size is also 1, so type cast address to char*
						   // when use int* , block size is 4, byte size is 1 so when we do (&x+1) - &x, difference between blocks is 1
int main()
{
	int i1;                                     // declaring variables of all possible data types
	short int i2;
	long int i3;
	long long int i4;
	unsigned int i5;
	unsigned long int i6;
	unsigned short int i7;
	unsigned long long int i8;
	char c1;
	signed char c2;
	unsigned char c3;
	float f1;
	double f2;
	long double f3;
	void* v1;

	printf("size of int %u \n", SIZEOF(i1));                        // calling SIZEOF macro for all delcared variables above
	printf("size of short int %u \n", SIZEOF(i2));
	printf("size of long int %u \n", SIZEOF(i3));
	printf("size of long long int %u \n", SIZEOF(i4));
	printf("size of unsigned int %u \n", SIZEOF(i5));
	printf("size of unsigned long int %u \n", SIZEOF(i6));
	printf("size of unsigned short int %u \n", SIZEOF(i7));
	printf("size of unsigned long long int %u \n", SIZEOF(i8));
	printf("size of char %u \n", SIZEOF(c1));
	printf("size of signed char %u \n", SIZEOF(c2));
	printf("size of unsigned char %u \n", SIZEOF(c3));
	printf("size of float %u \n", SIZEOF(f1));
	printf("size of double %u \n", SIZEOF(f2));
	printf("size of long double %u \n", SIZEOF(f3));
	printf("size of void %u \n", SIZEOF(v1));
	return 0;
}

