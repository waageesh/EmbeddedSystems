/*
Title  :  word_char_line_count_command
Author :  Vaageesh
Date   :  Thursday 14 October 2020 02:24:37 AM IST
*/


#include <stdio.h>

int main()
{
	char prev = 0;						// prev to store prev character
	char ch = getchar();					// ch to store current character
	int line_cnt = 0, word_cnt = 0, char_cnt = 0;		// intializing word,char,line counting variables to 0
	
	while ( ch != EOF )					// reading characters till EOF charcter encounters
	{
		char_cnt++;					// counting character
		if (ch == '\n')					// line count , for every new line charaacter
		{
			line_cnt++;
			prev = ch;				// storing new line in prev
			ch = getchar();				// reading new characer in next line
			continue;				
		}

		if (ch == ' ' || ch == '\t')			// checking character either space or tab space
		{
			prev = ch;				// storing space or tab in prev character
		}
		else if ( (ch != ' ' || ch != '\t') && ( prev == ' ' || prev == '\t' || prev == '\n' || !prev ) )
		{						// if character is non-empty and prev is either space or tab or newline or nothing
			word_cnt++;				// then a word is there , count that word by incrementing
			prev = ch;
		}
		
		ch = getchar();					// read next char 

	}

	printf("\nchar count :%d\nword count :%d\nlines count :%d\n", char_cnt, word_cnt, line_cnt);	// printing char, word, line count
	putchar(ch);						// printing EOF to terminate program
	return 0;
}
