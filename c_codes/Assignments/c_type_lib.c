/*
Title  :  c_type_lib
Author :  Vaageesh
Date   :  Thursday 08 October 2020 02:24:37 PM IST
*/

#include<stdio.h>

int isalpha(int ch);
int isalnum(int ch);
int isascii(int ch);
int isblank(int ch);

int main()
{
	char ch,cont;
	int opt;
	do
	{
		printf("Enter the character :");			// reading character to check
		scanf("%c",&ch);
		printf("Select any option\n1 - isalpha\n2 - isalnum\n3 - isascii\n4 - isblank\n");
		printf("Enter your choice :");				// select the option to check on given character
		scanf("%d",&opt);
		switch(opt)
		{
			case 1 :					// checking entered character is alphabet(a-zA-Z) or not 
				{
					if(isalpha(ch))
					{
						printf("The character %c is an alpha characer",ch);
					}
					else
					{
						printf("The character %c is not an alpha characer",ch);
					}
					break;
				}	
			case 2 :					// checking entered character is alpha-numeric(a-zA-Z0-9) or not 
				{
					if(isalnum(ch))
					{
						printf("The character %c is an alnum characer",ch);
					}
					else
					{
						printf("The character %c is not an alnum characer",ch);
					}
					break;
				}	
			case 3 :					// checking entered character is ASCII character or not 
				{
					if(isascii(ch))
					{
						printf("The character %c is an ascii characer",ch);
					}
					else
					{
						printf("The character %c is not an ascii characer",ch);
					}
					break;
				}	
			case 4 :					// checking entered character is blank character(tab space/space) or not 
				{
					if(isblank(ch))
					{
						printf("The character %c is an blank  characer",ch);
					}
					else
					{
						printf("The character %c is not an blank characer",ch);
					}
					break;
				}	
			default :
				{
					printf("Invalid input");
				}
		}

		printf("\nDo you want to continue (y/n) :");		// asking user if he wants to continue or not
		scanf(" %c",&cont);
		getchar();
	} while( cont == 'y' || cont == 'Y' );				// continue if entered y/Y

	return 0;
}

int isalpha(int ch)			
{
	if ( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122 ) ) 	// checks [a-z] or [A-Z]
		return 1;
	return 0;
}
int isalnum(int ch)
{
	if ( (ch >= 65 && ch <= 90) || (ch >= 48 && ch <= 57) || (ch >= 97 && ch <= 122 ) )    // checks [a-z] or [0-9] or [A-Z]
		return 1;
	return 0;
}
int isascii(int ch)
{
	if ( ch >= 0 || ch <= 127 ) 					// checks whether ascii character(0-127) or not
		return 0;
	return 1;
}
int isblank(int ch)
{
	if ( ch == 9 || ch == 32 ) 					// checks for tab space or space
		return 1;
	return 0;
}
