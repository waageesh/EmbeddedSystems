/*
Title	: WAP Communication between processes using different IPC mechanisms like IPC, SHM and PIPE
Author	: Prajakta Kasab
Date	: 18/01/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define BUFF_SIZE 15
#define FIFO_FILE "STRING_REVERSE_FIFO"



int main(void) 
{
	char string[BUFF_SIZE];
	int fd[2], i = 0, status;
	pipe(fd);														// creating pipe to communicate between parent and child process
	int pid = fork();												// creating a child process
	if (pid == 0)													// child process
	{
		sleep(5);													// delay child for sometime
		// so that parent can read string from STDIN and write that string into write end of pipe
		printf("Child process -> %d started \n", getpid());
		/* getting from PIPE , capitalizing and storing in shm */
		char* str = malloc(BUFF_SIZE);
		char* str_upper;											// string to save string that is captitalized
		int len, i = 0;
		
		/* close write end of pipe*/
		if (close(fd[1]) == -1)
			perror("pipe write end close");
	
		/* read string from read end of PIPE */
		if (read(fd[0], str, BUFF_SIZE) == -1)
			perror("pipe read");
		
		/* close read end after reading string*/
		if (close(fd[0]) == -1)
			perror("pipe read end close");
		
		len = strlen(str);
		str_upper = malloc(len + 2);								// dynamic memory allocation including size as int in first index

		/* capitalizing string read from pipe*/
		while(len >= 0)
		{	
			if (i == 0)
			{
				*(str_upper + i) = len + '0';							// save lenght of string in first index
			}
			else
			{
				*(str_upper + i) = toupper(*(str + i - 1));
			}
			len--;
			i++;
		}

		/*shm key intialization*/
		key_t key = 'C';
		
		/* create shared memory for above created key */
		int shmid = shmget(key, BUFF_SIZE, IPC_CREAT|0664);
		if (shmid == -1)
			perror("shmid");
		
		/* get address of created shared memory */
		char* shmaddr = shmat(shmid, NULL, 0);
		
		/* copying capitalized string to shm */
		strcpy(shmaddr, str_upper);
		
		/*detaching shm after writing into shm*/
		shmdt(shmaddr);
		printf("child process %d terminated\n", getpid());
		sleep(5);
	}
	else
	{
		char* str;
		printf("Parent process -> %d started\n", pid);
		printf("Enter the string :");
		scanf("%ms", &str);
		
		/*close stdin and redirect 0 fd to write end of pipe */
		if (close(fd[0]) == -1)
			perror("pipe read end close");
		
		/* write the string read from user to write end of pipe */
		if (write(fd[1], str, strlen(str) + 1) == -1)
			perror("pipe write");
		
		/* close write end of PIPE after writing string into PIPE */
		if (close(fd[1]) == -1)
			perror("pipe write end close");
		
		/* wait till child completed, since child process CAPITALISE the string and place that in shared memory*/
		wait(&status);
		printf("parent process restored\n");
		
		/* open fifo file created in read mode */
		int fifo_fd = open(FIFO_FILE, O_RDONLY, 0664);
		if (fifo_fd == -1)
		{
			perror("fifo open");
		}
		
		/* reading from fifo */
		int ret = read(fifo_fd, string, strlen(str));
		if (ret == -1)
			perror("fifo read");
			
		/* placing last character as NULL for the characters read from FIFO file */
		*(string + ret) = '\0';
		
		/* close fifo file*/
		close(fifo_fd);
		
		printf("final string %s, len %ld\n", string, strlen(string));
		printf("parent process %d terminated\n", pid);
	}
	return 0;
}
