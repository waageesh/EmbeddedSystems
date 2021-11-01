/*
Title   : finding global sum and global maximum value of array[N] dividing work across threads
Author  : Vaageesh
Date    : Sunday 17 January 2021 12:32:31 PM IST 
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct sum_max
{
	int global_sum;
	int global_max;
	int start;
	int end;
} sum_max_t;

/* mutex variable for locking and unlocking critical section */
pthread_mutex_t lock;

/* structure to store global_sum & global_max values */
sum_max_t* sm;

void* sum_max_thread_entry_func(void* arr)
{
	printf("Entered thread entry func with range %d, %d\n", sm->start, sm->end);
	int *array = (int*)arr;
	/* Applying mutex lock, so that next incoming thread wont acquire the lock
	   to access the below critical section */
	pthread_mutex_lock(&lock);
	for (int i = sm->start; i <= sm->end; i++)
	{
		//printf("arr[%d]:%d\n", i, array[i]);
		sm->global_sum = sm->global_sum + array[i];
		if (array[i] > sm->global_max)
		{
			sm->global_max = array[i];
		}
	}
	/* unlocking mutex for next thread to acquire critical section */
	pthread_mutex_unlock(&lock);
}

int main()
{
	/* Dynamic memory allocation for global structure */
	sm = malloc(sizeof(sum_max_t));
	sm->global_sum = 0;
	sm->global_max = -999999;
	
	int size;

	/* reading size of array - min size 500 */
	printf("Enter the size of array :");
	scanf("%d", &size);
	int arr[size];
	pthread_t tid[5];
	
	/* mutex varaible initialization */
	pthread_mutex_init(&lock, NULL);
	int divide_count = (size % 5 == 0) ? (size / 5) : (size / 5 + 1);
	int thread_count = 5;
	/* populating random values into array */
	for (int i=0; i<size; i++)
	{
		arr[i] = (i*i)%size;
	}

	/* creating threads for sharing work among array */
	for (int i = 0; i < thread_count; i++)
	{
		/* allocating start and end indexes of array to each thread */
		sm->start = (i) * divide_count;
		sm->end = ((i + 1) * divide_count) - 1;
		if (sm->end >= size)		// if end index of array crosses its size, assign end as size of array
		{	
			sm->end = size-1;
		}

		/* creating thread and registering thread entry function with thread id */
		if (pthread_create(&tid[i], NULL, sum_max_thread_entry_func, (void*)&arr) != 0)
		{
			perror("Thread creation");
		}

		/* waits till thread completion */
		if (pthread_join(tid[i], NULL) != 0)
		{
			perror("Thread waiting");
		}
	}

	printf("global max : %d\nglobal sum : %d\n", sm->global_max, sm->global_sum);
	free(sm);
	return 0;
}
