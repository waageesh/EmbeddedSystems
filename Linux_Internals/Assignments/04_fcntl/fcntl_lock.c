/*
Title	: file control
Author	: Vaageesh
Date	: Monday 11 January 2021 11:19:00 PM IST
*/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>
#include <errno.h>


int main (int argc, char* argv[])
{
 	int fd, status;
 	struct flock lock;
 	int pid;
	fd = open(argv[1], O_WRONLY | O_TRUNC);
	if (fd == -1)
	{
		perror("Open error");
	}
 	//wait(&status);	
	pid = fork();
	if (pid == 0)
	{
		printf("child pid %d\n", getpid());
		int odd_array[50];
		// lock the file descriptor before writing, to prevent its writing from other process
		lock.l_type = F_WRLCK;
		
		/* Place a write lock on the file. */
	 	if (fcntl(fd, F_SETLKW, &lock) == -1)
	 	{
	 		if (errno == EINTR)
	 			printf("file is already locked by other process\n");
	 	}
	 	
		// write message into file
		
		for (int i=1,j=0; i<=100; i++)
		{
			if (i % 2 == 0)
			{
				odd_array[j] = i;
			}
		}
		
		// write data read from buff to file
		if (write(fd, odd_array, sizeof(odd_array)/sizeof(int)) == -1)
			perror("write error");
		
		// unlock write lock on file
		lock.l_type = F_UNLCK;
		fcntl (fd, F_SETLKW, &lock);
	}
	else
	{
		printf("parent pid %d\n", getpid());
		int even_array[50];
		// lock the file descriptor before writing, to prevent its writing from other process
		lock.l_type = F_WRLCK;
		
		/* Place a write lock on the file. */
	 	if (fcntl(fd, F_SETLKW, &lock) == -1)
	 	{
	 		if (errno == EINTR)
	 			printf("file is already locked by other process\n");
	 	}
	 	
		// write message into file
		for (int i=1,j=0; i<=100; i++)
		{
			if (i % 2 != 0)
			{
				even_array[j] = i;
			}
		}
		
		// write data read from buff to file
		if (write(fd, even_array, sizeof(even_array)/sizeof(int)) == -1)
			perror("write error:");
		
		// unlock the write unlock on file	
		lock.l_type = F_UNLCK;
		fcntl (fd, F_SETLKW, &lock);
	}
 	return 0;
}
