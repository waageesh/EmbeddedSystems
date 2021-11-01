/*
Title  :  word_char_line_count_command
Author :  Vaageesh
Date   :  Friday 16 October 2020 11:52:49 PM IST
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

void remove_spaces(char* line);     // function prototype for space removal in given string

int main()
{

	char cont;
	do 
	{
		char* line = malloc(1024);  // dynamic memory allocation for input string
		__fpurge(stdin);            // clear the previous stdin screen

		printf("Enter the string with more spaces in between two words :\n");
		fgets(line, 1024, stdin);    // getting line from stdin and storing in str

		printf("string after removal of spaces :\n");
		remove_spaces(line);        // calling function for spaces removal

		printf("Do you want to continue (yY / nN) :");      // asking user if he want to continue or not
		scanf("%c", &cont);
		free(line);                                         // free the dynamic memory allocated for string 

	} while ( cont == 'Y' || cont == 'y' );             // continue if entered y/Y

	return 0;
}

void remove_spaces(char* line)  // function definition for removing spaces
{
	int cnt = 0;                
	while (*line)	           	// terminating when entered ch is EOF(CTRL+D)
	{
		if (*line == 32)		// if characer is space
		{
			cnt++;				// for every space, increment the count
		}
		else if (*line == 9)	// for every tab space(4 spaces), increment count to 4
		{
			cnt = cnt + 4;
		}
		else
		{
			if (cnt > 0)		// if count > 0 , there are 1 or more spaces
			{
				putchar(32);	// print one space and next character
			}
			putchar(*line);
			cnt = 0;			// resetting count to 0 to count next upcoming spaces ot tab sapces
		}
		line++;
	}

}


