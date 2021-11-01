/*
Title  : user defined read_int functon to read integers, alternative to scanf()
Author : Vaageesh	
Date   : Tuesday 03 November 2020 02:52:12 PM IST 

*/

#include<stdio.h>
#include<stdio_ext.h> 							// header file for __fpurge to clear stdin for next cycle

void read_int(int* num);						// function prototype for scanf alternative user-defined function
int main()
{
	int num;							
	char cont;							
	do
	{
		__fpurge(stdin);					// cleaning previous stdin screen to take new number
		printf("Enter the number :");
		read_int(&num);						// passing anumber from stdin as argument to read_int function 
		printf("Entered number is:%d", num);			// printing entered number
		printf("\nDo you want to continue(yY/ Nn) :");		// asking user if he wants to continue or not
		scanf(" %c", &cont);					
	} while (cont == 'Y' || cont == 'y');				// continue if entered y/Y
}

void read_int(int* num)							// function definiton for reading integers
{
	*num = 0;
	char ch,prev_ch;						// defining current and previous character
	int sign = 1;							// declaring and intializing sign with 1 to decide sginedness of the number
	while( (ch = getchar()) != '\n')				// reading character from STDIN and checking if its end of the line
	{
		if (prev_ch == '-' && ch >= 48 && ch <= 57 )		// if prev char is minus(-) and curr char is number, assign -1 to sign
		{
			sign = sign * -1;
		}
		if ( ch >= 48 && ch <= 57 )				// check curr car is number or not
		{	
			*num = *num * 10 + ( (int)ch - 48);		// adding to previous number , int(ch) should be subtracted with 48 to get 
									// corresponding digit 
		}
		prev_ch = ch;						// moving prev char to curr char and curr char to next char 
	}
	*num = *num * sign ;						// return number along with sign
}
