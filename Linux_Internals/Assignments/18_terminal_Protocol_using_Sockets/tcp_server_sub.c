/*
Title   : server to do subtraction request from Client
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
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define SERVER_IP       "127.0.0.1"
#define SERVER_PORT 	5002
#define SERVER_LENGTH 	10
#define SERVER_BUFF	20

int main()
{

    int sock_fd, data_sock_fd,buffer_len;
    int result=0;
    int numbers[2];
    struct sockaddr_in serv_addr; 
    char serv_buffer[2];

    printf("Server for Subtraction op is waiting...\n");

    /* Create a TCP socket */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    /* Bind it to a particular IP address & port) */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serv_addr.sin_port = htons(SERVER_PORT); 

    bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    /* listen for incoming connections */
    listen(sock_fd, SERVER_LENGTH);

    /* If there are any, accept and create a new data socket */
    data_sock_fd = accept(sock_fd, (struct sockaddr*)NULL, NULL); 

    memset(numbers, 0, sizeof(numbers));
    
    /* Try to get some actual data from client */
    recv(data_sock_fd, (void *)&numbers,SERVER_BUFF,0);

    /* Print the data received from client */
    printf("Here is the client data: %d, %d\n",numbers[0], numbers[1]);
    
    /* send result back to client */
    result = numbers[0] - numbers[1];
    send(data_sock_fd, (void*)&result, sizeof(result), 0);
       

    /* Close the sockets now */
    close(data_sock_fd);
    close(sock_fd);
}






