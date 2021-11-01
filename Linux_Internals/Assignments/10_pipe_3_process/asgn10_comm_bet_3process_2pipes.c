#include<stdio.h>
/*
Title  : WAP to create three child from the same parent 
Date : 4th Dec 2020
Author : Prajakta Kasab
*/


#include<unistd.h>

int main() 
{
	// declarations
   	int pipe_fd1[2], pipe_fd2[2];
   	int return_status1, return_status2;
   	int pid, i, j, k,num, comm;
   	char pipe1_writemessage[20];
   	char pipe2_writemessage[20];
   	char readmessage[20];
   	
   	printf("Enter the number of commands u want to create : \n");
   	scanf("%d", &comm);
   	
   	
   	for(k = 0; k < comm - 1; k++)
   	{
	   
   	// get input for pipe1 
   	printf("Enter no of elements u want to store in pipe1 \n");
   	scanf("%d", &num);
   	
   	printf("Enter the message for pipe1 \n");
   	
   	// store in array 
   	for (i = 0; i < num; i++)
   	{
   		scanf("%s", &pipe1_writemessage[i]);
   	}
   	
   	// get input from pipe2
    printf("Enter no of elements u want to store in pipe2\n");
   	scanf("%d", &num);
   	
   	printf("Enter the message for pipe2 \n");
   	// store in array
   	for (j = 0; j < num; j++)
   	{	
   		scanf("%s", &pipe2_writemessage[j]);
   	}
   }
   	// call pipe function for pipe1
   	return_status1 = pipe(pipe_fd1);
   	
   	// error checking
   	if (return_status1 == -1) 
   	{
      	printf("Unable to create pipe 1 \n");
      	return 1;
   	}
   	
   	// call pipe function for pipe2
   	return_status2 = pipe(pipe_fd2);
   	
   	// error checking
   	if (return_status2 == -1) 
	{
      	printf("Unable to create pipe 2 \n");
      	return 1;
   	}
   	
   	// Create a child process
   	
   	for(i = 0; i < comm; i++)
   	{
	   
   	pid = fork();
   
   	if (pid != 0) 				// Parent process 
   	{
      	close(pipe_fd1[0]); 			// Close the unwanted pipe1 read side
      	close(pipe_fd2[1]); 			// Close the unwanted pipe2 write side
      	printf("In Parent: Writing to pipe 1 –> Message is %s\n", pipe1_writemessage);
      	write(pipe_fd1[1], pipe1_writemessage, sizeof(pipe1_writemessage));
      	read(pipe_fd2[0], readmessage, sizeof(readmessage));
      	printf("In Parent: Reading from pipe 2 –> Message is %s\n", readmessage);
   	} 
	else 
	{ 																						//child process
	
      	close(pipe_fd1[1]); 			// Close the unwanted pipe1 write side
      	close(pipe_fd2[0]); 			// Close the unwanted pipe2 read side
      	read(pipe_fd1[0], readmessage, sizeof(readmessage));
      	printf("In Child: Reading from pipe 1 -> Message is %s\n", readmessage);
      	printf("In Child: Writing to pipe 2 –> Message is %s\n", pipe2_writemessage);
      	write(pipe_fd2[1], pipe2_writemessage, sizeof(pipe2_writemessage));
   	}
   }
   	return 0;
}
