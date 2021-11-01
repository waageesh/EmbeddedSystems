/*
Title  : implement printf using varaidic functions
Date   : Friday 27 November 2020 10:42:47 PM IST
Name   : Vaageesh
*/

#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<stdio_ext.h>

int my_itoa(int num1,char *s1);                            //declaration of own itoa and printf functions
int my_printf(const char * , ... );                        //variadic function declaration

int main()
{
	char ch;
	do
	{
		int i;
		char c,s[30];
		my_printf("Enter a number : ");                          //intake and printing number
		scanf("%d",&i);
		my_printf("Output : %d\n",i);

		my_printf("Enter a char : ");                           //intake and printing charecter
		__fpurge(stdin);
		scanf("%c",&c);
		my_printf("Output : %c\n",c);

		my_printf("Enter a string : ");                     //intake and printing string
		__fpurge(stdin);
		scanf("%s",s);
		my_printf("Output : %s\n",s);

		my_printf("Do you want to continue : (y/Y|n/N)");          //continue option
		scanf(" %c",&ch);
		__fpurge(stdin);
	}while( ch == 'y' | ch == 'Y' );

}
int my_printf(const char *format, ... )                       //functon definition
{
	char *s,s1[100];
	int i,j=0;
	va_list ap;
	va_start(ap,format);
	while(*format)                                        //read first argument 
	{
		if(*format=='%')                              //check for format specifier
		{
			format++;
			if(*format=='d')                        //check for integral format specifier
			{
				i=va_arg(ap,int);               //read 2nd argument 
				my_itoa(i,s1);                  //convert to integre to string
				while(s1[j]!='\0')
				{
					putchar(s1[j]);            //printing each charecter
					j++;
				}
			}
			else if(*format=='c')
			{
				i=va_arg(ap,int);                 //read argumnet if charecter format specifier
				putchar(i); 
			}
			else if(*format=='s')
			{
				if((s=va_arg(ap,char*))==NULL)         //read no argument or null string
				{
					puts("(null)");
					break;
				}
				else 
				{
					while(*s)                   //printing string
					{
						putchar(*s);
						s++;
					}
				}
			}
			else
			{
				putchar(*format);          //if not a format specifier printing charecter
			}
		}


		else
		{
			putchar(*format);

		}
		format++;                      //going to next charecter
	}
	va_end(ap);
}
int my_itoa(int num1,char *s1)                             //itoa defnition
{
	char *temp;
	temp=(char*)malloc(40);
	int l,i=0,j=0;

	while(num1%10!=0)                                //genrating string of char by adding 48 to each integer
	{
		temp[i]=(num1%10)+48;
		num1=num1/10;
		i++;
	}
	l=i-1;
	while(j<i)                                //swaping to get the exact string from above reverse string
	{

		s1[j++]=temp[l--];
	}
	return i;

}

