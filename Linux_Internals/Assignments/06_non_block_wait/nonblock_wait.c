/*
Title	: avoid a child become zombie with out blocking the parent, using waitpid(), fork() system calls
Author	: Vaageesh
Date	: Monday 04 January 2021 12:03:23 AM IST
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main()
{
	int status;		// status to collect exit status of child procesd
	pid_t pid;		// pid to collect process id's of parent and child process
	pid = fork();		// creating child process at this step
	if (pid > 0)		// fork will will return pid +ve value for parent process
	{
		printf("parent process with id %d has started\n", getpid());

		/*  WNOHANG macro wont block parent process, 
		   -1 is to tell parent process to wait, till any of the child terminates */
		while ( waitpid(-1, &status, WNOHANG) != -1)	// waitpid will return -1, if any of its child got terminated
		{
			sleep(1);
			printf("parent process is running\n");	
		}
		if (WIFEXITED(status))				// if child exited sucessfully, it will return True
		{
			printf("child process terminated with status %d\n", WEXITSTATUS(status));
		}
		else						// return false, if child terminated abnormally
		{
			printf("child process terminated abnormally\n");
		}

		printf("parent process is terminating\n");
	}
	else if (pid == 0)	// fork will return pid 0 if its child process
	{
		printf("child process with id %d is started\n", getpid());
		sleep(5);					// make child process runs for 5 seconds
		//printf("child process is terminated\n");
		exit(0);					// exit status of child
	}
	return 0;
}
