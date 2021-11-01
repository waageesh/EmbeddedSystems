/*
Title   : UPD server to receive commands from client
Author  : Vaageesh
Date    : Thursday 21 January 2021 07:34:49 PM IST
*/

#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP  	"127.0.0.1"
#define SERVER_PORT 	5001
#define SERVER_LENGTH 	10
#define SERVER_BUFF	50
#define FILE_BUFF_SIZE	65
int main()
{
	    int sock_fd,buffer_len,cli_len, ret, index, packet=1;
	    struct sockaddr_in serv_addr;				// structure to store server IP-address and port 
	    struct sockaddr_in    cli_addr;				// strcture to store Client IP-address and port
	    char serv_buffer[SERVER_BUFF];				// buffer to store linux command received from Client 
	    char file_buff[FILE_BUFF_SIZE];				// buffer to store packet to be sent to Client from file
	    int linux_cmd_run_freq, fd_read;				// variable to store lo of times remote cmd to be executed &
	    								//      file descriptor for opening file in read mode

	    printf("Emertxe: Server is waiting...\n");

	    /* Create a UDP socket */
	    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);

	    /* Bind it to a particular IP address & port) */
	    serv_addr.sin_family = AF_INET;
	    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	    serv_addr.sin_port = htons(SERVER_PORT); 
		
	    /* binding with above server info stored in structure */ 	
	    bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

	    /* Try to get some actual data from client */
	    cli_len = sizeof(struct sockaddr_in);
	    
	    /* validation for bytes received from client */
	    if (recvfrom(sock_fd,(void *)serv_buffer,SERVER_BUFF,0,(struct sockaddr *) &cli_addr, &cli_len) == -1)
	    {
	    	perror("packet from client");
	    	exit(1);
	    }
	    printf("string rec from client :	%s\n",serv_buffer);
	    index = strlen(serv_buffer)-1;
	    linux_cmd_run_freq = serv_buffer[index]-48;
	    serv_buffer[index] = '\0';
	    printf("string got from client %s, with freq %d\n", serv_buffer, linux_cmd_run_freq);
	    
	    
	    /* Print the data received from client */
	    printf("Sender Info:\n");
	    printf("Sender IP: %s\n", inet_ntoa(cli_addr.sin_addr));
	    printf("Sender Port: %d\n", ntohs(cli_addr.sin_port));
	    
	    /* opening file in write mode to store remote execution output */	
	    int fd = open("file.txt", O_CREAT|O_TRUNC|O_WRONLY, 0664);
	    
	    /* taking backup file descriptor for STDOUT */
	    int fd_stdin = dup(1);
	    
	    /* closing STDOUT and redirecting stdout to file.txt*/
	    dup2(fd, 1);
	    
	    /* executing the linux command for given no of times*/
	    for (int i=0; i<linux_cmd_run_freq; i++)
	    {
	    	system(serv_buffer);
	    }
	    
	    /* restoring STDOUT to print on STDOUT instead of file */
	    dup2(fd_stdin, 1);
	  
	    /* opening file in read mode */
	    fd_read = open("file.txt", O_RDONLY, 0664);
	    
	    /* reading 64bytes each time from file, since packet size is 64bytes */
	    do
	    {
	    	/* clearing out the buffer every time */
	    	memset(file_buff, 0, sizeof(file_buff));
	    	
	    	/* reading 64bytes from file each time into buffer */
	    	ret = read(fd_read, file_buff, 64);
	    	
	    	/* termianting strign by placing NULL in end */
	    	file_buff[65] = '\0';
	    	
	    	/* validation for no of bytes read */
	    	if (!ret)
	    	{
	    		sendto(sock_fd, NULL, 0, 0, 
	    				(struct sockaddr *)&cli_addr, sizeof(cli_addr));
	    		break;
	    	}
	    	
	    	/* storing packet no in the end of packet*/
	    	int n = strlen(file_buff);
	    	file_buff[n] = packet++;
	    	file_buff[n+1] = '\0';
	    	
	    	/* sending packet to Client */
	    	int server_ack = sendto(sock_fd, file_buff, strlen(file_buff) + 1, 0, 
	    				(struct sockaddr *)&cli_addr, sizeof(cli_addr));
	    	/* validation for bytes sent to Client sucessfully */
	    	if (server_ack)
	    	{
	    		printf("packet %d sent to client sucessfully, ", packet-1);
	    	}
	    	else
	    	{
	    		printf("packet %d sending failed, ", packet-1);
	    	}
	    	
	    	/*getting acknowledgemet from Client */
	    	char ack[2];
	    	recvfrom(sock_fd,(void *)ack, 2, 0,(struct sockaddr *) &cli_addr, &cli_len);
	    	printf("ack from client:%s\n", ack);
	    	
	    	/* if acknowledgement received is not "Y" then terminate the process */
	    	if (strcmp(ack, "Y") != 0)
	    	{
	    		printf("packets not send properly\n");
	    		exit(1);
	    	}
	    	/* to observe whether packets are going 64bytes each time, we are keeping delay for 1sec */	
	    	sleep(1);
	    	
	    } while(ret);
	    printf("reading froim client done, sock_fd %d is closing...\n", sock_fd);

	    /* Close the socket now */
	    close(sock_fd);
	    
	    return 0;
}
