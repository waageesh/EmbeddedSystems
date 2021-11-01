/*
Title   : UDP client to send Linux command to Client
Author  : Vaageesh
Date    : Thursday 21 January 2021 07:34:49 PM IST
*/

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

#define SERVER_IP_ADDRESS 	"127.0.0.1"
#define SERVER_PORT       	5001
#define CLIENT_BUFF_SIZE	20
#define SERVER_ACK_BUFF	100

int main()
{
	int sock_fd,c_size,n, serv_ack;
	char client_buff[CLIENT_BUFF_SIZE];
	char* linux_command;
	struct sockaddr_in serv_addr; 

	/* Create a client socket */
	if((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
	printf("Error: Could not create socket\n");
	return 1;
	} 

	/* Binding with client socket is optional here */

	/* Populate it with server's address details */
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERVER_PORT); 
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRESS);

	/* Get the message from client */
	printf("Enter the command you want to sent to server :");
	fgets(client_buff, 100, stdin);
	
	int index = strlen(client_buff);
	printf("Enter no of times to be executed :");
	scanf("%c", &client_buff[index-1]);
	
	/* making last char as NULL to terminate string */
	client_buff[index] = '\0';
	printf("linux command[%s]\n", client_buff);

	/* Send the message to server */
	c_size = sendto(sock_fd, client_buff, strlen(client_buff) + 1, 0,
	    (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	
	/* remote command sent validation  */
	if(c_size)
		printf("Linux command sent to server successsfully, please check\n");
	else
		printf("Error: Message sending failed\n");
	
	/* print 64 bytes per 1 packet received from UDP Server */
	do
	{
		char serv_ack_buff[SERVER_ACK_BUFF];
		int serv_ack_len = sizeof(struct sockaddr_in);
		
		/* receive packet(each 64bytes) from  UDP Server */
		serv_ack = recvfrom(sock_fd, (void *)serv_ack_buff, SERVER_ACK_BUFF, 0,
					(struct sockaddr *) &serv_addr, &serv_ack_len);
		/* if no of bytes received > 0 */
		if (serv_ack)
		{
			int n = strlen(serv_ack_buff)-1 ;
		    	int packet = serv_ack_buff[n];
		    	serv_ack_buff[n] = '\0';
		    	printf("%s", serv_ack_buff);
		    	char ack[2] = "Y";
		    	sendto(sock_fd, ack, strlen(ack) + 1, 0, 
	    				(struct sockaddr *)&serv_addr, sizeof(serv_addr));
		}
		else	// bytes received 0, terminate
		{
			printf("no data came from server, exiting...\n");
		}
		
	} while(serv_ack);
	printf("reading from server done, sockfd %d is closing...\n", sock_fd);
	close(sock_fd);
	return 0;
}












