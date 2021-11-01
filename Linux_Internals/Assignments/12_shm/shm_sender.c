/*
Title	: sender/writer code for writing into shared memory
Author	: Vaageesh
Date	: Monday 11 January 2021 11:19:00 PM IST
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main(void) 
{
	char* str, *shmaddr;
	int shmid, i = 0;
	key_t key = 'A';
	printf("Enter the string :");
	scanf("%ms", &str);

	// capitalizing the string
	int len = strlen(str);
	char* str_upper = malloc(strlen(str)+1);
	while(len>=0)
	{
		*(str_upper+i) = toupper(*(str+i));
		printf("%c\n", *(str_upper+i));
		len--;
		i++;
	}
	*(str_upper+i) = '\0';
	
	// create shared memory for storing string
	shmid = shmget(key, strlen(str)+1, IPC_CREAT|0664);
	
	if (shmid == -1)
	{
		shmid = shmget(key, strlen(str)+1, 0664);
	}
	
	// attach shared memory
	shmaddr = shmat(shmid, NULL, 0);// NULL for shmaddr, 0 for SHMFLG

	// wrtie into shared memory
	strcpy(shmaddr, str_upper);
	
	sleep(5);
	printf("Final output is %s\n", shmaddr);
	
	// detaching shared memory from ptr
	shmdt(shmaddr);
	
	//Remove shared memory
        shmctl(shmid, IPC_RMID, 0);

	return 0;
}
