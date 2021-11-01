/*
Title  : all possible string combinations
Date   : Friday 27 November 2020 10:42:47 PM IST
Name   : Vaageesh
*/


#include<stdio.h>
#include<string.h>
void comb(char*,int,int);         //declaration fo permutaion function and swap function
void swap(char*,char*);
int main()
{
	int l,i,j;
	char *s,temp;
	printf("Enter String :");        
	scanf("%ms",&s);
	l=strlen(s);
	for(i=1;i<l-1;i++)               //intake of string
        {
                for(j=i;j<l-1;j++)
                {
                        if(s[i]>s[j+1])
                        {
                                temp=s[i];          //swaping to for alphabetic order
                                s[i]=s[j+1];
                                s[j+1]=temp;

                        }
                }
        }
        comb(s,0,l-1);             //calling permutation function
}
void comb(char *s,int n,int l)
{
	int i;

	if(n==l)
	{
		printf("%s\n",s);                   //condition for reaching end of each permutation possible like 'adc'
	}
	else
	{
		for(i=n;i<=l;i++)
		{
			swap(&s[n],&s[i]);          //swaping string elements from latest stirng available
			comb(s,n+1,l);              //recall of function till end of element count
			swap(&s[n],&s[i]);          //swaping elements after function call is completed and loop till i<=l
		}
	}
}
void swap(char *a,char *b)                  //swap function defnition
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

