/* 
Title  : Sorting( bubble sort, insertion sort & selection sort)
Author : Vaageesh
Date   : Monday 20 December 2020 11:40:49 PM IST
*/

#include "sort.h"

int main()
{
	int elementArray[ARRAYSIZE];

	int totalElements, result;
	int choice, i = 0;
	char option;
	
	do
	{
	
	printf("\n\nEnter the option:\n");
	printf("1. Create an array\n");	
	printf("2. BubbleSort\n");	
	printf("3. InsertionSort\n");	
	printf("4. SelectionSort\n");	
	printf("5. Display array\n");
	
	printf("Choose your option from above: ");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
			printf("\nEnter the total number of element to be inserted in array: ");
			scanf("%d", &totalElements);
		
			for(i = 0; i < totalElements; i++)
			{
				printf("%d: ", i);
				scanf("%d", &elementArray[i]);
			}	
			break;
		
		case 2: 
			result = bubbleSort(elementArray, totalElements);
			(result == SUCCESS)? printf("\nbubbleSort SUCCESS\n"): printf("bubbleSort FAILURE\n") ;
			
			//check the list for validating
			print_array(elementArray, totalElements);
			break;

		case 3: 
			result = insertionSort(elementArray, totalElements);
			(result == SUCCESS)? printf("\ninsertionSort SUCCESS\n"): printf("insertionSort FAILURE\n") ;
			
			//check the list for validating
			print_array(elementArray, totalElements);
			break;
		case 4: 
			result = selectionSort(elementArray, totalElements);
			(result == SUCCESS)? printf("\nselectionSort SUCCESS\n"): printf("selectionSort FAILURE\n") ;
			
			//check the list for validating
			print_array(elementArray, totalElements);
			break;

		case 5: 
			print_array(elementArray, totalElements);
			break;
		default:
			printf("Invalid entry.\n");
			break;
	}
	/* check for continue */
        printf("Continue (y/n): ");
        scanf("\n%c", &option);
        
        if ( option == 'y' )
        {
            continue;
        } else
        {
            break;
        }
        
    } while (1);
		
    return 0;
}
