/*
Title  :  swap_using_pass_by_reference_without_temp
Author :  Vaageesh
Date   :  Thursday 08 October 2020 02:24:37 PM IST
*/

#include<stdio.h>

void swap(int* num1, int* num2);			// function declaration/prototype

int main()
{
	int num1,num2;					// declaring num1, num2 variables
	char cont;					
	do	
	{
		printf("Enter N1 :");			// read number1, number2 from user
		scanf("%d",&num1);
		printf("Enter N2 :");
		scanf("%d",&num2);
		swap(&num1, &num2);			// call swapping function
		printf("after swapping,\n");
		printf("N1 = %d\nN2 = %d", num1, num2);		// print after swapping

		printf("\nDo you want to continue(y/n) :");	// ask user if he wants to continue or not
		scanf(" %c", &cont);
	} while ( cont == 'Y' |  cont == 'y' ) ;		// continue if entered Y/y
	return 0;
}

void swap (int* num1, int* num2)				// function definition for swapping variables
{
	*num1 = *num1 ^ *num2 ;					// swap logic using pointers
	*num2 = *num1 ^ *num2 ;
	*num1 = *num1 ^ *num2 ;
}

