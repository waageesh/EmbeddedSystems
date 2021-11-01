/*
Title	: Three child from same parent using fork(), wait() system calls
Author	: Vaageesh
Date	: Monday 04 January 2021 12:03:23 AM IST
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int status,i=0;
    pid_t pid[3];		// array to hold child PIDs	
    pid[0] = fork();		// creating first child
    if (pid[0] == 0)		// 1st child case
    {
            sleep(1);		// child2 wait for 2 sec
    }	
    else			// parent case
    {
        printf("child process started with id %d\n", pid[0]);
        pid[1] = fork();	// creating 2nd child
        if (pid[1] == 0)	// 2nd child case
        {
            sleep(2);		// child2 wait for 2 sec
        }
        else
        {
            printf("child process started with id %d\n", pid[1]);
            pid[2] = fork();	// creating 3rd child 
            if (pid[2] == 0)	// 3rd child case
            {   
                sleep(3);
            }
            else		// parent case
            {   
                printf("child process started with id %d\n", pid[2]);
            }
        }
    }
    
    while (wait(&status) != -1)			// loop till all child process completes
    {	
    	if (WIFEXITED(status))				// sucessful child process terminates
    	{
        	printf("child %d terminated with status %d\n", pid[i++], status);
        }
        else						// sucessful child process terminates
        {
        	printf("child %d terminated abnormally\n", pid[i]);
        	return 0;
        }
    }
    return 0;
}



