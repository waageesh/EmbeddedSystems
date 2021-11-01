/*
Title	: implement pipe between 3 processes for cmd line args using C program
Author	: Vaageesh
Date	: Friday 08 January 2021 11:02:59 PM IST
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char* argv[])
{
	int fd[2];
	int pid, status;
	pipe(fd);				// creating pipe for communication between child1 and child2
	pid = fork();				// creates child1 process

	if (pid > 0)				// parent process
	{
		int fd1[2];			// file descriptor to hold pipe2 read/write ends
		pipe(fd1);
		int pid1 = fork();		// creates child2
		if (pid1 == 0)			// child2 process
		{
			sleep(1);
			// child2 for 2nd cmd arg along with options given
			// parent process, writing into pipe on write end
			int stdin_fd, k;

			// reading args for second command after "|" till end
			for (int i =  1; i < argc; i++)
			{
				if (!strcmp(argv[i],"|"))	// check till | symbol encounters
				{
					k = i;
					break;
				}
			}
			// close the write end for pipe1
			if (close(fd[1]) == -1)
				perror("pipe1 Close Error");

			// duplicating stdin to read end of pipe1 i.e, fd[0] 
			stdin_fd = dup2(fd[0], 0);
			if (stdin_fd == -1)
				perror("pipe1 Read Error");
			
			// duplicating stdout to write end of pipe2 i.,e fd1[1]
			if (dup2(fd1[1], 1) == -1)
				perror("pipe2 Write Error");

			// executing 2nd command
			if (execvp(argv[k+1], &argv[k+1]) == -1)
			{
				printf("Child2 execution failed\n");
				exit(0);
			}
			exit(0);
		}
		else						// parent process
		{
			sleep(2);
			int pid2 = fork();			// child3 process
			if (pid2 == 0)
			{
				// child3 for 2nd cmd arg along with options given
				// parent process, writing into pipe on write end
				int stdin_fd, k, pipe_cnt=0;

				// reading args for second command after "|" till end
				for (int i =  1; i < argc; i++)
				{
					if (!strcmp(argv[i],"|"))	// check till "|" symbol encounters twice
					{
						pipe_cnt++;
						if (pipe_cnt == 2)
						{
							k = i;
							break;
						}
					}
				}
				// close the write end
				if (close(fd1[1]) == -1)
					perror("Close Error");

				// duplicating stdin to read end of pipe i.e, fd1[0] 
				stdin_fd = dup2(fd1[0], 0);
				if (stdin_fd == -1)
					perror("Read Error");

				// executing 2nd command
				if (execvp(argv[k+1], &argv[k+1]) == -1)
				{
					printf("Child2 execution failed\n");
					exit(0);
				}
				exit(0);
			}
		}
	}
	else
	{
		// child1 process, writing into pipe on write end
		char* args[argc-1];
		int k;
		// reading args for first command till first occurence of "|"
		for (int i=1; i<argc; i++)
		{
			int size = strlen(argv[i]);
			args[i-1] = malloc(size);
			if (!strcmp(argv[i], "|"))
			{
				args[i-1] = NULL;			// fill last 1d array with NULL
				break;
			}
			else
			{
				memcpy(args[i-1], argv[i], size);	// copy 1d array into other 1d array till given size
			}
		}

		// close the read end
		if (close(fd[0]) == -1)
			perror("Close");


		// closing stdout file descriptor, and to redirect output to pipe write end
		if (dup2(fd[1], 1) == -1)
			perror("Write Error");

		// making cmd arg output print on PIPE, instead of STDOUT
		// writing at write end	
		if (execvp(args[0], args) == -1)
		{
			printf("child1 execution failed\n");
		}
	}
	sleep(3);
	exit(0);
}

