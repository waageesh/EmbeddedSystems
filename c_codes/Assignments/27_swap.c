/*
Title  : SIZEOF macro for all data types
Author : Vaageesh
Date   : Thursday 05 November 2020 03:24:34 PM IST
*/

#include <stdio.h>
#include <stdio_ext.h>
// macro definiton for swapping 2 variables given data type
#define SWAP(t, x, y)   \
	t temp;	        \
	temp = y;	\
	y = x;		\
	x = temp;       \

int main()
{
							
	char cont;
	int menu;
	do
	{	
		printf("1. int\n2. Float\n3. Char\n4. long int\n5. Double\n6. long Double\n");
		printf("Choose data type of elements to be swapped from above :");
		scanf("%d", &menu);
		__fpurge(stdin);
		switch(menu)
		{
			case 1:
				{
					int num1, num2;
					printf("Enter the num1 :");			// read first number
					scanf("%d", &num1);

					printf("Enter the num2 :");			// read second number
					scanf("%d", &num2);

					SWAP(int, num1, num2);			// pass data type , num1 & num2 as arguments to SWAP 
										// user defined generic swapping macro 

					printf("after swapping are:\n");
					printf("num1 :%d\n", num1);			// printing after swap
					printf("num2 :%d\n", num2);
					break;				
				}
			case 2:
				{
					float num1, num2;
					printf("Enter the num1 :");			// read first number
					scanf("%f", &num1);

					printf("Enter the num2 :");			// read second number
					scanf("%f", &num2);

					SWAP(float, num1, num2);		// pass data type , num1 & num2 as arguments to SWAP 
										// user defined generic swapping macro 

					printf("after swapping are:\n");
					printf("num1 :%f\n", num1);			// printing after swap
					printf("num2 :%f\n", num2);
					break;				
				}
			case 3:
				{
					
					char num1, num2;
					printf("Enter the num1 :");			// read first number
					scanf("%c", &num1);
					
					__fpurge(stdin);				// to clear \n character on stdin
					
					printf("Enter the num2 :");			// read second number
					scanf("%c", &num2);

					SWAP(char, num1, num2);	// pass data type , num1 & num2 as arguments to SWAP user defined generic swapping macro 

					printf("after swapping are:\n");
					printf("num1 :%c\n", num1);			// printing after swap
					printf("num2 :%c\n", num2);
					break;				
				}
			case 4:
				{
					long int num1, num2;
					printf("Enter the num1 :");			// read first number
					scanf("%ld", &num1);

					printf("Enter the num2 :");			// read second number
					scanf("%ld", &num2);

					SWAP(long int, num1, num2);	// pass data type , num1 & num2 as arguments to SWAP user defined generic swapping macro 

					printf("after swapping are:\n");
					printf("num1 :%ld\n", num1);			// printing after swap
					printf("num2 :%ld\n", num2);
					break;				
				}
			case 5:
				{
					double num1, num2;
					printf("Enter the num1 :");			// read first number
					scanf("%lf", &num1);

					printf("Enter the num2 :");			// read second number
					scanf("%lf", &num2);

					SWAP(double, num1, num2);		// pass data type , num1 & num2 as arguments to SWAP 
										// user defined generic swapping macro 

					printf("after swapping are:\n");
					printf("num1 :%lf\n", num1);			// printing after swap
					printf("num2 :%lf\n", num2);
					break;				
				}
			case 6:
				{
					long double num1, num2;
					printf("Enter the num1 :");			// read first number
					scanf("%Lf", &num1);

					printf("Enter the num2 :");			// read second number
					scanf("%Lf", &num2);

					SWAP(long double, num1, num2);		// pass data type , num1 & num2 as arguments to SWAP 
										// user defined generic swapping macro 

					printf("after swapping are:\n");
					printf("num1 :%Lf\n", num1);			// printing after swap
					printf("num2 :%Lf\n", num2);
					break;				
				}
		}
		

		printf("DO you want to continue(yY/nN) :");	// asking user if he want to continue
		scanf(" %c", &cont);
	}

	while (cont == 'y' | cont == 'Y');			// continue if entered y/Y
	
	return 0;
}
