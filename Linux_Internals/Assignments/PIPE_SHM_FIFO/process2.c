/*
Title	: communication between processes using different IPC mechanisms like IPC, SHM and PIPE
Author	: Vaageesh
Date	: Thursday 13 January 2021 08:04:37 PM IST
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define BUFF_SIZE 10
#define FIFO_FILE "STRING_REVERSE_FIFO"

/* ipcs -m
   linux cmd to checked created memory */
/* ipcrm -m <shmid>
   linux cmd to delete create shared memory with shared memory id	*/
   
int main(void) 
{
	int i=0;

	/*defining key for shared memory*/
	key_t key = 'C';
	
	/* create/fetch shared memory with above key */
	int shmid = shmget(key, BUFF_SIZE, 0664);
	if (shmid == -1)
		perror("shmid");
	/* get shared memory address */
	char* shmaddr = shmat(shmid, NULL, 0);
	
	/* fetch length of shared memory string which is stored as first char in shared memory*/
	int len = *(shmaddr+0)-48;
	
	/* dynamic memory allocation for fetched lenght from shm*/
	char* str_rev = malloc(len);
	
	/* capitalizing string read from pipe*/
	while(len>=1)
	{
		*(str_rev+i) = *(shmaddr+len);
		len--;
		i++;
	}
	*(str_rev+i) = '\0';
	
	/* detaching shm after copying to local ref*/
	shmdt(shmaddr);

	
	/* create FIFO_FILE if it doesn't exist*/
	mkfifo(FIFO_FILE, 0666);
	
	// open FIFO file in write mode
	int fifo_fd = open(FIFO_FILE, O_WRONLY|O_CREAT|O_TRUNC, 0664);
	if (fifo_fd == -1)
	{
		perror("fifo open");
	}
	
	/* writing capitalized string to FIFO */
	if (write(fifo_fd, str_rev, strlen(str_rev)+1) == -1)
		perror("fifo write");
	
	/* close the FIFO file */
	close(fifo_fd);
	return 0;
}
