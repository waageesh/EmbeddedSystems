/*
Title	: receiver/reader code for reading from shared memory
Author	: Vaageesh
Date	: Monday 11 January 2021 11:19:00 PM IST
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main(void) 
{
	char *shmptr, *temp;
	int shmid, i=0,len;
	key_t key = 'A';

	// create shared memory for storing string
	shmid = shmget(key, 6, 0600);
	if (shmid == -1)
	{
		printf("shared memory already exiss for key %c", key);

	}
	// attach shared memory
	shmptr = shmat(shmid, NULL, 0);// NULL for shmaddr, 0 for SHMFLG
	
	// allocated memory for temp string
	temp = malloc(strlen(shmptr)+1);
	
	// convert to UPPER and reverse string
	len = strlen(shmptr)-1;
	
	while(len>=0)
	{
		*(temp+i) = *(shmptr+len);
		printf("%c\n", *(temp+i));
		len--;
		i++;
	}
	*(temp+i) = '\0';
	

	// wrtie into shared memory
	strcpy(shmptr, temp);
	printf("reverse string in shm : %s\n", shmptr);

	// detaching shared memory from ptr
	shmdt(shmptr);

	//Remove shared memory
    	shmctl(shmid, IPC_RMID, 0);
	return 0;
}
