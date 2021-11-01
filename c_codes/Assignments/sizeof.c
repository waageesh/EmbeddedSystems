/*
Title : sizeof
Author: vaageesh
Date  : Saturday 19 September 2020 10:01:23 PM IST
*/


#include<stdio.h>

int main()
{
	printf("size of int %zu \n",sizeof(int));					// considering all data types and 
	printf("size of short int %zu \n",sizeof(short int));				// calcuting their sizes using sizeof() function
	printf("size of long int %zu \n",sizeof(long int));
	printf("size of long long int %zu \n",sizeof(long long int));
	printf("size of unsigned int %zu \n",sizeof(unsigned int));
	printf("size of unsigned long int %zu \n",sizeof(unsigned long int));
	printf("size of unsigned short int %zu \n",sizeof(unsigned short int));
	printf("size of unsigned long long int %zu \n",sizeof(unsigned long long int));
	printf("size of char %zu \n",sizeof(char));
	printf("size of signed char %zu \n",sizeof(signed char));
	printf("size of unsigned char %zu \n",sizeof(unsigned char));
	printf("size of float %zu \n",sizeof(float));
	printf("size of double %zu \n",sizeof(double));
	printf("size of long double %zu \n",sizeof(long double));
	printf("size of void %zu \n",sizeof(void));

	return 0;
}
