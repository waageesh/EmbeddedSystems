/*
Title  : 2s_Compliment
Author : Vaageesh
Wednesday 30 September 2020 04:12:59 PM IST
*/

#include <stdio.h>
#include <math.h>

int main() 
{
	int num,index;                  				// declaring num and index variables
	char cont;                      			// declaring continue variable
	do
	{   
		index = 0;        	           	 		//initializing with 0 to avoid garbage value
		printf("enter the n :");
		scanf("%d", &num);       	      			// take 'n' to print prime numbers <=n
		if (num > pow(2,20) )
		{
			printf("Number out of range");
		}
		else if (num < 0)
		{
			printf("Invalid input");
		}
		else
		{
			int A[num];
			for(int i = 2;i <= num;i++)
			{
				A[i] = i;               			//initializing ith index of array with value 'i'
			}

			for(int i = 2;i <= (int)sqrt(num);i++)	            	// loop till half of the sqrt(n)
			{
				for(int j = 2;j <= num;j++)				// loop to get all multiples of i
				{
					index = i*j;                        	// getting mutiples of i and storing as index

					if (index <= num && A[index] != 0)      	// index value shouldn't cross given number  
					{                                   	//      and it shouldn't be filled already with 0
						A[index] = 0;                   // making index as 0, which indicates it not prime
					}
					else                                
						if (index > num)                // if index crosses given number
						{
							break;                  // then go for next number, by breaking inner loop
						}
						else                            
							continue;               // if index < number, then go for next iteration
				}
			}


			for(int i = 2;i <= num;i++)
			{
				if (A[i] != 0)                          	// checking if prime based on flag 0/1
				{
					printf("%d ",A[i]); 	                // print the prime number(flag-1)
				}

			}

		}

		printf("\nDo you want to continue(y/n) :");		// asking user to continue or not
		scanf(" %c", &cont); 

	} while(cont == 'y');                           	// if user given 'y', repeat the process

	return 0;
}
