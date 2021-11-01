#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int generate_magic_sq( int size, int (*sq_ptr)[size] ) ;
int main()
{
        int size;
        printf("Enter a number :");
        scanf("%d",&size);


        int *magic_sq = (int*)malloc(sizeof(int) * size * size);
        int (*sq_ptr)[size] ;
        sq_ptr = magic_sq;
        generate_magic_sq(size, sq_ptr);

        for (int i = 0; i < size ; i++)
        {
                for (int j = 0; j < size ; j++)
                {
                        printf("%d\t", *(*(sq_ptr + i) + j) );
                }
                printf("\n");
        }

        return 0;
}

int generate_magic_sq(int size, int (*sq_ptr)[size])
{
        int row =0, col=size/2, num = 1, prev_row = 0, prev_col=0;
        for (int num=1; num <= size*size; )
        {

            if (row == -1 || col == size)
            {
                    if (row == -1 &&  col == size && *(*(sq_ptr + (size-1)) + 0) != 0)
                    {
                        prev_row = row;
                        row = row+2;
                        col--;
                        printf("-1,4,element exist case --> row :%d, col :%d, num :%d\n", row, col, num);
                        *(*(sq_ptr + row) + col) = num++;
                        row--;
                        col++;
                        continue ;
                    }
                    if (row == -1)
                    {
                            prev_row = row;
                            row = size - 1;
                    }
                    if (col == size)
                    {
                            prev_col = col;
                            col = 0;
                    }

                    if ( *(*(sq_ptr + row) + col) == 0 )
                    {
                            printf("-1 or 4 case row :%d, col :%d, num :%d\n", row, col, num);
                            *(*(sq_ptr + row) + col) = num++;
                            prev_row = row;
                            row--;
                            col++;
                            printf("-next row :%d, col :%d, num :%d, size :%d\n", row, col, num, size);
                            continue;
                    }
                    else
                    {
                            printf("no already there at row :%d, col :%d, num :%d, prev_col:%d\n", row, col, num, prev_col);
                            prev_row++;
                            row = prev_row ;
                            col = prev_col-1;
                            //col--;
                            printf("new row :%d, col :%d, num :%d\n", row, col, num);
                            *(*(sq_ptr + row) + col) = num++;
                            row--;
                            col++;
                            continue;
                    }
            }
            if ( *(*(sq_ptr + row) + col) == 0 )
            {
                printf("....row :%d, col :%d, num :%d\n", row, col, num);
                *(*(sq_ptr + row) + col) = num++;
                prev_row = row;
                row--;
                col++;
            }
            else
            {
                prev_row++;
                row = prev_row ;
                col--;
                if (row == size)
                {
                    row  = 0;
                }
                if (col == size)
                {
                    col = 0;
                }
                printf("...........row :%d, col :%d, num :%d\n", row, col, num);
                *(*(sq_ptr + row) + col) = num++;
                row--;
                col++;
            }
        }

}
