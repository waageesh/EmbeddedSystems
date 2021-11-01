/*
Title   : Matrix multiplication using Multi-threading
Author  : Vaageesh
Date    : Sunday 17 January 2021 12:32:31 PM IST 
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int** generic_matrix_generator(int row, int col);			// function prototype for generic matrix generator

typedef struct thread_data						// global structure for storing matrices
{
	short m1_row;
	short m1_col;
	short m2_row;
	short m2_col;
	int **matrix1;
	int **matrix2;
	int **result;
	short cur_row;
} Thread_data_t;

Thread_data_t* thread ;						// declaring global structure variable

void* thread_entry_function(void* index)				// thread entry function for threads created
{
	int i = *(int *)index;
	
	
	// Multiplying first matrix row with second matrice and storing it in 
	// result matrix first row
	for (int j = 0; j < thread->m2_col; j++) 
	{
		thread->cur_row = 0;
		for (int k = 0; k < thread->m1_col; k++) 
		{
		    /* mutiple ith ROW of matrix1 with all columns in matrix2 */
		    thread->cur_row += thread->matrix1[i][k] * thread->matrix2[k][j];
		}
		thread->result[i][j] =   thread->cur_row;	
	}
}

int main()
{
	/* Dynamic memory allocation for global structure */
	thread = malloc(sizeof(Thread_data_t));
	
	/* reading rows and columns for both matrices */
	printf("Enter M1 rows and columns :");
	scanf("%hu%hu",&thread->m1_row, &thread->m1_col);
	printf("Enter M2 rows and columns :");
	scanf("%hu%hu",&thread->m2_row, &thread->m2_col);
	printf("col2:%d, col1:%d\n",thread->m2_col, thread->m1_col);
	
	/* declearing array of thread IDS for storing IDs of threads created */
	pthread_t tid[thread->m1_row];
	
	/* matrix generation for M1, M2 and resultant matrix */
	thread->matrix1 = generic_matrix_generator(thread->m1_row, thread->m1_col);
	thread->matrix2 = generic_matrix_generator(thread->m2_row, thread->m2_col);
    	thread->result  = generic_matrix_generator(thread->m1_row, thread->m2_col);
	
	/* reading Matrix1 values */
	printf("Enter M1 values :\n");
	for(int i=0; i<thread->m1_row; i++)
	{
		for(int j=0; j<thread->m1_col; j++)
		{
			scanf("%d", &thread->matrix1[i][j]);
		}
	}

	/* reading Matrix2 values */
	printf("Enter M2 values :\n");
	for(int i=0; i<thread->m2_row; i++)
	{
		for(int j=0; j<thread->m2_col; j++)
		{
			scanf("%d", &thread->matrix2[i][j]);
		}
	}
	
	/* creating thread and waiting for thread to be completed using pthread_join*/
	for (int i=0; i<thread->m1_row; i++)
	{
	    pthread_create(&tid[i], NULL, thread_entry_function, (void*)&i);
	    pthread_join(tid[i], NULL);
	}
	
	/* printing resultant matrix */
	printf("result matrix :\n");
	for(int i=0; i<thread->m1_row; i++)
	{
		for(int j=0; j<thread->m2_col; j++)
		{
			printf("%d ", thread->result[i][j]);
		}
		printf("\n");
	}

	return 0;
}

int** generic_matrix_generator(int row, int col)				// function definition for generic matrix generator
{
	/* Dynamic memory allocation for entire matrix */
	int** matrix = malloc(sizeof(int)*col);
	
	/* memory allocation validation for matrix */
	if (matrix == NULL)
		printf("memory not allocated for matrix\n");
	for (int i=0; i<row; i++)
	{
		/* Dynamic memory allocation for row */
		matrix[i] = malloc(sizeof(int)*row);
		/* memory allocation validation for row */
		if (matrix[i] == NULL)
			printf("memory not allocated for row %d\n", i);
	}
	return matrix;								// returning address of matrix(heap variable) created
}
