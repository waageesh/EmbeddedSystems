/*
Title	: Printing address that causing SEGMENTATION FAULT error
Author	: Vaageesh
Date	: Monday 11 January 2021 11:19:00 PM IST
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

struct sigaction act;			// declaring global structure variable

void mysignal_handler(int signum, siginfo_t* siginfo, void* data )
{
	printf("Segmentation Fault Error...");
	printf("Fault caused at Address %p\n", siginfo->si_addr);	// printing error causing address
	exit(0);
}

int main()
{
	int* p = (int*)10;
	memset(&act, 0, sizeof(act));		// clearing out the structure
	
	act.sa_sigaction = mysignal_handler;	// registering signal handler to act structure
	act.sa_flags = SA_SIGINFO;		// registering the flags
	
	sigaction(SIGSEGV, &act, NULL);	// registering SIGSEGV signal , which is responsible for throwing
						// SEG FAULT error, when illegal memory accessing happens
	*p = 50;				// causes SEG FAULT error, since address 0x10 is not allocated memory
	//strcpy(str, "hello");

	return 0;
}

