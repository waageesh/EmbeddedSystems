/*
Title	: file control
Author	: Vaageesh
Date	: Monday 11 January 2021 11:19:00 PM IST
*/


#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>
#include <errno.h>

int main()
{

	int pid = fork();			// creating a child process
	if (pid > 0)				// parent process
	{
		printf("parent pid %d started\n", getpid());
		sleep(2);
		char* str  = malloc(30);	// str to save linux command
		sprintf(str, "cat /proc/%d/status | head -4", pid);		// save dynamic linux command with pid
		system(str);			// execute above create dynamic linux cmd, to show process status
		printf("\n");
		int pid1 = fork();		// create child2 to show status of zombie process
		if (pid1 == 0)			// child 2 process
		{
			char* str  = malloc(30);				// str to save linux command
			int zombie_pid = pid;					// save zombie process pid
			sleep(2);
			sprintf(str, "cat /proc/%d/status | head -4", zombie_pid);	// save dynamic linux command with pid
			system(str);		// execute above create dynamic linux cmd, to show process status
			printf("\n");
			return 0;
		}
		printf("Process %d cleared by init\n", getpid());		// init termination display message 
		sleep(1);
		return 0;
	}
	else
	{
		printf("child pid %d started\n", getpid());
		char* str  = malloc(30);	// str to save linux command
		sprintf(str, "cat /proc/%d/status | head -4", getpid());		// save dynamic linux command with pid
		system(str);			// execute above create dynamic linux cmd, to show process status
		printf("\n");
		sleep(1);
		// printf("child pid %d terminated\n", getpid());
	}
	return 0;
}

