/*
Title   : create a child process which will execute command passed through command-line arguments
Author  : Vaageesh
Date    : Monday 04 January 2021 12:03:23 AM IST
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int status;
	pid_t pid;
	if (argc == 1)
	{
		printf("No args passed\nUsage:\n./exe_child [OPTIONS] <arg>\n");
	}
	else
	{
		printf("parent process with id %d started\n", getpid());
		pid = fork();								// creating child process
		if (pid > 0)								// parent process, pid>0
		{
			while(waitpid(-1, &status, WNOHANG) != -1)			// running parent process without blocking, while child is executing
			{
				sleep(1);
				printf("parent process is running\n");	
			}
			if (WIFEXITED(status))						// exit status is true, if there is normal termination of child
			{
				printf("child process exited normally with status %d\n", WEXITSTATUS(status));
			}
			else								// exust status is false, there is abnormal child termination
			{
				printf("child process exited abnormally\n");
			}
			printf("parent process terminating...\n");

		}
		else									// child process with pid == 0
		{
			printf("child process with ID %d started\n", getpid());
			if (execvp(argv[1], &argv[1]) == -1)				// execvp fails, returns -1
			{
				printf("execvp failed\n");
				exit(0);
			}
			sleep(5);							// on success return nothing, waits for 5sec and terminates
			exit(0);
		}
	}
	
	return 0;
}
