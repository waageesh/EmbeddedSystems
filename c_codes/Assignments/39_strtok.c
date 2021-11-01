/*
Title   : Strint Token function own-implementation
Date    : Wednesday 20 November 2020 12:19:25 PM IST
Author  : Vaageesh
*/

#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>

static char *a, tok[50];
static int j = 0, l1, l2, co = 0, c1 = 0, c2 = 0, flag = 0;

char* my_strtok(char *, char *);                   //declaration of strtok function

int main()
{
	char c;
	do
	{
	int i=0;
	__fpurge(stdin);
	char str[100], delim[100];
	char *token;
	printf("Enter string1: ");
	scanf("%[^\n]", str);             //reading string with spaces
	__fpurge(stdin);
	printf("Enter string2: ");
	scanf("%[^\n]", delim);           //reading dilemeter 
	__fpurge(stdin);
	token=my_strtok(str,delim);       //calling strtok function for first time
	while(token != NULL)
	{
		if(i == 0)
		{
			printf("Tokens :\n");
			i++;
		}
		printf("%s\n", token); 	
		token=my_strtok(NULL, delim);      //calling strtok more than once
	}
	j = 0 ; co = 0 ; c1 = 0 ; c2 = 0 ; flag = 0;
	printf("Do you want to continue :(y/Y|n/N)");
	__fpurge(stdin);
	scanf(" %c", &c);
	}while( c == 'y' || c == 'Y' );


}
char* my_strtok(char *s,char *d)                 		//function definition
{
	int x, i, k, count1 = 0, count = 0, m, n = 0, p;
	if(s != NULL) 					       //check function called for first time
	{
	a = s;
	l1 = strlen(a);
	l2 = strlen(d);
	}
	do
	{	
		if (flag == 1)
			return NULL;               		//check flag for previous element '\0'
		if(co == 0)
		{
		c2++;
     	        count1 = 0;
		

		//check for special charecters including delimiters present at first element
		if (a[j] >= 32 && a[j] <= 47 || a[j] >= 58 && a[j] <= 64 || a[j] >= 123 && a[j] <= 126 || a[j] >= 91 && a[j] <= 96 || a[j] == 9)       
		{
				
			do
			{
				for(m = 0 ; m < l1 ; m++)
				{
					a[m] = a[m+j+1];   //move the string forward if special char present
				}
				j = 0;
			}
			while(a[0] >= 32 && a[0] <= 47 || a[0] >= 58 && a[0] <= 64 || a[0] >= 123 && a[0] <= 126 || a[0] >= 91 && a[0] <= 96 || a[0] == 9); 
			//chaeck for special char at first position
		}

	      n = 0 ; 
	      j = 0;
	      do
	      {

		count = 0;
	        for(i = 0 ; i < l2 ; i++)
		{
			if(a[j] == d[i] || a[j] == '\0')                      //chaeck for delimeter or null at other locations
			{
				if(a[j] == '\0')                     //flag to end the fetch if '\0' is present
					flag = 1;
				 n = j;                             //noting location of dilemeter presence
	                 	break;
			}
			else
			{
			count++;
				if(count == l2)            //check for no  delemeter precense
				{
					n++;            //taking count of location
					j++;
				}
			}
		}
	 	
              	   
             }while(count == l2);                //loop if no dilemeter
	     co = 1;
	     for(p = 0 ; p < l1 ; p++)           //storing 0 in all locations of tok[]
		{
			tok[p]=0;
		}
    	     for(p = 0 ; p < n ; p++)            //storing array in tok[] till dilemeter
	     {
		tok[p] = a[p];
	     }
	    
	}

	if(s == NULL && c1 == 0)              //condition to skip first run for second call of strtok with NULL
	{
		co = 0;
		c1 = 1;
	}
	else if(s == NULL && c2 > 1)         //for repeated call of strtok with NULL
	{
		co = 0;
		c2 = 1;
		return tok;
	}

	}while(s == NULL);              //looping for strtok run for second time  

	return tok;
}

