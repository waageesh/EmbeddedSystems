/*
Title  : implementation of squeeze() alternative function 
Author : Vaageesh
Date   : Sunday 15 November 2020 06:17:49 PM IST
*/

#include <stdio.h>
#include <stdio_ext.h>

void remove_sub_string(char* string, char* sub_string);			// function prototype for squeezing string with given sub-string

int main()
{
	char* string;							// pointers for string & sub-string
	char* sub_string;	
	char cont;
	do
	{	
		__fpurge(stdin);					// clearing previous stdin
		printf("Enter string :");						
		scanf("%m[^\n]", &string);				// reading string
		__fpurge(stdin);					// clearing stdin after reading string, since %m allocates malloc memory
		printf("Enter string2 :");						
		scanf("%m[^\n]", &sub_string);				// reading sub-string

		remove_sub_string(string,sub_string);			// calling sub_string remove function
		printf("After squeeze :");
		while (*string)
		{
			if (*string == '\n')				// if char matches '\n', skips to next char
			{
				*string++;
				continue;
			}
			else						// if char != '\n' , then print the char and increment it
			{
				putchar(*string++);
			}

		}
		printf("\nDo you want to continue (yY/nN) :");
		scanf(" %c", &cont);

	} while (cont == 'Y' || cont == 'y');
	return 0;
}

void remove_sub_string(char* string, char* sub_string)			// function definition for removal of sub-string
{   
	char* sptr;								// declaring string pointer locally
	while(*sub_string)							 
	{
		char* sptr = string;						// assigning base address of string to local string pointer 
		while(*string)
		{
			if (*sub_string == *string)					// if sub-string's char matches with string's char
			{
				*string = '\n';						// replace matched char with '\n'
			}
			string++;							// moving string to next char
		}
		string = sptr;							// re-assigning string to base-address of string
		sub_string++;							// moving to next char in sub-string
	}
}


