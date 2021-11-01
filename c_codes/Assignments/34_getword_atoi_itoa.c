#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

int getword(char* str);
int custom_atoi(const char* str);
int custom_itoa(int n, char* str);

int main()
{
	int menu;
	char cont;
	do
	{
		printf("1. getword\n2. atoi\n3. itoa\n");
		printf("Enter the option to continue :");
		scanf("%d", &menu);

		switch(menu)
		{
			case 1 :
				{
					int first_word_len ;                                       
					char* str = (char*)malloc(sizeof(char)*100);                // Dynamic memory allocation for str pointer
					printf("Enter a word :");
					__fpurge(stdin);
					fgets(str, 100, stdin );                                   // reading string from stdin to ptr, starting from ptr Base Address
					first_word_len = getword(str);                             // calling getword function to get first token length
					printf("you entered :%s\n", str);
					printf("length of first word :%d\n", first_word_len);      // printing token length
					break;		
				}
			case 2 :
				{	
					char* str = (char*)malloc(sizeof(char)*100);                // Dynamic memory allocation for str pointer
					int str_num;
					printf("Enter a numeric string :");
					scanf("%s", str);
					str_num = custom_atoi(str);
					printf("string to num :%d\n", str_num);
					break;
				}
			case 3 :
				{
					char* str = (char*)malloc(sizeof(char)*100);                // Dynamic memory allocation for str pointer
					int num, string_len;
					printf("Enter a numeric string :");
					scanf("%d", &num);
					string_len = custom_itoa(num, str);
					printf("string to num :%s\n", str);
					printf("lenght of the string :%d\n", string_len);

					break;
				}

		}

		printf("Do you want to continue (yY/nN) :");
		scanf(" %c", &cont);
	}

	while (cont == 'Y' || cont == 'y') ;

}

int getword(char* str)
{
	int len = 0;
	char prev = *str;               // initializing prev to string base address

	while(*str)
	{
		if (*str == 32 )            // checks for spaces
		{
			if (prev == 32)         // checks for spaces before 1st occurence of alphabet
			{  
				*str++;
				continue;
			}
			else                    // if prev is non-space character & curr character is space then break loop
			{
				*str = '\0' ;
				break;
			}
		}
		else                        // if curr char is not space, move prev to curr char and curr char is incremented
		{
			prev = *str;            // changing prev to curr char
			len++;                  // incrementing the length of word
			*str++;                 // incrementing the cuu char
		}
	}
	return len;
}

int custom_atoi(const char* str)					// function definition for converting string to int
{
	int num = 0, i = 1;
	int sign = 1;
	char prev;
	char* ptr = (char*)str;
	while(*ptr)						// loop till str is NULL
	{
		if (*ptr == 43 || *ptr == 45)			// checking string is 43 or 45( since sign modifiers +,- ascci values are 43, 45)
		{
			if ( (*ptr == 43 || *ptr == 45) && (*(ptr+1) == 43 || *(ptr+1) == 45) )
			{
				return 0;
			}
			else
			{
				prev = *ptr;
				if (*ptr++ == 45)			// if str is +, make sign as -ve
				{
					sign = sign*-1;
				}
			}
		}
		else if ( *ptr >= 48 && *ptr <= 57 )		// checking if str is inbetween decimal values 0-9 whose ascii values are 48 - 57
		{
			prev = *ptr;
			num = num*10 + ( (*ptr++) - 48 );	// cummulatively,  mutiplying number with 10 and adding decimal value to get number
		}
		else                    // if str is not in between 0-9 or + or -
		{
			if ( !( (prev >= 48 && prev <= 57) || (prev == 43) || (prev == 43) ) )              // checking prev for 0-9 or + or -
			{
				if (!( (*ptr >= 48 && *ptr <= 57) || (*ptr == 43) || (*ptr == 43) ) )	    // checking ptr for 0-9 or + or -
				{
					if (num)							    // if num is there, then return num
					{
						return num;
					}
					else								   // if its first occurence after non-alphabets or +/-, then return 0
					{
						return 0;
					}
				}
			} 
			prev = *ptr;			// assing curr char to prev
			ptr++;				// incrementing curr char						
		}	
	}
	return num*sign;					// return str along with sign
}


int custom_itoa(int n, char* str)				// function definition for custom_itoa
{
	int string_len = 0;					// string_len to calculate string passed 
	int size = 0, temp = n;					// temp to loop thorugh the each charfacter in numeric string
	while(temp)						// looping till temp becomes 0
	{
		temp = temp/10;
		size++;
	}
	*(str+size--) = '\0';					// assigning last character of string as null
	while(n)						// looping through number
	{
		temp = n % 10;					// getting last digit eveytime and storing in reverse order of string array
		*(str+size) = temp+48;				// adding 48 to change it corresponding decimals ASCII value
		n = n / 10;					// decrementing number to get next char
		string_len++ ;					// incrementing string_len for calculating string len, decrementing size to move to before index of string
		size--;
	}

	return string_len;					// return string len
}

