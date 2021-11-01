/*
Title	: file control
Author	: Vaageesh
Date	: Monday 11 January 2021 11:19:00 PM IST
*/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main (int argc, char* argv[])
{
 	int fd;
 	struct flock lock;
 	int pid;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Open error");
	}
 	
	pid = fork();
	if (pid == 0)
	{
	 	/* file open in write mode. */
	 	int fd = open(argv[1], O_WRONLY);
	 	if (fd == -1)
	 	{
	 		perror("file write");
	 	}
	 	
	 	/* Initialize the flock structure. */
	 	memset(&lock, 0, sizeof(lock));
	 	lock.l_type = F_WRLCK;
	 	
	 	/* Place a write lock on the file. */
	 	fcntl(fd, F_SETLKW, &lock);

	 	/* Wait for the user to hit Enter. */
	 	getchar ();

	 	
	 	/* Release the lock. */
	 	lock.l_type = F_UNLCK;
	 	fcntl (fd, F_SETLKW, &lock);

	 	close (fd);
	 }
	 else
	 {	
	 	/* file open in read mode. */
	 	int fd = open(argv[1], O_WRONLY);
	 	if (fd == -1)
	 	{
	 		perror("file write");
	 	}
	 	
	 	/* Initialize the flock structure. */
	 	memset (&lock, 0, sizeof(lock));
	 	lock.l_type = F_WRLCK;
	 	
	 	/* Place a write lock on the file. */
	 	fcntl(fd, F_SETLKW, &lock);
	 	
	 	/* Wait for the user to hit Enter. */
	 	getchar ();
	 	
	 	/* Release the lock. */
	 	lock.l_type = F_UNLCK;
	 	fcntl (fd, F_SETLKW, &lock);

	 	close (fd);
	 	
	 }
 	return 0;
}
