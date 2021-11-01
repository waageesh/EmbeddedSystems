#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int generate_magic_sq( int size, int (*sq_ptr)[size] ) ;			// function prototype for magic_square(size & pointer to array 
										// 					as arguments)
int main()
{
        int size;
        printf("Enter a number :");
        scanf("%d",&size);							// reading odd size for magic square


        int *magic_sq = (int*)malloc(sizeof(int) * size * size);		// declaring Dynamic memory allcoation for magic square
        int (*sq_ptr)[size] ;							// declaring pointer to array
        sq_ptr = magic_sq;							// assinging magic square base address to pointer to array
        generate_magic_sq(size, sq_ptr);					// calling magic sq generating funciton

        for (int i = 0; i < size ; i++)						// printing magic sq elements after generating magic_sq
        {
                for (int j = 0; j < size ; j++)
                {
                        printf("%d\t", *(*(sq_ptr + i) + j) );
                }
                printf("\n");
        }

        return 0;
}

int generate_magic_sq(int size, int (*sq_ptr)[size])				// function proto-type for generating magic square
{
        int row =0, col=size/2, num = 1, prev_row = 0, prev_col=0;		// declaring and intializing row, col , prev_row, prev_col 
        for (int num=1; num <= size*size; )					// loop to generate n*n numbers and save them in magic sq
        {

            if (row == -1 || col == size)					// checking row, col exceeds boundary
            {
                    if (row == -1 &&  col == size && *(*(sq_ptr + (size-1)) + 0) != 0)			// checking (row-1, 0) is
                    {											// filled or not
                        prev_row = row;						// copying row to prev value
                        row = row+2;						// shifting row to its prev val
                        col--;							// shifting col to its prev by decrementing
                        *(*(sq_ptr + row) + col) = num++;			// assign number to (new row , prev col) 
                        row--;							// generate new row,col and move to next iteration
                        col++;
                        continue ;
                    }
                    if (row == -1)						// if row exceed boundary negatively
                    {
                            prev_row = row;					// copying curr row val , to prev
                            row = size - 1;					// resetting row to max val
                    }
                    if (col == size)						// if col exceed boundary positively
                    {
                            prev_col = col;					// copying curr col value to prev
                            col = 0;						// resetting col to 0(beginning index)
                    }

                    if ( *(*(sq_ptr + row) + col) == 0 )			// if element is not there at newly changed co-ordinates
                    {
                            *(*(sq_ptr + row) + col) = num++;			// assing element to newly changed co-ordinates
                            prev_row = row;					// copying cur row value to prev
                            row--;						// generate new (row,col) and move to next iteration
                            col++;
                            continue;
                    }
                    else							// if again element is there at newly changed place, 2nd time
                    {
                            prev_row++;						// getting prev value by incrementing, since prev contains newly changed row now
                            row = prev_row ;					// changing row old to prev row value
                            col = prev_col-1;					// changing col to prev_col-1 val
                            *(*(sq_ptr + row) + col) = num++;			// assigning element now
                            row--;						// generate new (row,col) and move to next iteration
                            col++;
                            continue;
                    }
            }
            if ( *(*(sq_ptr + row) + col) == 0 )				// if (row,col) is other than (-1,size) & 
            {									// 			element doesn't exist at that place
                *(*(sq_ptr + row) + col) = num++;				// assign element to that place
                prev_row = row;							// copying row to prev
                row--;								// generating new (row,col) and move to next iteration
                col++;
            }
            else								// if (row,col) is other than (-1,size) &
            {									// 			element exist at that place
                prev_row++;							// getting prev_row
                row = prev_row ;						// chaning row to prev val
                col--;	
                if (row == size)						// if row exceed boundary positively
                {
                    row  = 0;							
                }
                if (col == size)						// if col exceed boundary positively
                {
                    col = 0;
                }
                *(*(sq_ptr + row) + col) = num++;				// assign element to newly changed co-ordinates
                row--;								// generate new (row ,col) for next iteration
                col++;
            }
        }

}
