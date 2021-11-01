/*
Title  : Processor Endianess
Author : Vaageesh
Date   : Friday 12 November 2020 03:19:46 PM IST 
*/

#include <stdio.h>

int main()
{
	unsigned int i = 1;	
	char* cptr = (char*)&i;					// typecasting to char pointer to get fitst
								
	
	if (*cptr)						// if memory read is from LSB, then *cptr will give 01 as value
	{
		printf("processor is Little endian\n");
	}
	else							// if memory read is from MSB, then *cptr will give 00 as value
	{
		printf("processor is Big endian\n");
	}
}
