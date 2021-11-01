/*
Title  : implement printf using varaidic functions
Date   : Friday 27 November 2020 10:42:47 PM IST
Name   : Vaageesh
*/



#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

int my_scanf(const char *format , ... );		//declaring variadic function

int main()
{
	char c;
	do
	{
		int num;
		char ch,ch1,ch2,*st;
		float f;
		double d;
		
		st=(char*)calloc(100,1);                                     //memory allocation to string
		printf("Enter number : ");
		
		my_scanf("%d",&num);
		printf("You entered : %d\n",num);                            //prompting all types of inputs and reading them
		
		printf("Enter charecter : ");
		my_scanf("%c",&ch);
		printf("You entered : %c\n",ch);
		
		__fpurge(stdin);                                        //fpurge to clear buffer as we need to read char
		
		printf("Enter string : ");
		my_scanf("%s",st);
		printf("You entered : %s\n",st);
		
		printf("Enter float :" );
		my_scanf("%f",&f);
		printf("You entered : %f\n",f);
		
		printf("Enter double : ");
		my_scanf("%lf",&d);
		printf("You entered : %lf\n",d);

		printf("Do you want to continue : (y/Y|n/N) ");                     //continue option
		my_scanf(" %c",&c);
		__fpurge(stdin);
	}while( c == 'y' | c == 'Y' );
}
int my_scanf(const char *format , ... )					//defnition
{
	char *str,c[100],*end;
	int i=0,count=0;
	str=(char*)calloc(100,1);                              //memory allocation 
	va_list ap;                                          //declaring varidic function argument pointer
	va_start(ap,format);

	while(*format)                                      //reading first argument
	{ 
		count++;
		if(*format==' ')
		{
			__fpurge(stdin);
			format++;
		}
		if(*format=='%')                           //check for format specifier
		{
			i=0;
			format++;
			if(*format=='d'||*format == 'i')                    //check for integer specifier
			{
				if(*format=='d'||*format=='i')
				{
					while((c[i]=getchar())!='\n')         
					{
						i++;                        //getting charecter strng
					}
					c[i]='\0';                            
					*(int*)va_arg(ap,int*)=atoi(c);   //converting string to integer and storing in argument
				}
			}
			else if(*format=='l')              //check fo specifiers with %l
			{
				format++;
				if(*format=='d'||*format=='i'||*format=='u'||*format=='f')
				{
					if(*format=='d'||*format=='i')
					{
						while((c[i]=getchar())!='\n')
							i++;
						c[i]='\0';
						*(long int*)va_arg(ap,long int*)=atol(c); //convert to long and assign
					}
					else if(*format=='u')
					{
						while((c[i]=getchar())!='\n')
						{
							i++;
						}
						c[i]='\0';                           //convert string to long
						*(unsigned long int*)va_arg(ap,unsigned long int*)=strtoul(c,NULL,10);
					}
					else if(*format=='f')
					{
						while((c[i]=getchar())!='\n')
						{
							i++;
						}
						c[i]='\0';                           //convert string to float and assign
						*(double*)va_arg(ap,double*)=atof(c);

					}
				}
				else if(*format=='l')           //check for specifier with %ll
				{
					format++;
					if(*format=='d'||*format=='i')
					{
						while((c[i]=getchar())!='\n')
							i++;
						c[i]='\0'; 
						*(long long int*)va_arg(ap,long long int*)=atoll(c);
					}
					else if(*format=='u')
					{
						while((c[i]=getchar())!='\n')
							i++;
						c[i]='\0';
						*(unsigned long long int*)va_arg(ap,unsigned long long int*)=strtoull(c,NULL,10);
					}
				}
				else
				{
					while((c[i]=getchar())!='\n')
						i++;
					c[i]='\0';
					*(long int*)va_arg(ap,long int*)=atol(c);
				}		
			}
			else if(*format=='u')             //check for unsigned specifer
			{	
				while((c[i]=getchar())!='\n')
				{
					i++;
				}
				c[i]='\0';
				*(unsigned int*)va_arg(ap,unsigned int*)=strtoul(c,NULL,10);
			}
			else if (*format=='s')                      //chaeck for string specifier
			{
				while((c[i]=getchar())!='\n'&&c[i]!=' ')
				{
					i++;
				}
				c[i]='\0';
				str=(char*)va_arg(ap,char*);
				strcpy(str,c);                            //copy string to argumnet
			}
			else if (*format=='c')                   //specifier for char
			{
				c[i]=getchar();
				*(char*)va_arg(ap,char*)=c[i];
			}
			else if (*format=='f'||*format=='L')              //specifier for float and long double
			{
				if(*format=='f')
				{
					while((c[i]=getchar())!='\n')
					{	
						i++;
					}
					c[i]='\0';                              //convert to float and assign 
					*(float*)va_arg(ap,float*)=atof(c);
				}
				else if(*format=='L')                  // for long double
				{
					format++;
					if(*format=='f')
					{
						while((c[i]=getchar())!='\n')
						{
							i++;
						}
						c[i]='\0';
						*(long double*)va_arg(ap,long double*)=atof(c);
					}
				}
			}
		}
		else
		{

			if(*format!=' ')  //to remove first space
				puts("\n");
		}
		format++;                 //next charecter in first argument
	}
	va_end(ap);
}
