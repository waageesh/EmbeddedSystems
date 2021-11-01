/*
Title  : average by taking values from command line, stdin and environmental varaible
Author : Vaageesh
Date   : Thursday 05 November 2020 03:24:34 PM IST
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float average_stdin( int*, int);				// function prototype for calculating average of numbers taken from STDIN
float average_command_line();					// function prototype for calculating average of numbers taken from command line
float average_env_var();					// function prototype for calculating average of numbers taken from environmental variables
int custom_atoi(char* str);					// function prototype for concerting string(argument) to integer
char* custom_strtok(char* str, char delim);			// function prototype for tokenizing the string

int main(int argc, char** argv[], char** envp[])		// taking double pointers argv(for storing command line arguments) , envp(for environmental variables)
{
	int menu, num_cnt;					// menu for choosing average calculating method, num_cnt for taking no of elements for average
	float avg;
	char cont;
	do
	{
	if (argc == 1  )					// if arg count is 1, no arguments are passed, hence provide only 2 options(from scanf & environmental var)
	{
		printf("1. Scan from keyword\n2. Proceed with environment variable arguments\n");
		printf("Enter your choice\t:");
		scanf("%d", &menu);
	}
	else							// if arg count > 1, arguments passed which add one more method(average to calculate from command line arguments)
	{
		printf("1. Scan from keyword\n2. Proceed with environment variable arguments\n3. Proceed with provided command line arguments.\n");
		printf("Enter your choice\t:");
		scanf("%d", &menu);
	}
	switch(menu)						// swtich case all 3 methods of average calculation
	{
		case 1:						// case 1 for calculating from stdin read intehers using scanf
			{
				printf("Enter the total number of integers :");
				scanf("%d", &num_cnt);
				int num_arr[num_cnt];

				printf("Enter elements: ");	// storing elements into an array
				for (int i = 0 ; i < num_cnt ; i++)
				{
					scanf("%d", &num_arr[i]);
				}

				avg = average_stdin(num_arr, num_cnt);				// passing array and elements count to average_stdin function
				printf("The average of entered elements :%f\n", avg);		// printing average of scanf read elements
				break;
			}

		case 2:						// case 2 for calculating from environmental variables
			{

				char* env_arr = getenv("arr");					// getting environmental varable with name "arr"
				float avg = average_env_var(env_arr);				// passing env_arr to function and getting average value
				printf("The average of entered elements :%f\n", avg);		// printing average value
				break;
			}

		case 3:						// case 3 for calculating from command line arguments
			{
				avg = average_command_line(argv, argc);				// passing command line arguments array argv and arguments count 
				printf("The average of entered elements :%f\n", avg);		// printing average value
				break;
			}


	}

	printf("DO you want to continue (yY/nN) :");		// asking user if he want to continue
	scanf(" %c", &cont);

	} while (cont == 'Y' || cont == 'y');

	return 0;
}

float average_stdin( int* num_arr, int num_cnt)			// function definition for calculating average from stdin inputs
{
	float sum = 0;
	int i = 0;
	while(i < num_cnt)					// looping num_cnt no of times
	{
		sum = sum + *(num_arr + i++);			// cummulative addition of each element to "sum"
	}
	return (sum / num_cnt) ;				// sum / (arguments count) gives average
}

float average_command_line(char** arg_arr, int arg_cnt)		// function definition for calculating average from command line arguments
{
	float sum = 0;
	int i = 1;	
	while(i < arg_cnt)					// looping arg_cnt no of times
	{
		sum = sum + custom_atoi(arg_arr[i++])  ;	// cummulative addition of each element to "sum"	
	}
	return sum/arg_cnt;					// sum / (arguments count) gives average
}
float average_env_var(char* env_arr)
{

	int token_cnt = 0, sum = 0;
	char* delim = " ";					// defining delimter in double quotes , here its space(" ")
	char* token = strtok(env_arr, " ");
	while(token)						// loop till token is null
	{
		token_cnt++;					// increment token count when token is there
		sum = sum + custom_atoi(token);			// type cast token which string to int using custom_atoi user-defined function
		token = strtok(NULL, delim);			// get next token by passing NULL and delim
	}
	return sum / token_cnt;					// sum / (tokens count) gives average
}


int custom_atoi(char* str)					// function definition for converting string to int
{
	int num = 0, i = 1;
	int sign = 1;
	while(*str)						// loop till str is NULL
	{
		if (*str == 43 || *str == 45)			// checking string is 43 or 45( since sign modifiers +,- ascci values are 43, 45)
		{
			if (*str++ == 45)			// if str is +, make sign as -ve
				sign = sign*-1;
		}
		else if ( *str >= 48 && *str <= 57 )		// checking if str is inbetween decimal values 0-9 whose ascii values are 48 - 57
		{
			num = num*10 + ( (*str++) - 48 );	// cummulatively,  mutiplying number with 10 and adding decimal value to get number
		}
		else
			str++;					// if str is not in between 0-9 or + or -
	}
	return num*sign;					// return str along with sign
}

