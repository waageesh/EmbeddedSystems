/*
Title   : avoid zombie using SIGNAL Handler
Author  : Vaageesh
Date    : Sunday 17 January 2021 12:32:31 PM IST 
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
 
struct sigaction act;
void sigchild_handler_sa_flag(int signum, siginfo_t *info, void* arg)
{
	printf("entered signal handler V2 func\n");
	printf("Child %d terminating..\n", getpid());
	//printf("child %d terminating with status %d\n", info->si_pid, info->si_status);
}

void sigchild_handler(int signum)
{
	printf("entered signal handler V1 func\n");
	pid_t pid = wait(NULL);
	printf("Child %d terminating..\n", pid);
}

int main()
{
	int menu, pid;
	printf("1. avoid zombie process using signal handler\n2. avoid zombie use sa_flag from struct sigaction\n");
	printf("Choose one from above :");
	scanf("%d", &menu);
	if (menu == 1)						// using sa_handler for signal registering
	{
		/* registering signal to signal handler*/
		act.sa_handler = sigchild_handler;
		
		/* SIGCHLD signal registration status */
		perror("SIGCHLD resgistering");
		
		/* registering signal to signal handler*/
		sigaction(SIGCHLD, &act, NULL);
	}
	else							// using sa_sigaction for signal registering
	{
		/* registering signal handler function */		
		act.sa_sigaction = sigchild_handler_sa_flag;
		
		/* registering SA_NOCHLDWAIT to remove child process resources after its termination */
		act.sa_flags = SA_NOCLDWAIT;
		
		/* registering signal to signal handler*/
		sigaction(SIGCHLD, &act, NULL);
		
		/* SIGCHLD signal registration status */
		perror("SIGCHLD resgistering");
	}
	
	if ( (pid = fork())== 0)				// child process
	{
		/* Delaying child process for 3 sec */
		for(int i=0; i<3; i++)
		{
			sleep(1);
			printf("child process %d is running..\n", getpid());
		}
	}
	else							// parent process
	{
		sleep(5);					// waiting parent till child completes its execution
		printf("parent process %d terminating..\n", getpid());
	}
	
	return 0;
}
