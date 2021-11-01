/*
Title : median
Author: vaageesh
Date  : Wednesday 30 September 2020 11:38:44 PM IST
*/


#include <stdio.h>

int main()
{
    char cont;
    do
    {
    	int size1, size2, swap=0, temp=0 ;
    	float median1=0, median2=0 ;
    	printf("Enter the 'n' value for Array A :");  			// taking array1 size
        scanf("%d",&size1);
        
        if (size1 > 10)							// checking array size<10
        {
            printf("Max array elements exceeded\n");
        }
        else
        {
            int arr1[size1];						// declaring array1 with given size
            
            printf("Enter the elements one by one for Array A:");
            for(int i=0;i<size1;i++)	
            {
                scanf("%d",&arr1[i]);					// taking element by element for array1
            }
            
            for(int i = 0 ; i < size1 ; i++)				// bubble sort for array1
            {
                for(int j = 0 ; j < size1-1 ; j++)
                {
                    if ( arr1[j] > arr1[j+1] )				// swapping adjacent elements if not in ascending order
                    {
                        temp = arr1[j+1];
                        arr1[j+1] = arr1[j];
                        arr1[j] = temp;
                        swap = 0;
                    }
                }
                
                if ( swap == 1 )					// if entire array is already sorted, then break the loop
                {
                    break;
                }
            }
            
            printf("After sorting :");
            for (int i = 0 ; i < size1 ; i++)
            {
                printf("%d ",arr1[i]);					// printed sorted array1
            }
            
            if ( !(size1 % 2) )						// checking size of array1 is even or odd
            {
                int mid1 = size1/2;		
                median1 = ((float)arr1[mid1] + arr1[mid1-1])/2;		// median by taking sum of middle , middle+1 elements if size is even
            }
            else
            {
                int mid1 = (float)size1/2;				// defining middle element
                median1 = arr1[mid1];					// median, by taking middle element alone when size of array is odd
            }
            
            printf("\nmedian1 of array1 :%f\n",median1);		// printing median of array1
            
            printf("Enter the 'n' value for Array B :");		// taking size of array2
            scanf("%d",&size2);				
            
            if (size2 > 10)						// checking size of array2 < 10
            {
                printf("Max array elements exceeded\n");
            }
            else
            {    
                int arr2[size2];           				// declaring array2 of given size
                printf("Enter the elements one by one for Array B:");
                for(int i=0;i<size2;i++)	
                {
                    scanf("%d",&arr2[i]);				// enetering elements into array one by one
                }
                
                for(int i = 0 ; i < size2 ; i++)			// bubble sort for array2
                {
                    for(int j = 0 ; j < size2-1 ; j++)
                    {
                        if ( arr2[j] > arr2[j+1] )			// swapping adjacent elements if they are not in ascending order
                        {
                            temp = arr2[j+1];
                            arr2[j+1] = arr2[j];
                            arr2[j] = temp;
                            swap = 0;
                        }
                    }
                    
                    if ( swap == 1 )					// if array2 is already sorted, break the loop
                    {
                        break;
                    }
                }
                
                printf("After sorting :");
                for (int i = 0 ; i < size2 ; i++)
                {
                    printf("%d ",arr2[i]);				// printed sorted array2
                }
                
                if ( !(size2 % 2) )					// checking size of array2 is even or odd
                {
                    int mid1 = size2/2;
                    median2 = ((float)arr2[mid1] + arr2[mid1-1])/2;	// getting median with avg of middle, middle+1 elements, if size is even
                }
                else
                {
                    int mid1 = size2/2;
                    median2 = arr2[mid1];				// getting median from middle element alone, if size is dd
                }
                
                printf("\nmedian2 of array2 :%f",median2);		// printing median2
            }
        }
        
        printf("\nmedian of both arrays :%f",(median1+median2)/2);		// printing final medina with avg of median1, median2
        
        printf("\nDo you want to continue(y/n) :");     // asking user to continue or not
        scanf(" %c",&cont);     
        	
	} while(cont == 'y');                           // if user given 'y', repeat the process
	
	return 0;
}

