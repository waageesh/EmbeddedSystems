/*
Title	: BlockSignal for sometime for registered signals
Author	: Vaageesh
Date	: Monday 14 January 2021 11:19:00 PM IST
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


struct sigaction act;			// declaring sigaction structure globally
sigset_t block;			// declaring sigset_t variable
void signal_handler(int signum)	// signal handler function
{
	// checking signal passed is in sigset_t list or not
	if (signum == 2)
		printf("SIGINT received\n");
	int i=10;
	while(i--)
	{
		sleep(1);
	}	
	
}
int main()
{
	act.sa_handler = signal_handler;	// register signal handler
	act.sa_flags = SA_SIGINFO;
	
	/*adding single single at once, to sigset*/
	sigaddset(&block, SIGUSR1);		// adds SIGUSR1 to block(sigset_t variable) internally
	sigaddset(&block, SIGTERM);		// adds SIGTERM to block(sigset_t variable) internally
	sigaddset(&block, SIGABRT);		// adds SIGABRT to block(sigset_t variable) internally
	
	act.sa_mask = block;			// assigning sigset_t to sa_mask in sigaction structure
		
	/* blocks all signals except SIGKILL and SIGSTOP*/
	//sigfillset(&block);
	//sigprocmask(SIG_SETMASK, &block, NULL);

	
	/* registering signal to signal handler*/
	sigaction(SIGINT, &act, NULL);		//  int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);			
	while(1)
	{
		sleep(1);
		printf("process waiting for signal...\n");
	}
	return 0;
}
