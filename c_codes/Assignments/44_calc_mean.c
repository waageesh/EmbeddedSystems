/*
Title  : Calculating mean for all data types
Date   : Friday 27 November 2020 10:29:16 PM IST
Name   : Vaageesh
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>

void func(void *, void *, void *, int ,int);                  //generic function declaration

int main(int argc,char *argv[])                            //calling main with arguments
{
	char c;
	do
	{
		int ch, n, i, l1;
		void *a, *x, *sum, *avg;
		if(argc <= 1)
			puts("Error :enter command line arguments ");          //argument presence check
		else
		{   
			printf("Select data type :\n1.Int\n2.Short\n3.Float\n4.Double\n"); //prompt options
			printf("Enter choice :");
			scanf("%d", &ch);
			n=atoi(argv[1]);
			switch(ch)
			{
				case 1:func(a, sum, avg, n, ch);                   //call according to choice
				       break;
				case 2:func(a, sum, avg, n, ch);
				       break;
				case 3:func(a, sum, avg, n, ch);
				       break;
				case 4:func(a, sum, avg, n, ch);
				       break;
			}
		}
		printf("Do you want to continue :(y/Y|n/N)");               //contniue optin
		scanf(" %c", &c);
	}while( c == 'y' | c == 'Y' );
}

void func(void *a, void *sum, void *avg, int n, int ch)             //generic function for Calculating mean
{
	int i;
	switch(ch)
	{
		case 1:
		    {
    			a = (int*)calloc(n, sizeof(int));                          //memory allocation
    			sum = (int*)calloc(1, sizeof(int));
    			avg = (float*)calloc(1, sizeof(float));
    			printf("Enter %d elements of type int \n",n);
    			for(i = 0 ; i < n ; i++)
    			{
    				printf("a[%d]= ", i);
    				scanf("%d",(int*)(a + (i * sizeof(int))) );   //typecasting elements for oper as arguments are genric 
    				*(int*)sum = *(int*)sum + *(int*)(a + (i * sizeof(int)) );
    			} 
    			*(float*)avg = (float)(*(int*)sum / n);               //double typecast as we need output in float
    
    			printf("The mean of given inputs is = %g\n",*(float*)avg);
    			break;
		    }
		case 2:
		    {
    			a = (short*)calloc(n,sizeof(short));
    			sum = (int*)calloc(1,sizeof(int));
    			avg = (float*)calloc(1,sizeof(float));
    			printf("Enter %d elements of type short \n",n);
    			for(i = 0 ; i < n ; i++)
    			{
    				printf("a[%d]= ", i);
    				scanf("%hd",(short*)(a + (i * sizeof(short))) );
    				*(int*)sum = *(int*)sum + *(short*)(a + (i * sizeof(short)) );      //typcast and add elements
    			}
    			*(float*)avg = (float)*(int*)sum/n;                              //printing float output
    			printf("The mean of given inputs is = %g\n",*(float*)avg);
    			break;
		    }
		case 3:
		    {
    			a = (float*)calloc(n, sizeof(float));               // Dynamic Memory allocation
    			sum = (float*)calloc(1, sizeof(float));             
    			avg = (float*)calloc(1, sizeof(float));
    			printf("Enter %d elements of type float \n", n);
    			
    			for(i = 0 ; i < n ; i++)
    			{
    				printf("a[%d]= ", i);
    				scanf("%f", (float*)(a + (i * sizeof(float))) );                        // reading float values
    				*(float*)sum = *(float*)sum + *(float*)(a + (i * sizeof(float)) );      // cummulative sum of float values
    			}
    			*(float*)avg = (float)*(float*)sum/n;                                       // Calculating average from final sum
    			printf("The mean of given inputs is = %g\n", *(float*)avg);
    			break;
		    }
		case 4:
		    {
    			a = (double*)calloc(n, sizeof(double));
    			sum = (double*)calloc(1, sizeof(double));
    			avg = (double*)calloc(1, sizeof(double));
    			printf("Enter %d elements of type double \n", n);
    			for(i = 0 ; i < n ; i++)
    			{
    				printf("a[%d]= ", i);
    				scanf("%lf", (double*)(a + (i * sizeof(double))) );
    				*(double*)sum = *(double*)sum + *(double*)(a + (i * sizeof(double)) );
    			}
    			*(double*)avg = (double)*(double*)sum/n;                       //double output 
    			printf("The mean of given inputs is = %g\n", *(double*)avg);
    			break;
		    }
	}
}

