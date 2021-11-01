/*
Title   : Demote Float to int
Date    : Wednesday 20 November 2020 12:14:22 PM IST
Author  : Vaageesh
*/

#include<stdio.h>
typedef union flo                                //union defnition 
{
	float floa;
	struct one                              //structure to have float number into its partitions
	{
		unsigned int mantisa :23;
		unsigned int expo    :8; 
		unsigned int sign    :1;   	
	}one;
}flo;

int main()                                      
{
	char cont;
	do
	{
		flo f;
		int x = 0, sign = 0, nbit = 0, mask = 0, new = 0;
		printf("Enter float value:");					//intake of float input
		scanf("%f", &f.floa);
	
		sign = f.one.sign;						//fetching sign from structure
		x = f.one.expo;                         				//fetching exponent value form structure
		nbit = x - 127;

		mask = ( ~(~0 << nbit)) << (23 - nbit);           			//creating mask according to exponent value 

		if(sign == 1)                            				//check for negative input
		{
			if(nbit < 0)
				printf("Demoted number is : %f\n", 0.0);         //output for 0...float input
			else                                           		 //output for value > zero 
				printf("Demoted number is : -%f\n", (float)((1 << nbit) | ((f.one.mantisa & mask) >> (23 - nbit))));
		}
		else
		{
			if(nbit<0)                                    		//printing of +ve 0 values
				printf("Demoted number is : %f\n", 0.0);
			else                                           		//printing demoted +ve float
				printf("Demoted number is : %f\n", (float)((1 << nbit) | ((f.one.mantisa & mask) >> (23 - nbit))));
		} 
		printf("Do you want to continue : (y/Y|n/N) ");
		scanf(" %c",&cont);
	}while( cont == 'y' || cont == 'Y');
}
