/*
Title  : String reverse using recursive or iteration
Author : Vaageesh
Date   : Friday 13 November 2020 01:04:45 AM IST
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

void string_reverse_recursive(char *str);		// function prototypes for recursive and iterative string reverse functions
void string_reverse_iteration(char* str);

int main()
{
	int menu;
	char cont;
	do 
	{
		__fpurge(stdin);			// clearing previous stdin screen
		char* str;
		printf("Enter a string :");
		scanf("%m[^\n]", &str);			// reading entire string till newline(\n) character is encountered, 
							// m in between % and s is to create memory of length of given string, 
							// and [^\n] is to tell scanf read till delimiter \n is encounterd
							// this is shortcut for reading string of unknown length, where 
							// we dont know how many bytes should we allocate, 
							// either for static or dynamic memory allocation
		printf("Enter string reverse or recursive :\n1. Recursion\n2. Iteration\nChoose option :");
		scanf("%d", &menu);			// reading menu for string reverse method for recursive or iterative
		if (menu == 1)
		{
			string_reverse_recursive(str);	
			printf("\n");
		}
		else if (menu == 2)
		{
			printf("string is %s\n", str);
			string_reverse_iteration(str);
			printf("\n");
		}

		printf("Do you want to continue (yY/nN) :");		// asking use if he want to continue or not
		scanf(" %c", &cont);

	} while (cont == 'y' || cont == 'Y');				// continue if he entered y/Y
}
void string_reverse_recursive(char *str)		// string reverse using recursion function definition
{
	if(*str == '\0')				// if character is null, terminate the recursive call
		return;
	string_reverse_recursive(str+1);		// else, recursive call with pointer pointing to next address
	printf("%c",*str);				// printing character backawards from last stack frame, when recursive call terminates at \0
}

void string_reverse_iteration(char* str)			// string reverse method using iteration
{
	for(int i = strlen(str) - 1 ; i >= 0; i--)    	 	// starting from last index ,and decrementing index to find pointer value in reverse
        {
            printf("%c", *(str+i) );				// printing curr character
        }
}
