/*
Title : even_or_odd
Author: vaageesh
Date  : Saturday 19 September 2020 10:01:23 PM IST 
*/


#include<stdio.h>
#include<stdio_ext.h>
#include<math.h>
int main()
{

	int num;
	char cont;
	do{
		printf("Enter the value of n :");
		scanf("%d",&num);					// taking number for even-odd check

		if (num < 0)						// if -ve number is passed
		{
			if (num%2 == 0)					// checking even number
				printf("%d is -ve even number",num);
			else						// checking odd number
				printf("%d is -ve odd number",num);
		}
		else if(num>=0 && num<pow(2,20))				// checking given number within range(200000) or not
		{
			if (num == 0)
				printf("%d is +ve number",num);
			else if (num%2 == 0)					// checking even number
				printf("%d is +ve even number",num);
			else						// checking odd number
				printf("%d is +ve odd number",num);
		}
		else							
		{
			printf("Number out of Range");
		}


		__fpurge(stdin);					// clearing previous given values in STDIN
		printf("\nDo you want to continue(y/n) :");		// taking user input for continuing
		scanf(" %c",&cont);


	}
	while(cont=='y');						// loop continues if 'y' prompt given
	return 0;
}


