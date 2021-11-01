/*
Title : even_or_odd
Author: vaageesh
Date  : Saturday 22 September 2020 10:01:23 AM IST 
*/



#include<stdio.h>


int main()
{
	int nth_day,option,day,day_no;
	char cont;
	do
	{
		printf("Enter value of n :");
		scanf("%d",&nth_day);
		if ( nth_day >=1 && nth_day <= 365 )		// checking range in between
		{
			printf("Choose First Day:\n1.Sunday\n2.Monday\n3.Tuesday\n4.Wednesday\n5.Thursday\n6.Friday\n7.Saturday\n");
			printf("Enter the option to set the first day :");
			scanf("%d",&option);
			day_no = nth_day % 7;                    // finding day number by dividing with 7(since days range 1-7)
			day = (day_no + option - 1) % 7;        // finding which day by dividing with 7
			printf("day is %d\n",day);
			switch(day)				// printing day based on week selected for the first day of year	
			{
				case 1 : 
					{
						printf("%d day is Sunday\n",nth_day);
						break;
					}

				case 2 : 
					{
						printf("%d day is Monday\n",nth_day);
						break;
					}

				case 3 : 
					{
						printf("%d day is Tuesday\n",nth_day);
						break;
					}

				case 4 : 
					{
						printf("%d day is Wednesday\n",nth_day);
						break;
					}

				case 5 : 
					{
						printf("%d day is Thursday\n",nth_day);
						break;
					}

				case 6 : 
					{
						printf("%d day is Friday\n",nth_day);
						break;
					}

				case 7 : 
					{
						printf("%d day is Saturday\n",nth_day);
						break;
					}

				default :
					{
						printf("none of the above\n");
					}
			}
		}
		else								// if day is not given withing range of 1-365
		{
			printf("Invalid input\n");
		}

		printf("Do you want to continue(y/n) :");
		scanf(" %c",&cont);
	} while(cont == 'y');
	
	return 0;

}
