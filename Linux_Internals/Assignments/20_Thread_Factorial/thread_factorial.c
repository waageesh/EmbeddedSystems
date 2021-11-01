/*
Title   : Factorial using Thread 
Author  : Vaageesh
Date    : Sunday 17 January 2021 12:32:31 PM IST 
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

/* thread_entry_function for factorial using Dynamic Memory Allocation */
void *thread_entry_function(void* arg)
{
        int num = *(int*)arg;               // typecasting void* to int* and dereferencing
        long int *res = (long int *)malloc(sizeof(long int));       // DMA for storing result
        *res = 1;                           // initializing res with 1
        int max = (num-3 > 0) ? (num - 3) : 0 ;                     // calculating max to stop fact calculation
        for(int i=num; i>max; i--)          // fact calculation loop
        {
                *res = (*res)*i;
        }
        return res;                         // return long int *
}

int main()
{
        int num, temp;                        
        long int *res;
        long int fact=1;
        printf("Enter the number :");
        scanf("%d", &num);                  // user input for calculating factorial
        temp = num;
        int max_threads = 3+num%2;          // calculating max no of threads required
        pthread_t tid[max_threads];         // array of thread IDs
        for (int i=0; i<max_threads; i++)   // creating no of thread required for fact load balancing
        {
            /* create thread. Thread will execute thread_entry_function func */
            pthread_create(&tid[i], NULL, thread_entry_function, (void*)&num);
            
            /* wait till thread completion */
            pthread_join(tid[i], (void **)&res);
            
            fact = fact * (*res);           // mutiplying fact result with return value of thread function
            num = num-3;                    // decrementing num by 3
        }

        printf("Back in main thread\nFactorial of %d is %ld\n", temp, fact);          // printing final factorial

}

