/*
Title  : Binary search for all data-types
Date   : Friday 27 November 2020 08:00:01 PM IST
Author   : Vaageesh
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>

int one(const void *,const void *);                         //decalration of functons for all data types
int two(const void *,const void *);
int three(const void *,const void *);
int four(const void *,const void *);

int main(int argc,char *argv[])
{
	char c1;
	do
	{
		__fpurge(stdin);					// clearing previous stdin screen
		int ch, n, i, l1;
		void *a,*x;
		if(!(argv[1]))						// checking command line arguments are provided are not
		{
			printf("Error: No command line argument\n");
			return 0;
		}

		printf("Select data type :\n1.Int\n2.Char\n3.Float\n4.Double\n");     //prompt options available
		printf("Enter choice :");
		scanf("%d", &ch);
		n = atoi(argv[1]);                                      // converting command line argument from string to int
		switch(ch)
		{
			case 1:						// case for binary search of int 
				{ 
					a=(int*)calloc(n, sizeof(int)); 				//allocating memory and intake of elemets
					printf("Enter %d elements of type int : ", n);           
					for(i = 0 ; i < n ; i++)
					{
						scanf("%d", (int*)(a + (i*sizeof(int))) );
					}
					qsort(a, n, sizeof(int), one);                          //using qsort to sort all elements
					puts("After sorting:\n");
					for(i = 0 ; i < n ; i++)
					{
						printf("%d\n", *(int*)(a + (i*sizeof(int))) );            //printing after sort
					}
					puts("Enter key element to search :");
					scanf("%d", (int*)x);                       //typecasting void pointer to intake element to search 
					for(i = 0 ; i < n ; i++)
					{
						if(*( (int*)(a + (i * sizeof(int))) ) == *(int*)x)               //printing search result
						{ 
							printf("the element is present at position %d \n",i);
						}
						else
						{
							printf("the element is not present at position %d \n",i);
						}
					}
					break;
				}
			case 2:						// case for binary search of char
				{
					a = (char*)calloc(n, sizeof(char));                       //search process for char elements
					printf("Enter %d elements of type char : ", n);
					for(i = 0 ; i < n ; i++)
					{
						__fpurge(stdin);                               //fpurge to clear buffer
						scanf("%c", (char*)(a + (i*sizeof(char))) );
					}
					qsort(a, n , sizeof(char), two);
					for(i = 0 ; i < n ; i++)
					{
						printf("%c\n", *(char*)(a + (i*sizeof(char))) );
					}
					puts("Enter key element to search :");
					scanf(" %c", (char*)x);
					for(i = 0 ; i < n ; i++)
					{
						if(*((char*)(a + (i*sizeof(char))) ) == *(char*)x)
						{
							printf("the element is present at position %d \n", i);
						}
						else
						{
							printf("the element is not present at position %d \n", i);
						}

						break;
					}
				}
			case 3:					// case for binary search of float
				{
					a=(float*)calloc(n, sizeof(float));                      //search for float elements
					printf("Enter %d elements of type float : ", n);
					for(i = 0 ; i < n ; i++)
					{
						scanf("%f", (float*)(a + (i*sizeof(float))) );
					}
					qsort(a,n,sizeof(float), three);			// sorting the float array

					for(i = 0 ; i < n ; i++)				// printing the array
					{
						printf("%f\n", *(float*)(a + (i*sizeof(float))) );	
					}

					puts("Enter key element to search :");				
					scanf("%f", (float*)x);					// read the element to be searched

					for(i = 0 ; i < n ; i++)
					{
						if(*((float*)(a + (i * sizeof(float))) ) == *(float*)x)
						{ 
							printf("the element is present at position %d \n", i);
						}
						else
						{
							printf("the element is not present at position %d \n", i);
						}

						break;
					}
				}
			case 4:
				{
					a = (double*)calloc(n, sizeof(double));                   //search for double elments
					printf("Enter %d elements of type double : ", n);
					for(i=0;i<n;i++)
					{
						scanf("%lf", (double*)(a + (i*sizeof(double))) );
					} 

					qsort(a, n, sizeof(double), four);			// sorting the double array

					for(i=0;i<n;i++)					// printing the double array
					{
						printf("%lf\n", *(double*)(a + (i * sizeof(double))) );
					}

					puts("Enter key elementto search :");			
					scanf("%lf", (double*)x);				// reading element to be searched

					for(i = 0 ; i < n ; i++)				
					{
						if(*((double*)(a + (i * sizeof(double))) ) == *(double*)x)
						{
							printf("the element is present at position %d \n",i);
						}
						else
						{
							printf("the element is not present at position %d \n",i);
						}

						break;
					}
				}
		}
		printf("Do you want to continue : (y/Y|n/N) ");
		scanf(" %c",&c1);
	} while( c1 == 'y' || c1 == 'Y' );
}

int one(const void *a, const void *b)             //functions for argument in qusort 
{
	return *(int*)a > *(int*)b;
}

int two(const void *a , const void *b)
{
	return *(char*)a > *(char*)b;
}
int three(const void *a , const void *b)
{
	return *(float*)a > *(float*)b;
}
int four(const void *a , const void *b)
{
	return *(double*)a > *(double*)b;
}
