/*
Title   : TCP Client that takes 2 numbers and send them to corresponding server forarithmatic operation
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
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

#define SERVER_IP_ADDRESS 	"127.0.0.1"
#define SERVER_PORT       	5000
#define CLIENT_BUFF_SIZE	20

int main()
{
    int numbers[2];
    int sock_fd, server_sock_fd, c_size;
    int server_port;
    int result;
    char client_buff[CLIENT_BUFF_SIZE];
    struct sockaddr_in serv_addr; 

    /* Create a client socket */
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
	printf("Error: Could not create socket\n");
	return 1;
    } 
    /* Binding with client socket is optional here */
    /* Populate it with Relay server's address details */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT); 
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRESS);
    
    if(connect(sock_fd, (struct sockaddr *)&serv_addr,sizeof(serv_addr)) != 0)
    {
	perror("connect");
	printf("Error connecting to server\n");
	close(sock_fd);
	exit(1);
    }
    else
	printf("Connection successful\n");
	
    /* Get the message from client */
    printf("+ \n- \n* \n\\ \n%% \n");
    printf("Enter the operator you want to perform from above 4 operators:\n");
    fgets(client_buff, CLIENT_BUFF_SIZE, stdin);
    
    /* removing trailing \n that will be read using fgets */
    client_buff[strlen(client_buff)-1] = '\0';

    /* Send the Arithmatic opertor to server */
    c_size = send(sock_fd, (void*)client_buff, strlen(client_buff) + 1, 0);

    if(c_size > 0)
	printf("Message sent to server successsfully, please check\n");
    else
	printf("Error: Message send\n");
    
    /* recv server port required for arithmatic operation */
    recv(sock_fd, (void*)&server_port, sizeof(server_port), 0);
    printf("server port received from Relay server:%d\n", server_port);
    
    
    /* Create a client socket */
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
	printf("Error: Could not create socket\n");
	return 1;
    } 
    
    /* connect with corresponding server */
    /* Populate it with server's address details */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(server_port); 
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRESS);
    
    //server_sock_fd
    if(connect(sock_fd, (struct sockaddr *)&serv_addr,sizeof(serv_addr)) != 0)
    {
	perror("connect");
	printf("Error connecting to server\n");
	close(sock_fd);
	exit(1);
    }
    else
	printf("Connection successful\n");

    /* Send the numbers to corresponding server */
    printf("enter the 2 numbers :");
    scanf("%d%d", &numbers[0], &numbers[1]);
    c_size = send(sock_fd, (void*)&numbers, sizeof(numbers), 0);

    if(c_size > 0)
	printf("Message sent to server successsfully, please check\n");
    else
    {
	printf("Error: Message send\n");
	exit(1);
    }
    recv(sock_fd, (void*)&result, sizeof(result), 0);
    printf("result is :%d\n",result);
    
    close(sock_fd);
}











