
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<stdio_ext.h>
#define MAXLEN 255
#define MAXVAL 2000000
#define MINVAL -2000000
void NRPSstring(char str[],int len,int k);                         //function declaration
int main()
{
	int n,k,i,j;                                               //declaration of variables
	char kdistinct[MAXLEN];
	char ch;
	do
	{
		printf("Enter the number character C : ");
		scanf("%d", &k);
		if ((k < 1) || (k > 10))                             //error check for limit
		{
			printf("Invalid numbeer\n");
			return 1;
		}
		printf("Enter the length of the string : ");
		scanf("%d", &n);
		if ((n < MINVAL) || (n > MAXVAL))
		{
			printf("Invalid Number \n");
			return 1;
		}
		printf("Enter the %d distinct characters : ", k);
		for (i = 0;i < k;i++)
		{
			scanf("\n%c", &kdistinct[i]);
		}
		for (i = 0;i < k;i++)
		{
			for (j = (i + 1);j < k;j++)
			{
				if (kdistinct[j] == kdistinct[i])            //check for distict characters
				{
					printf("Values are not distinct");
					return 1;
				}
			}
		}
		printf("Possible NRPS is : ");
		NRPSstring(kdistinct, n, k);                               //function calling
		__fpurge(stdin);                                           //clears previous buffer
		printf("\nDo you want to continue (y/n) : ");                   //continue option from the user
		scanf("%c", &ch);
	}while (ch == 'y' || ch == 'Y');
	return 0;
}
void NRPSstring(char str[],int len,int k)                                  //function definition
{
	int i,val = 0,count = 0;
	for (i = 0;i < len;i++)
	{
		if (i % k == 0 && i != 0)
		{
			val++;
		}
		printf("%c",*(str + ((i + val) % k)));
	}
}


