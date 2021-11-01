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
#define SERVER_PORT       	5010
#define CLIENT_BUFF_SIZE	20
typedef struct num
{
	int numbers[2];
}numArray;

int main()
{
    numArray num_buffer;
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
    
	/* connect with corresponding server */
    /* Populate it with server's address details */
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

    int numbers[2];
    printf("enter the 2 numbers :");
    scanf("%d%d", &numbers[0], &numbers[1]);
    c_size = send(sock_fd, (void*)&numbers, sizeof(numbers), 0);
    if(c_size > 0)
    {
		printf("Message sent to server successsfully, please check\n");
    }
    else
    {
		perror("Message send");
		exit(1);
    }
    recv(sock_fd, (void*)&result, sizeof(result), 0);
    printf("result is :%d\n",result);
    
    close(sock_fd);
}











