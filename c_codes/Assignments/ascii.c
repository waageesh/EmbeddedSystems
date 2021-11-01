/*
Title : ascii
Author: vaageesh
Date  : Saturday 19 September 2020 10:01:23 PM IST
*/



#include<stdio.h>

int main()
{
	printf("Dec\tOct\tHex\tAscii\n");				// generating header for ascii table
	printf("---------------------\n");
	for (int i=0;i<128;i++)
	{
		if ( (i>=0 && i<=32) || i==127)				// checking non-printable ascii character
		{
			printf("%d \t %03o \t %02X \t Not Printable\n",i,i,i);
		}
		else
			printf("%d \t %03o \t %02X \t %c\n",i,i,i,i);		// printing printable ascii value
	}

}
